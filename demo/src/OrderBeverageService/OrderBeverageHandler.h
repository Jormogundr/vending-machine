#ifndef VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/OrderBeverageService.h"
#include "../../gen-cpp/WeatherService.h"
#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"
//#include "../BeveragePreferenceService/BeveragePreferenceHandler.h"


namespace vending_machine{

class OrderBeverageServiceHandler : public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceHandler(
		  ClientPool<ThriftClient<WeatherServiceClient>> *,
      ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *);
  ~OrderBeverageServiceHandler() override=default;

  void PlaceOrder(std::string& _return, const int64_t city) override;
 private:
  ClientPool<ThriftClient<WeatherServiceClient>> *_weather_client_pool;
  ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *_beverage_pref_client_pool;
};

// Constructor
OrderBeverageServiceHandler::OrderBeverageServiceHandler(
		ClientPool<ThriftClient<WeatherServiceClient>> *weather_client_pool,
    ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *beverage_pref_client_pool) {

     // Storing the clientpool
     _weather_client_pool = weather_client_pool;
     _beverage_pref_client_pool = beverage_pref_client_pool;
}

// Remote Procedure "PlaceOrder"
void OrderBeverageServiceHandler::PlaceOrder(std::string& _return, const int64_t city){
     // Your implementation goes here
     printf("PlaceOrder\n");

     //return BeverageType::type::COLD;
#if 1   
    // 1. get the weather service client pool
    auto weather_client_wrapper = _weather_client_pool->Pop();
    if (!weather_client_wrapper) {
      ServiceException se;
      se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
      se.message = "Failed to connect to weather-service";
      throw se;
    }
    auto weather_client = weather_client_wrapper->GetClient();

    // by default get cold
    WeatherType::type weatherType = WeatherType::type::COLD;

    // 2. call the remote procedure : GetWeather
    try {
      weatherType = weather_client->GetWeather(city);
    } catch (...) {
      _weather_client_pool->Push(weather_client_wrapper);
      LOG(error) << "Failed to send call GetWeather to weather-client";
      throw;
    }
    _weather_client_pool->Push(weather_client_wrapper);

    // 3. business logic
    BeverageType::type beverageType;
    if(weatherType == WeatherType::type::WARM)
      beverageType = BeverageType::type::COLD;
    else
      beverageType = BeverageType::type::HOT;

    // 3. get the beverage preference service client pool
    auto beverage_pref_client_wrapper = _beverage_pref_client_pool->Pop();
    if (!beverage_pref_client_wrapper) {
      ServiceException se;
      se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
      se.message = "Failed to connect to beverage-preference-service";
      throw se;
    }
    auto beverage_client = beverage_pref_client_wrapper->GetClient();

    // by default get Latte
    std::string beverage = "latte";

    // 4. call the remote procedure : getBeverage
    try {
      beverage = beverage_client->getBeverage(beverageType);
    } catch (...) {
      _beverage_pref_client_pool->Push(beverage_pref_client_wrapper);
      LOG(error) << "Failed to send call getBeverage to beverage-preference-client";
      throw;
    }
    _beverage_pref_client_pool->Push(beverage_pref_client_wrapper);
    
  // 5. Set return value
    _return = beverage;

#endif
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H


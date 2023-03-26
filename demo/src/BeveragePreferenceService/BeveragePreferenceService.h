#ifndef VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>
#include <vector>
#include "../../gen-cpp/WeatherService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{


class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  std::string getBeverage(BeverageType::type btype) override;
  vector<std::string> cold_drinks = {"cappuccino", "latte", "espresso"};
  vector<std::string> hot_drinks = {"lemonade", "ice tea", "soda"}; 
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

string BeveragePreferenceServiceHandler::getBeverage(BeverageType::type btype) {
    // initialize random seed
    srand (time(NULL));
    if (btype == "HOT") {
        // randomly select hot beverage
        return hot_drinks[rand() % 2];
    }
    else {
        // randomly select a cold beverage
        return cold_drinks[3 + rand() % 5];
    }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H


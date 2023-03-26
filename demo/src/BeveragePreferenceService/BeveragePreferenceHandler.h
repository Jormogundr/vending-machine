#ifndef VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>
#include <vector>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  std::string getBeverage(const BeverageType::type btype);
  std::vector<std::string> cold_drinks = {"cappuccino", "latte", "espresso"};
  std::vector<std::string> hot_drinks = {"lemonade", "ice tea", "soda"}; 
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}


std::string BeveragePreferenceServiceHandler::getBeverage(const BeverageType::type btype) {
    printf("get Beverage\n");
    // initialize random seed
    srand (time(NULL));
    std::string choice = "latte";
    // randomly select hot beverage else randomly select a cold beverage
    if (btype == 0) {
        choice = hot_drinks[rand() % 2];
    }
    else {
        choice = cold_drinks[3 + rand() % 5];
    }
    return choice;
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H


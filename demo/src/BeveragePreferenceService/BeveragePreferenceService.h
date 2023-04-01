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
    
    void getBeverage(std::string& _return, BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() { }

// getBeverage
void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, BeverageType::type btype) {
    printf("get Beverage\n");

    // initialize random seed
    srand(time(NULL));

    // define drink choices
    std::vector<std::string> hotDrinks = {"cappuccino", "latte", "espresso"};
    std::vector<std::string> coldDrinks = {"lemonade", "ice tea", "soda"}; 

    if (btype == BeverageType::type::HOT) {
        _return = coldDrinks[rand() % 3];
    }
    else {
        _return = hotDrinks[rand() % 3];
    }
}


} // namespace vending_machine

#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
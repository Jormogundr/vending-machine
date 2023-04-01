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
    
    void getBeverage(std::string& _return, const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() { }

// getBeverage
void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type btype) {
    printf("get Beverage\n");

    // initialize random seed
    srand(time(NULL));

    // define drink choices
    std::vector<std::string> hotDrinks = {"cappuccino", "latte", "espresso"};
    std::vector<std::string> coldDrinks = {"lemondate", "ice tea", "soda"}; 

    if (btype == 0) {
        _return = hotDrinks[rand() % 2];
    }
    else {
        _return = coldDrinks[3 + rand() % 5];
    }
}


} // namespace vending_machine

#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
#pragma once
#ifndef CUSTOMERFACTORY_HPP
#define CUSTOMERFACTORY_HPP

#include "Libraries.hpp"
#include "Level.hpp"
#include "Food.hpp"
#include "Customer.hpp"
#include "FoodFactory.hpp"

class Customer;

class CustomerStrategy {

};

class CustomerFactory {
private: 
    static CustomerFactory* cf;
    FoodFactory* ff;
    CustomerStrategy* cs;
public:
    CustomerFactory() : cs(NULL), ff(NULL) {
        init();
        ff -> init();
    }
    void init();
    static CustomerFactory* getCustomerFactory() {
        return cf;
    }
    Customer* get(Level* l, Customer* c); // level single ton or static?
};

#endif
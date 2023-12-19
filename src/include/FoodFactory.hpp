#pragma once
#ifndef FOODFACTORY_HPP
#define FOODFACTORY_HPP

#include "Libraries.hpp"
#include "Level.hpp"
#include "Food.hpp"

class Customer;

class FoodFactory {
private:
    int numFood;
    std::vector<std::string> sample;
public:
    FoodFactory() : numFood(0), sample{} {}
    void init();
    SampleFood* get(Level* l, Customer* c);
};

#endif
#pragma once
#ifndef FOODITERATOR_HPP
#define FOODITERATOR_HPP

#include "Libraries.hpp"

class FoodIterator {
public:
    void init();
    std::string get();
    void next();
    void back();
    void display();
    FoodIterator() : list({}), iter(list.begin()) {
        // copy constructor for food, or assignment operator
    }
private:
    std::vector <std::string> list;
    std::vector <std::string>::iterator iter;
};

#endif
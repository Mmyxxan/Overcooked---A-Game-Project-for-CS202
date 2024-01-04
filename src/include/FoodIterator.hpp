#pragma once
#ifndef FOODITERATOR_HPP
#define FOODITERATOR_HPP

#include "Libraries.hpp"
#include "ModelFactory.hpp"
#include "CameraGame.hpp"

class FoodIterator {
public:
    void init();
    std::string get();
    void next();
    void back();
    void display();
    void setFoodTexture(std::string food);
    FoodIterator() : list({}), iter(list.begin()), frame(NULL), food(NULL) {
        // copy constructor for food, or assignment operator
    }
private:
    std::vector <std::string> list;
    std::vector <std::string>::iterator iter;
    Texture* frame;
    Texture* food;
};

#endif
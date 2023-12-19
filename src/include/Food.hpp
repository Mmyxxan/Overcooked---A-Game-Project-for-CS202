#pragma once
#ifndef FOOD_HPP
#define FOOD_HPP
#include "Libraries.hpp"
#include "Object.hpp"
// #include "State.hpp"

// space for every type of customer, or customer send space, but space is defined on the attach and attachment?
// how to encapsulate this?

class FoodState;
class MotionlessState;

class Food : public Object {
private:
    std::string description;
    std::set<std::string> food_set;
    // unordered set description and add all descriptions from decorators to it
    FoodState* state;
    Food* f;
    Object* o;
public:
    void display();
    std::string getFile();
    Food(std::string description) : Object("food"), description(description), f(NULL), o(NULL), state(NULL), food_set({}) {
        // state = new MotionlessState(description);
        food_set = {description};
        init();
    }
    Food(Object* o, std::string description): Object("food"), f(NULL), o(o), description(description), state(NULL), food_set({}) {
        // std::cerr << getDescription() << '\n';
        food_set = {description};
        init();
        // else copy constructor;
    }
    virtual void init();
    Food(Food* f) : Object("food"), f(f), state(NULL) {
        std::cerr << description << '\n';
        // state = new MotionlessState(getDescription());
        init();
    }
    void setDescription();
    std::string getDescription();
    std::set<std::string> getSet();
};

class CookerWrapper : public Food {
public:
    CookerWrapper() : Food("cookerwrapper") {
        std::cout << "cooker wrapper" << '\n';
    }
    CookerWrapper(Object* o) : Food(o, "cookerwrapper") {} 
    CookerWrapper(Food* f) : Food(f) {} 
};

class StorerMaterial : public Food {
public:
    StorerMaterial() : Food("storermaterial") {

    }
    StorerMaterial(Object* o) : Food(o, "storermaterial") {} 
    StorerMaterial(Food* f) : Food(f) {} 
};

class SampleFood : public Food {
public:
    SampleFood(std::string description) : Food(description) {}
    bool assess(Object* o);
    bool assess(Food* f);
};

// create new food class and adapter pattern instead of adding set description to each element
// or ensure player to make things in order
// baked and add more ingredients is wrong
// add baked in every leaf of the composite
// food complex composite 
// encapsulate steps in recipes that can be random order, and which is not????
// format description from every step, or using a tree and put it in a whole unordered needed subtree

#endif


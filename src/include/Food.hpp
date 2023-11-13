#pragma once
#include "Libraries.hpp"
#include "Object.hpp"

class DisplayFactory {
private: static DisplayFactory* df;
         DisplayFactory() {}
public: static DisplayFactory* getDF() {
    if (!df) df = new DisplayFactory();
    return df;
}
        std::string getFile(std::string description);
};

class FoodState {
protected:
    DisplayFactory* df;
    std::string description;
public:
    FoodState(std::string description): description(description) {
        df = DisplayFactory::getDF();
    }
    // virtual void action() = 0;
    virtual std::string getFile() = 0;
};

class MotionlessState : public FoodState {
public:
    MotionlessState(std::string description) : FoodState(description) {

    }
    std::string getFile();
    void action();
};

class Food : public Object {
private:
    std::string description;
    FoodState* state;
    Food* f;
public:
    // void display();
    std::string getFile();
    Food(std::string description) : Object("food"), description(description), f(NULL) {
        state = new MotionlessState(description);
    }
    Food(Object* o): Object("food") {
        if (o -> description == "food") {
            state = new MotionlessState(getDescription());
        }
        // else copy constructor;
    }
    Food(Food* f) : Object("food"), f(f) {
        state = new MotionlessState(getDescription());
    }
    void setDescription();
    std::string getDescription();
};

class CookerWrapper : public Food {
public:
    CookerWrapper() : Food("cookerwrapper") {}
    CookerWrapper(Object* o) : Food(o) {} 
    CookerWrapper(Food* f) : Food(f) {} 
};


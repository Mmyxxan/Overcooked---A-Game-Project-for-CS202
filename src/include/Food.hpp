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
    virtual void action() = 0;
    virtual std::string getFile() = 0;
};

class MotionlessState : public FoodState {
public:
    MotionlessState(std::string description) : FoodState(description) {
        std::cerr << description << '\n';
    }
    std::string getFile();
    void action();
};

class Food : public Object {
private:
    std::string description;
    FoodState* state;
    Food* f;
    Object* o;
public:
    void display();
    std::string getFile();
    Food(std::string description) : Object("food"), description(description), f(NULL), o(NULL) {
        state = new MotionlessState(description);
    }
    Food(Object* o, std::string description): Object("food"), f(NULL), o(o), description(description) {
        std::cerr << getDescription() << '\n';
        if (o -> description == "food") {
            state = new MotionlessState(getDescription());
        }
        else state = new MotionlessState("cannotwrap");
        // else copy constructor;
    }
    Food(Food* f) : Object("food"), f(f) {
        std::cerr << description << '\n';
        state = new MotionlessState(getDescription());
    }
    void setDescription();
    std::string getDescription();
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


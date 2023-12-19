#pragma once
#include "Libraries.hpp"
#include "Object.hpp"
#include "Timer.hpp"
#include "Area.hpp"
#include "Food.hpp"
#include "Mediator.hpp"
#include "State.hpp"
#include "ModelFactory.hpp"

class KitchenState;
class Cooker : public Object
{
private:
    Food* food;
    KitchenState* ks;
    std::string food_description;
    Mediator* m;
    Timer* timer;
    std::vector<std::string> wrappee;
    int state;
    Model time;
    // State* state;
public:
    Cooker() : Object("cooker"), timer(NULL), state(0), food(NULL), ks(NULL), wrappee({}) {
        area = new Area(200, 200, false);
        time = *(ModelFactory::getModelFactory() -> getModel("timer.glb"));
    }
    Cooker(std::string food_description) : Object("cooker"), timer(NULL), state(0), food(NULL), food_description(food_description), ks(NULL), wrappee({}) {
        area = new Area(200, 200, false);
        time = *(ModelFactory::getModelFactory() -> getModel("timer.glb"));
    }
    void pause();
    int getState();
    // void setState();
    void setMediator(Mediator* m);
    void display();
    void displayTimer();
    void wrap();
    bool wrappable(Object* o);
    void attach(Object* o);
    void update(float x, float y);
    bool isInArea(float x, float y);
    void Process(); // set pos set state set image
};
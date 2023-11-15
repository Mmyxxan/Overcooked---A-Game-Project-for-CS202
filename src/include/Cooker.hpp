#pragma once
#include "Libraries.hpp"
#include "Object.hpp"
#include "Timer.hpp"
#include "Area.hpp"
#include "Food.hpp"
#include "Mediator.hpp"

class Cooker : public Object
{
private:
    Mediator* m;
    Timer* timer;
    int state;
    // State* state;
public:
    Cooker() : Object("cooker"), timer(NULL), state(0) {
        area = new Area(200, 200, false);
    }
    int getState();
    // void setState();
    void setMediator(Mediator* m);
    void display();
    void attach(Object* o);
    void update(float x, float y);
    bool isInArea(float x, float y);
    void Process(); // set pos set state set image
};
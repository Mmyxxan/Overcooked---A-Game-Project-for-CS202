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
    Area* area;
    Timer* timer;
    int state;
    // State* state;
public:
    Cooker() {
        area = new Area(30, 30, false);
        timer = nullptr;
    }
    void display();
    void attach(Object* o);
    void update(float x, float y);
    bool isInArea(float x, float y);
    void Process(); // set pos set state set image
};
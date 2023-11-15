#pragma once
#include "Libraries.hpp"
#include "Mediator.hpp"
#include "Food.hpp"

class Storer : public Object {
private:
    Mediator* m;
    int state;
public:
    Storer() : Object("storer"), state(0), m(NULL) {
        area = new Area(200, 200, false);
    }
    void setMediator(Mediator* m);
    void display();
    void update(float x, float y);
    bool isInArea(float x, float y);
    virtual void Process();
};


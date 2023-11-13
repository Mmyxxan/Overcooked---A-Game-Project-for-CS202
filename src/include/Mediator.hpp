#pragma once
#include "Libraries.hpp"
#include "ControllableObject.hpp"
#include "Object.hpp"

class Mediator {
private:
    ControllableObject* chef;
    std::vector <Object*> obj;
    Object* att;
public:
    Mediator(ControllableObject* chef): chef(chef), obj({}) {} // get the information of both chef and obj, the two sides receive information from this mediator and process their own by changing inside state of each one.
    void registerObject(Object* o);
    void notifyObjects();
    void assignBack(Object* o);
    Object* getAttachment();
    float getChefX();
    float getChefY();
};

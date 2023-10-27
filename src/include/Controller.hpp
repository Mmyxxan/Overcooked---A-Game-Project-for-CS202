#pragma once
#include "Libraries.hpp"
#include "Object.hpp"
#include "ControllableObject.hpp"

class Controller {
private:
    std::vector <Object*> obj;
    char key;
public:
    Controller(): obj({}), key('\n') {};
    void registerObject(Object* o);
    bool isKeyPressed(char x);
    void notifyObservers();
    void control();
};
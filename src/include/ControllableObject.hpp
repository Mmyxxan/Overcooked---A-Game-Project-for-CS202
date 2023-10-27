#pragma once
#include <Libraries.hpp>
#include "Object.hpp"

class ControllableObject: public Object
{
private:
    int state;
    std::string description;
    char left;
    char right;
    char up;
    char down;
    const float speed = 0.2f;
public:
    ControllableObject(std::string file, Vector3 position, Vector3 axis, float direction, Vector3 scale): left('A'), right('D'), up('W'), down('S'), description("controllable"), state(0) {
        setFile(file); 
        setPos(position); setAxis(axis);
        setDirection(direction);
        setScale(scale);
    }
    ControllableObject(char left, char right, char up, char down): left(left), right(right), up(up), down(down), description("controllable") {}
    void setKeyLeft(char x);
    void setKeyRight(char x);
    void setKeyUp(char x);
    void setKeyDown(char x);
    char keyLeft();
    char keyRight();
    char keyUp();
    char keyDown();
    void setLeft();
    void setRight();
    void setUp();
    void setDown();
    void setMoveLeft();
    void setMoveRight();
    void setMoveUp();
    void setMoveDown();
    void update(const char event);
    std::string getDescription();
    // display: setMove()... Move() function call
};
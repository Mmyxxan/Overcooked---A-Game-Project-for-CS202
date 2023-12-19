#pragma once
#ifndef CONTROLLABLEOBJECT_HPP
#define CONTROLLABLEOBJECT_HPP
#include "Libraries.hpp"
#include "Object.hpp"
#include "CameraGame.hpp"
#include "Area.hpp"

class ControllableObject: public Object
{
private:
    // std::string description;
    char left;
    char right;
    char up;
    char down;
    const float speed = 0.2f;
    char orientation;
public:
    // state pattern and pause in state
    ControllableObject(std::string file, Vector3 position, Vector3 axis, float direction, Vector3 scale): left('A'), right('D'), up('W'), down('S'), orientation('D') {
        area = new Area(200, 200, true);
        setFile(file); 
        setPos(position); setAxis(axis);
        setDirection(direction);
        setScale(scale);
        // description = "controllable";
    }
    ControllableObject(char left, char right, char up, char down): left(left), right(right), up(up), down(down) {
        // description = "controllable";
    }
    void display();
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
    void attach(Object* o);
    // std::string getDescription();
    // display: setMove()... Move() function call
};
#endif
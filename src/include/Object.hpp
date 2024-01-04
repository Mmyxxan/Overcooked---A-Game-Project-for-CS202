#pragma once
#include <Libraries.hpp>
#include "Area.hpp"
#include "CameraGame.hpp"
#include "Map.hpp"
#include "ModelFactory.hpp"
// #include "PauseGame.hpp"
// #include "Checker.hpp"
#ifndef OBJECT_HPP
#define OBJECT_HPP

class Mediator;

class Object {
public:
    Model* model;
    std::string file;
// private: 
    Vector3 activePos;
    Vector3 space;
    bool activated;
    Vector3 position;
    Vector3 axis;
    Vector3 scale;
    float direction;
    Camera3D cam;
    Object* att;
public:
    Area* area;
    Map* map;
    // ModelFactory* mf;
public: 
    // void registerPause(PauseGame* pause);
    virtual void displayAttachment();
    virtual void displayTimer();
    virtual void drawArea();
    virtual void pause();
    virtual std::set<std::string> getSet();
    void registerArea(Map* map);
    std::string description;
    Object() : att(NULL), file(""), space({0.0f, 0.0f, 0.0f}), position({0.0f, 0.0f, 0.0f}), axis({0.0f, 0.0f, 0.0f}), scale({0.0f, 0.0f, 0.0f}), direction(0.0f), area(NULL) {
        description = "object"; 
        // mf = new ModelFactory();
    }
    Object(std::string description) : att(NULL), description(description), file(""), position({1.0f, 1.0f, 1.0f}), axis({1.0f, 1.0f, 1.0f}), scale({1.0f, 1.0f, 1.0f}), direction(90.0f) {
        // mf = new ModelFactory();
    }
    Object(std::string file, Vector3 position, Vector3 axis, float direction, Vector3 scale): file(file), position(position), axis(axis), direction(direction), scale(scale), space(position), att(NULL) {
        area = new Area(200, 200, false);
        // mf = new ModelFactory();
    }
    virtual void setMediator(Mediator* m);
    Vector3 getPos();
    Vector3 getAxis();
    float getDirection();
    Model& getModel();
    Vector3 getScale();
    void set();
    void unset();
    void setPos(Vector3 pos);
    void setAxis(Vector3 axis);
    void setDirection(float dir);
    void setModel();
    void setScale(Vector3 scale);
    virtual void setFile(const std::string path);
    // virtual void display();
    // virtual void setFile (const std::string path);
    virtual void display();
    void setCamera();
    Camera3D getCamera();
    virtual void update(const char event);
    virtual void update(float x, float y);
    virtual std::string getDescription();
    virtual std::string getFile();
    BoundingBox getBoundingBox();
    void setSpace(Vector3 space);
    Vector3 getSpace();
    virtual void attach(Object* o);
    Object* getAttachment();
    // virtual 
    void deattach();
    void rotate(char rotation, float angle);
    void removeArea(Vector2 root, float height, float width);
    virtual void Process();
    virtual int getID();
    virtual std::string selfAssess();
    virtual int getState();
    // void animate();
};
#endif

// class ObjectController {};



// class KeyboardController {
//     Object obj;
//     cooker.invoke(material)
// };
// class Animation {};
// add an object controller, it will use position to track if to invoke which one, and let the object invocation do their things by Observer Pattern
// will I use a decorator pattern to attach a dish to a controllable object, and track down recursively to check all objects attached until you see a controllable, which interacts another way.
// 2 relationships: attachment material - controllable, material - cooker
// what about an object attach to another object - answered
// material - material display on manual choice
// attachable.attach(object) must have their space defined (where to attach), values to change the location of the attached.

// class Cooker : public Object {};
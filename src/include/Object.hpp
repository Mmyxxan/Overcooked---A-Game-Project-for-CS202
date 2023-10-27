#pragma once
#include <Libraries.hpp>
#include "CameraGame.hpp"

class Object {
private: 
    std::string description;
    Vector3 activePos;
    Vector3 space;
    bool activated;
    Vector3 position;
    Vector3 axis;
    Vector3 scale;
    float direction;
    std::string file;
    Model model;
    Camera3D cam;
    Object* att;
public: 
    Object() {}
    Object(std::string file, Vector3 position, Vector3 axis, float direction, Vector3 scale): file(file), position(position), axis(axis), direction(direction), scale(scale), description("object"), space(position), att(NULL) {}
    Vector3 getPos();
    Vector3 getAxis();
    float getDirection();
    Model getModel();
    Vector3 getScale();
    void set();
    void unset();
    void setPos(Vector3 pos);
    void setAxis(Vector3 axis);
    void setDirection(float dir);
    void setModel();
    void setScale(Vector3 scale);
    void setFile(const std::string path);
    // virtual void display();
    // virtual void setFile (const std::string path);
    void display();
    void setCamera();
    Camera3D getCamera();
    virtual void update(const char event);
    std::string getDescription();
    BoundingBox getBoundingBox();
    void setSpace(Vector3 space);
    Vector3 getSpace();
    virtual void attach(Object* o);
    Object* getAttachment();
    virtual void deattach();
    // void animate();
};

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
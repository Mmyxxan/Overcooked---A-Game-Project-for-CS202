#pragma once
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Object.hpp"

class Particle : public Object {
private:
    Particle* next;
    
public:
    bool valid;
    Particle() : Object("particle"), next(NULL), valid(false) {
        // float a, b, c;
        // std::cin >> a >> b >> c;
        // setPos({a, b, c});
        setPos({5.0f, 2.0f, 1.0f});
        // load from file
    }
    Particle(Vector3 position) : Object("particle"), next(NULL), valid(false) {
        this -> position = position;
    }
    void attach(Object* o);
    void setNext(Particle* next);
    Particle* getNext();
    void setValid();
    void setInvalid();
    bool isValid();
};

#endif
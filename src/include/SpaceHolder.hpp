#pragma once
#ifndef SPACEHOLDER_HPP
#define SPACEHOLDER_HPP

#include "Particle.hpp"

class SpaceHolder {
private:
    int num;
    Particle* p;
    Particle* head; // invalid ones
public:
    SpaceHolder(int num, Vector3 position) : num(num), p(NULL), head(NULL) {
        p = new Particle[num];
        for (int i = 0; i < num; i++) p[i] = Particle(Vector3Add(position, {0.0f, 5.0f, 2.0f}));
    }
    void init();
    Particle* manage();
    Particle* get();
    
    // add object 1 cus - many dishes
};

#endif
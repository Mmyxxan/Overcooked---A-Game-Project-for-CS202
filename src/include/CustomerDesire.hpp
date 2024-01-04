#pragma once
#ifndef CUSTOMERDESIRE_HPP
#define CUSTOMERDESIRE_HPP

#include "Libraries.hpp"
#include "SharedResources.hpp"
#include "Food.hpp"
#include "ModelFactory.hpp"
#include "Button.hpp"
#include "Timer.hpp"
#include "DrawNumber.hpp"
#include "CameraGame.hpp"

class CustomerDesire {
protected:
    const Font font = SharedResources::getResources() -> getCustomerFont();
    SampleFood* food;
public:
    CustomerDesire() : food(NULL) {}
    virtual void setUp() = 0;
    virtual void display() = 0;
};

class CustomerOrder : public CustomerDesire {
private:
    Model* food3d;
    Vector3 pos;

public:
    CustomerOrder(SampleFood* food, Vector3 pos) : food3d(NULL), pos(pos) {
        this -> food = food;
        setUp();
    }
    void setUp();
    void display();
};

class CustomerWaiting : public CustomerDesire {
private:
    Texture* frame;
    Texture* content;
    Timer* timer;
    DrawNumber** draw;
public:
    CustomerWaiting(SampleFood* food, Timer* timer) : frame(NULL), timer(timer), content(NULL), draw(NULL) {
        this -> food = food;
        draw = new DrawNumber*[2];
        for (int i = 0; i < 2; i++) draw[i] = nullptr;
        setUp();
    }
    void setUp();
    void display();
};

class CustomerEating : public CustomerDesire {
private:
    Texture* frame;
    Texture* content;
    Timer* timer;
    DrawNumber** draw;
public:
    CustomerEating(SampleFood* food, Timer* timer) : frame(NULL), timer(timer), content(NULL) {
        this -> food = food;
        draw = new DrawNumber*[2];
        for (int i = 0; i < 2; i++) draw[i] = nullptr;
        setUp();
    }
    void setUp();
    void display();
};

#endif
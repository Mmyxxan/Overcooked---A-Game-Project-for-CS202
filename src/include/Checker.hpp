#pragma once
#ifndef CHECKER_HPP
#define CHECKER_HPP
#include "Libraries.hpp"
#include "Timer.hpp"
#include "Button.hpp"
// #include "Factory.hpp"

// class Area;

// gamemanager check if checker is time left;
// create sample food for customer
// pause game, pause timer on observer pattern, timer mediator,... pause controller, mediator, change screen



class Instruction {
// public: virtual std::string getInstruction(Object* o);
};

class FoodInstruction : public Instruction {

};

// remaining: pool object, holder, factory, state of customer, level, random stuff, game manager stuff, food factory and manager, give points and create sample food

//customer holder but food factory, state Pattern is important
// resolve by interface of checker forward, and concrete checker afterwards
//Factory

// share the same interface as (CustomerFactory or) customer Holder
// class CustomerQueue {
//     // here
// private:
//     CustomerFactory* cf;
// public:
//     CustomerQueue() : cf(NULL) {}
//     // set initialized position for customer and takeaway customer, but change takaway customer position when a customer is popped

// };

// class Customer;
// template <int i> 
// class SpaceHolder;

// class Particle {
// private:
//     Vector3 pos;
//     Particle* next;
//     bool valid;
// public:
//     Particle() : pos({0.0f, 0.0f, 0.0f}), next(NULL), valid(false) {}
//     void setNext(Particle* next);
//     Particle* getNext();
//     void setValid();
//     void setInvalid();
// };

// the holders are not all the same
// template <int i> 

// class Table {

// };
// checker and display factory singleton

class Checker {
    // user benefits
private:
    // a map from string to sample food, if there is a mapping, assessed true. or assess from queue.top()
    int time;
    Button* system;
    Timer* timer;
public:
    int score;
    // new thread to observe all objects and assess player
    Checker() : score(0), timer(NULL), time(0), system(NULL) {
        // random sample food from file
        // timer = new Timer(0, Level::getTime());
        // timer -> start();
        // get button
        system = new CheckerButton();
    }
    Checker(int time) : score(0), timer(NULL), time(time), system(NULL) {
        // random sample food from file
        // timer = new Timer(0, Level::getTime());
        // timer -> start();
        // create button and get texture for it
        system = new CheckerButton();
    }
    void pause();
    void reset();
    void start();
    void display();
    void manage(); 
    // throughout gameplay to check if time left,...
    void update(const std::string description); 
    bool isTimeleft();
};


// display, recipe, point factory
// Food Factory, Customer Factory

// template class
// new mediator for checker

// static get food from food factory

// template<int i>

// object on controllable: observer pattern mediator to send message about register on chef, and deregister
// mediator of controllable and the object -> composition, has A. attachment container and skeleton pattern

// buffer of any type?

// sender = this, receiver = ? sender in this function. first message by mediator.
// deregister from both objects to each other
// brief message so that can be reused, 1 message - 1 single action like drop attachment, take buffer, admit buffer.


#endif
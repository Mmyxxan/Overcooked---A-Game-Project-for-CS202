#pragma once
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "Object.hpp"
#include "State.hpp"
#include "Mediator.hpp"
#include "Food.hpp"
#include "Particle.hpp"
#include <CustomerFactory.hpp>
#include <Level.hpp>
#include <MediatorChecker.hpp>

class CustomerState;

class Customer : public Object {
private:
public:
    // State* state; // state has eating timer, personality time, old young and appearance 
    CustomerState* status;
    int ID;
    std::string assess;
    MediatorChecker* mc;
    SampleFood* f;
    int state;
    Timer* lifetimer;
    Timer* timer;
    Customer* next;
    // Table* t;
public:
    bool inUse;
    Particle* space;
    Customer(int ID) : Object("customer"), mc(NULL), ID(ID), f(NULL), state(0), timer(NULL), status(NULL), space(NULL), next(NULL), inUse(false), assess("wrong") {
        mc = new MediatorChecker();
        area = new Area(200, 200, false);
        f = new SampleFood("dough");
        lifetimer = new Timer(0, 5);
        // lifetimer -> start();
        // status = new CustomerState(Customers::outdated, this);
        // setFile("little_chef_overcooked_like.glb");
        // setModel();
    }
    void displayDesire();
    SampleFood* getSampleFood();
    void attach(Object* o);
    std::string getFile();
    void setSampleFood(SampleFood* f) {
        this -> f = f;
    }
    void pause();
    void setNext(Customer* next);
    Customer* getNext();
    void systemAssess();
    void assignSpace(Particle* space);
    void detachfromSpace();
    void changeState(CustomerState* status);
    void setMediatorChecker(MediatorChecker* mc);
    int getID();
    std::string selfAssess();
    void Process();
    void update(float x, float y);
    bool isInArea(float x, float y);
    int getState();
    void bringIntoState();
};

#endif
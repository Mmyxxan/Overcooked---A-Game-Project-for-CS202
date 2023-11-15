#pragma once
#include "Libraries.hpp"
#include "Mediator.hpp"
#include "Timer.hpp"
#include "Food.hpp"
#include "Object.hpp"

// remaining: pool object, holder, factory, state of customer, level, random stuff, game manager stuff, food factory and manager, give points and create sample food

//customer holder but food factory, state Pattern is important

class Table : public Object {
    Table() : Object("table") {}
    // init table space, set space, lot of space;
};

class StorageHolder {

};

class KitchenHolder {

};

class TableHolder {
    // pos of table 1, table 2, ...
};

class Level {
    Level() {}
};

// class Table {

// };

// checker and display factory singleton
class Checker {
    // user benefits
private:
    // a map from string to sample food, if there is a mapping, assessed true. or assess from queue.top()
    int score;
    Timer* timer;
public:
    // new thread to observe all objects and assess player
    Checker() : score(0), timer(NULL) {
        // random sample food from file
    }
    void update(const std::string description); 
    bool isTimeleft();
};

// display, recipe, point factory
// Food Factory, Customer Factory

// template class
// new mediator for checker
class MediatorChecker {
private:
    Object* att;
    ControllableObject* chef;
    Checker* checker;
    std::vector <Object*> obj;
public:
    MediatorChecker(): obj({}), chef(NULL), checker(NULL), att(NULL) {}
    void registerObject(Object* o);
    void deregisterObject(int id);
    void notifyObjects();
    void notifyChecker(std::string description);
    float getChefX();
    float getChefY();
    Object* getAttachment();
    void drop();
    Object* getAttachmentfrom();
};

// static get food from food factory
class Customer : public Object {
private:
    // State* state; // state has eating timer, personality time, old young and appearance 
    int ID;
    MediatorChecker* mc;
    SampleFood* f;
    int state;
public:
    Customer(int ID) : Object("customer"), mc(NULL), ID(ID), f(NULL), state(0) {
        mc = new MediatorChecker();
    }
    void setMediatorChecker(MediatorChecker* mc);
    int getID();
    std::string selfAssess();
    void Process();
    void update(float x, float y);
    bool isInArea(float x, float y);
    int getState();
};

class CustomerHolder {
private:
    int curID;
public:
    CustomerHolder() : curID(0) {

    }
    // set some customer into invalid state of pool object;
};

class GameManager {
    // int level; // namespace level
    // all initialized and draw here;
private:
    TableHolder* tables;
    StorageHolder* storage;
    KitchenHolder* kitchen;
    CustomerHolder* customer;
    Level* l;
    Checker* c;
public:
    GameManager() : l(NULL), c(NULL), tables(NULL), storage(NULL), customer(NULL), kitchen(NULL) {}

    void init();    
};
#pragma once
#ifndef STATE_HPP
#define STATE_HPP
#include "Libraries.hpp"
#include "Timer.hpp"
#include "Object.hpp"
#include "Storer.hpp"
#include "Cooker.hpp"
#include "Customer.hpp"
// #include "Checker.hpp"
#include "Food.hpp"
#include "DisplayFactory.hpp"
#include "CustomerDesire.hpp"

// attachment display inside display of accompany, pass reference pointer.

class Food;

class Storer;
class Cooker;

class Customer;

class Status {
public:
    // virtual Status* getNextState(Customer* customer) = 0;
    virtual void action() = 0;
};

// multiple inheritance: status, object
class KitchenState : public Status {
private:
    Object* obj;
    int state;
    std::string file;
    Vector3 axis;
    float direction;
    Vector3 scale;
    Vector3 pos;
    KitchenState* nextState;
    float rx;
    float ry;
    float width;
    float height;
public:
    KitchenState(
        Object* obj, 
        int state, 
        std::string file, 
        Vector3 axis, 
        float direction, 
        Vector3 scale, 
        Vector3 pos, 
        float rx,
        float ry, 
        float width, 
        float height) :  
        state(state), 
        obj(obj), 
        file(file), 
        axis(axis), 
        direction(direction), 
        scale(scale), 
        pos(pos), 
        nextState(NULL), 
        rx(rx), 
        ry(ry), 
        width(width), 
        height(height) {
    }
    // bool interact();
    void action();
    virtual std::string getFile();
    KitchenState* getNextState();
    KitchenState* getState(int state);
    void setNextState(KitchenState* nextState);
    virtual void setDisplay();
};

class CustomerState : public Status {
protected:
    // nextState = new State, set next state in customer
    // handle request, and cycle state real as you want, 
    // handle state on self object and external movements
    Customer* customer;
    CustomerDesire* cd;
    CustomerDesire* cd1;
    bool valid;
    int state;
    Timer* timer;
    // display sample food?
public: 
    CustomerState(int state, Customer* customer) : customer(customer), state(state), timer(NULL), valid(true), cd(NULL), cd1(NULL) {
        // init();
    }  
    void init();
    void displayDesire();
    void initCustomerDesire();
    virtual void pause();
    CustomerState(Customer* customer) : customer(customer), state(2), timer(NULL), valid(true), cd(NULL), cd1(NULL) {
        // timer = new Timer(0, getTime(state));
        // timer -> start();
        // init();
        // initCustomerDesire();
    }
    bool interact();
    virtual std::string getFile(); // = 0; // youngcustomer state old customer state// 
    virtual int getTime(int state); // = 0;
    bool isValid();
    void handleRequest();
    virtual CustomerState* getNextState(Customer* customer);
    void action();
    int getState();
    ~CustomerState() {
        if (valid) {
            // timer -> stop();
            delete timer;
            timer = nullptr;
        }
    }
};

class OldCustomerState : public CustomerState {
public:
    // timer start here to get time
    OldCustomerState(Customer* customer) : CustomerState(customer) {
        CustomerState::init();
    }
    OldCustomerState(int state, Customer* customer) : CustomerState(state, customer) {
        CustomerState::init();
    }
    OldCustomerState* getNextState(Customer* customer);
    std::string getFile(); 
    int getTime(int state); 
};

class YoungCustomerState : public CustomerState {
public:
    // timer start here to get time
    YoungCustomerState(Customer* customer) : CustomerState(customer) {
        CustomerState::init();
    }
    YoungCustomerState(int state, Customer* customer) : CustomerState(state, customer) {
        CustomerState::init();
    }
    YoungCustomerState* getNextState(Customer* customer);
    std::string getFile(); 
    int getTime(int state); 
};

class TakeawayCustomerState : public CustomerState {
public:
    TakeawayCustomerState(Customer* customer) : CustomerState(customer) {}
    TakeawayCustomerState(int state, Customer* customer) : CustomerState(state, customer) {}
    TakeawayCustomerState* getNextState(Customer* customer);
    std::string getFile(); 
    int getTime(int state); 
};

class FoodState {
protected:
    Model food;
    Food* f;
    DisplayFactory* df;
    std::string description;
    std::set<std::string> food_set;
public:
    FoodState(std::string description, std::set<std::string> food_set): description(description), food_set(food_set) {
        df = DisplayFactory::getDF();
    }
    virtual void action() = 0;
    virtual std::string getFile() = 0;
};

class MotionlessState : public FoodState {
public:
    MotionlessState(std::string description, std::set<std::string> food_set) : FoodState(description, food_set) {
        // std::cerr << description << '\n';

        // food = LoadModel(description.c_str());
    }
    std::string getFile();
    void action();
};

#endif 
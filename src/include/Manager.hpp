#pragma once
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Mediator.hpp"
#include "TableHolder.hpp"
#include "CustomerHolder.hpp"

class Manager {
protected:
    MediatorChecker* mc;
    CustomerHolder* ch; // send message like object/ adapter or composite
    TableHolder* th;
    // Strategy* s;
public:
    Manager(int i) : ch(NULL), th(NULL), mc(NULL) {
        mc = new MediatorChecker();
        ch = new CustomerHolder();
        th = new TableHolder_2();
        // strategy level.
        // take 3 cus and assign 3
    }
    Manager(float i) : ch(NULL), th(NULL), mc(NULL) {
        mc = new MediatorChecker();
        ch = new CustomerHolder();
        th = new TableHolder_3();
        // strategy level.
        // take 3 cus and assign 3
    }
    Manager() : ch(NULL), th(NULL), mc(NULL) {
        mc = new MediatorChecker();
        ch = new CustomerHolder();
        th = new TableHolder();
        // strategy level.
        // take 3 cus and assign 3
    }
    virtual void init(ControllableObject* chef, Checker* c, Map* map, PauseGame* pause);
    virtual void assign();
    virtual void run();
    // void process();
    // assign initially, self-end
    // assign like mediator
    // message
};

class Manager_2 : public Manager {
public:
    Manager_2() : Manager(2) {}
    void init(ControllableObject* chef, Checker* c, Map* map, PauseGame* pause) {
        mc -> setChef(chef);
        mc -> setChecker(c);
        ch -> init(mc, map, pause);
        th -> init(map);
    }
    void assign() {
        mc -> notifyObjects();
        // table use a circular linked list
        // if strategy -> getNextCustomer != null
        // th -> get().receive(ch -> get());
        // not-full table is still set invalid to get.
        Table* tmp = th -> get();
        if (tmp && tmp -> receivable()) {
            Customer* temp = ch -> get();
            if (temp) tmp -> receive(temp);
        }
        
        return;
    }
    void run() {
        ch -> run();
        th -> manage();
    }
};

class Manager_3 : public Manager {
public: 
    Manager_3() : Manager(3.0f) {}
};

#endif
#pragma once
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Mediator.hpp"
#include "TableHolder.hpp"
#include "CustomerHolder.hpp"

class Manager {
private:
    MediatorChecker* mc;
    CustomerHolder* ch; // send message like object/ adapter or composite
    TableHolder* th;
    // Strategy* s;
public:
    Manager() : ch(NULL), th(NULL), mc(NULL) {
        mc = new MediatorChecker();
        ch = new CustomerHolder();
        th = new TableHolder();
        // strategy level.
        // take 3 cus and assign 3
    }
    void init(ControllableObject* chef, Checker* c, Map* map, PauseGame* pause);
    void assign();
    void run();
    // void process();
    // assign initially, self-end
    // assign like mediator
    // message
};

#endif
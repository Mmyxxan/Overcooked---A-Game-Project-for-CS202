#pragma once
#ifndef CUSTOMERHOLDER_HPP
#define CUSTOMERHOLDER_HPP

#include "Libraries.hpp"
#include "Customer.hpp"
#include "MediatorChecker.hpp"
#include "Map.hpp"
#include "PauseGame.hpp"

class CustomerHolder {
private:
    // alike space holder - template
    // strategy
    // 1 customer - many dishes -> check if one dish is in sb's desire, not if it's the same as sample food
    // samplefood linked list
    // review SLL in dictionary cs163
    // pool object?
    int num;
    Customer** p;
    Customer* head;
    // iterate by linked list, delete a node, add a node;
    // set space for customer
    int curID;
public:

    CustomerHolder() : curID(0), num(2), p(NULL), head(NULL) {
        p = new Customer*[num];
        for (int i = 0; i < num; i++) p[i] = nullptr;
    }
    void init(MediatorChecker* mc, Map* map, PauseGame* pause);
    Customer* manage();
    Customer* get();
    void run();
    // set some customer into invalid state of pool object, if it's exceed life time of a customer.
};

#endif
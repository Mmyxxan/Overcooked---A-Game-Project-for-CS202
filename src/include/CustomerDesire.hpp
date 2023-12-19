#pragma once
#ifndef CUSTOMERDESIRE_HPP
#define CUSTOMERDESIRE_HPP

#include "Libraries.hpp"
#include "SharedResources.hpp"
#include "Food.hpp"
#include "ModelFactory.hpp"

class CustomerDesire {
private:
    const Font font = SharedResources::getResources() -> getCustomerFont();
public:
    CustomerDesire() {}
    virtual void display() = 0;
};

class CustomerOrder : public CustomerDesire {
private:
    SampleFood* food;
    Vector3 pos;
    Model* food3d;
public:
    CustomerOrder(SampleFood* food, Vector3 pos) : food(food), pos(pos), food3d(NULL) {
        setUp();
    }
    void setUp();
    void display();
};

class CustomerEating : public CustomerDesire {
private:

public:
    CustomerEating() {}
};

#endif
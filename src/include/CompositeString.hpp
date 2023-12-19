#pragma once
#ifndef COMPOSITESTRING_HPP
#define COMPOSITESTRING_HPP

#include "Libraries.hpp"

// select 1 component: build with composite to enable this functionality
// use unordered set to store ingredients
// use try throw catch

class ComponentString {
private:
    int type;
    ComponentString* parent;
    std::string description;
public:
    ComponentString();  // (int type, ComponentString* parent, std::string description)
    ComponentString(int type, ComponentString* parent, std::string description);
    int getType();
    std::string getDescription();
    void setParent(ComponentString* parent);
    ComponentString* getParent();
    virtual void add(ComponentString* component);
    virtual void remove(ComponentString* component);
    virtual bool isProper(ComponentString* component);
};

// chef holding an emptycomposite

class CompositeString : public ComponentString {
private: 
    std::vector <ComponentString*> children;
public:
    CompositeString() : children({}) {

    }
    void add(ComponentString* component);
    void remove(ComponentString* component);
    bool isProper(ComponentString* component);
};

class PizzaComposite : public CompositeString {
public:
    void addPizzaComposite(PizzaComposite* pizza);
};

// model factory pass a pure object with scale direction axis model (not pos) and we copy it do display to other object we want
// struct Display {
// model scale direction axis
// modify underlyings code of object with this struct
// }

class PizzaBaseComposite : public PizzaComposite {
public:
    void addPizzaBase(PizzaComposite* pizza);
};

class PizzaToppingComposite : public PizzaComposite {
public:
    void addPizzaTopping(PizzaComposite* pizza);
};

// review the composite in head first more

#endif
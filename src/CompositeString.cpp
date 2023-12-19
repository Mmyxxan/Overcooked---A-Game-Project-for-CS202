#include <CompositeString.hpp>

// use type as a hierarchy indicator 
// add base, add topping, add main (same hierarchy), add more (lower, child hierarchy)

void CompositeString::add(ComponentString* component) {

}

void CompositeString::remove(ComponentString* component) {

}

bool CompositeString::isProper(ComponentString* component) {
    
}

ComponentString::ComponentString(int type, ComponentString* parent, std::string description) : type(type),
parent(parent), 
description(description) {
    
}

ComponentString::ComponentString() {
    
}

int ComponentString::getType() {
    return type;
}

std::string ComponentString::getDescription() {
    return description;
}

void ComponentString::setParent(ComponentString* parent) {
    this -> parent = parent;
}

ComponentString* ComponentString::getParent() {
    return parent;
}

void ComponentString::add(ComponentString* component) {

}

void ComponentString::remove(ComponentString* component) {

}

bool ComponentString::isProper(ComponentString* component) {

}
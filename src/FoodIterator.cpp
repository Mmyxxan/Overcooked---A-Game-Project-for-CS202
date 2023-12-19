#include <FoodIterator.hpp>

// use arrow keys to remotely control the food iterator, the same to pause key.
// create iterator

void FoodIterator::init() {
    list.push_back("dough");
    list.push_back("doughdough");
    iter = list.begin();
    return;
}

std::string FoodIterator::get() {
    return *iter; // copy the memory
    // iter pointing to food factory to pass a factory as parameter
    // factory -> get(Object* o)
    // in get wrapping object o with proper food that this factory manufacture
    // return a food factory
    // or make a copy constructor
    // get(Object* o) : Food* temp = new Food(*iter -> description, o); can be processed here or in storer functioning state
}

void FoodIterator::next() {
    ++iter;
    if (iter == list.end()) iter = list.begin();
    return;
}

void FoodIterator::back() {
    if (iter == list.begin()) {
        iter = list.end();  // Set to the last element
    }
    --iter;
    return;
}

void FoodIterator::display() {

}

// associated with controller to press arrow keys to back and next
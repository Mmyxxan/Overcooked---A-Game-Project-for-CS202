#include <FoodIterator.hpp>

// use arrow keys to remotely control the food iterator, the same to pause key.
// create iterator

void FoodIterator::init() {
    frame = TextureFactory::getTextureFactory() -> getTexture("food.png");
    list.push_back("dough");
    list.push_back("onion");
    list.push_back("sausage");
    list.push_back("pepperoni");
    list.push_back("tomato");
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
    setFoodTexture(*iter);
    EndMode3D();
    if (frame) DrawTexture(*frame, 0, 0, WHITE);
    if (food) DrawTexture(*food, 0, 0, WHITE);
    // I can make it like *iter -> display(); but here I do not have a vector of food class, it's a vector of stirng so I have to make it like this, manually and not really oop.
    BeginMode3D(*CameraGame::getCamera());
}

void FoodIterator::setFoodTexture(std::string food) {
    this -> food = TextureFactory::getTextureFactory() -> getTexture(food + ".png");
    return;
}

// associated with controller to press arrow keys to back and next
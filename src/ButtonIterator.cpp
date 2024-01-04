#include <ButtonIterator.hpp>

// create another controller to manage all keys input, including button triggered input
// data design oriented programming
// chapter level, change chef, change map

void ButtonIterator::update(int key) {
    if (key == KEY_RIGHT) next();
    if (key == KEY_LEFT) back();
    (*iter) -> update(true);
}

void ButtonIterator::add(Button* button) {
    buttons.push_back(button);
}

void ButtonIterator::init() {
    iter = buttons.begin();
    (*iter) -> update(true);
    // iter = end();
}

Button* ButtonIterator::get() {
    return *iter;
}

void ButtonIterator::next() {
    (*iter) -> update(false);
    ++iter;
    if (iter == buttons.end()) iter = buttons.begin();

}

void ButtonIterator::back() {
    (*iter) -> update(false);
    if (iter == buttons.begin()) {
        iter = buttons.end();  // Set to the last element
    }
    --iter;
}

void ButtonIterator::display() {
    for (int i = 0; i < buttons.size(); i++) {
        if (buttons[i]) buttons[i] -> display();
    }
}
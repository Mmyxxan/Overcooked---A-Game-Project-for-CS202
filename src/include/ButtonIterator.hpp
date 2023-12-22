#pragma once
#ifndef BUTTONITERATOR_HPP
#define BUTTONITERATOR_HPP

#include "Libraries.hpp"
#include "Button.hpp"

class ButtonIterator {
private:
    std::vector<Button*> buttons;
    std::vector<Button*>::iterator iter;
public:
    ButtonIterator() : buttons({}), iter(buttons.begin()) {
        // call void init();
        // iter = buttons.end();
    }
    void update(int key);
    void add(Button* button);
    void init();
    Button* get();
    void next();
    void back();
    void display();
};

#endif
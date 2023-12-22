#pragma once
#ifndef UI_HPP
#define UI_HPP

#include "Libraries.hpp"
#include "Screen.hpp"

class UI {
private:
    const int screenWidth = 1400;
    const int screenHeight = 800;
    Screen* currentScreen;
public:
    UI(Screen* currentScreen) : currentScreen(currentScreen) {}
    void init();
    void run();
    void handle();
};

#endif
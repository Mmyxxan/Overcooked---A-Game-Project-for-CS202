#pragma once
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Libraries.hpp"
#include "GameAudio.hpp"

// can be copied from dictionary
// texture factory

class Screen {
private:
    Screen* nextScreen;
    GameAudio* audio;
    Texture* background;
    // button array
public:
    Screen() : nextScreen(nullptr), audio(nullptr), background(nullptr) {}
    virtual void handleGamePause();
    virtual void init();
    virtual void render();
};

#endif
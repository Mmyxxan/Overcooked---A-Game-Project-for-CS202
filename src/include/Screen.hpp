#pragma once
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Libraries.hpp"
#include "GameAudio.hpp"
#include "Button.hpp"
#include "ButtonIterator.hpp"
#include "GameManager.hpp"
#include "GameInstruction.hpp"

// can be copied from dictionary
// texture factory

class Screen {
protected:
    Button* bg;
    Screen* nextScreen;
    GameManager* game;
    GameAudio* audio;
    Texture* background;
    Button* buttons;
    ButtonIterator* button_iterator;
    GameInstruction* instruction;
    // button array
public:
    Screen() : nextScreen(nullptr), audio(nullptr), background(nullptr), buttons(nullptr), button_iterator(nullptr), bg(nullptr), game(NULL), instruction(NULL) {}
    virtual void handleGamePause();
    virtual void handleEvents();
    virtual void setNextScreen(Screen* nextScreen);
    virtual Screen* getNextScreen();
    virtual void init();
    virtual void render();
    Screen* createScreen(int screen);
};

class MenuScreen : public Screen {
private:
    const int num = 4;
public: 
    MenuScreen() : Screen() {}
    void handleEvents();
    void render();
    void init();
};

class GameScreen : public Screen {
public:
    GameScreen() : Screen() {}
    void handleEvents();
    void render();
    void init();
};

class ExitScreen : public Screen {
public:
    ExitScreen() : Screen() {}
    void handleEvents();
    void render();
    void init();
};

class MapScreen : public Screen {
public:
    MapScreen() : Screen() {}
    void handleEvents();
    void render();
    void init();
};

class FirstGameScreen : public Screen {
public:
    FirstGameScreen() : Screen() {}
    void handleEvents();
    void render();
    void init();
};
 
#endif
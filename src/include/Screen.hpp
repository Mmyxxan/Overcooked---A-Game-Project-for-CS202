#pragma once
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Libraries.hpp"
#include "GameAudio.hpp"
#include "Button.hpp"
#include "ButtonIterator.hpp"
#include "GameManager.hpp"
#include "GameInstruction.hpp"
#include "CameraGame.hpp"
#include "DrawNumber.hpp"

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

class PauseScreen : public Screen {
private:
public:
    PauseScreen(GameManager* game) : Screen() {
        Screen::game = game;
    }
    void handleEvents();
    void render();
    void init();
};

class GameScreen : public Screen {
private:
    Screen* pauseScreen;
public:
    GameScreen(GameManager* game) : Screen(), pauseScreen(NULL) {
        Screen::game = game;
    }
    void handleEvents();
    void render();
    void init();
};

class FirstGameScreen : public GameScreen {
public:
    FirstGameScreen(GameManager* game) : GameScreen(game) {}
    // void handleEvents();
    // void render();
    void init();
};

class SecondGameScreen : public GameScreen {
public:
    SecondGameScreen(GameManager* game) : GameScreen(game) {}
    void init();
};

class GameUpScreen : public Screen {
private:
    DrawNumber* draw;
public:
    GameUpScreen(GameManager* game) : Screen(), draw(NULL) {
        Screen::game = game;
    }
    void handleEvents();
    void render();
    void init();
};
 
#endif
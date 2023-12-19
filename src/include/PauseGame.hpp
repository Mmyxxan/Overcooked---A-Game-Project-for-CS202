#pragma once
#ifndef PAUSEGAME_HPP
#define PAUSEGAME_HPP

#include "Libraries.hpp"
#include "Object.hpp"

// composite holder 
class PauseGame {
private:
    bool isPaused;
    std::vector <Object*> obs;
public:
    PauseGame() : obs({}), isPaused(false) {

    }
    void toggle();
    bool Paused();
    void pause();
    void registerObject(Object* obj);
    // void registerHolder(); // iterator pattern
    void notifyObjects();
};


#endif
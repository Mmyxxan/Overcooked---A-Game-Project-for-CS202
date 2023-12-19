#include <PauseGame.hpp>

// think of a way to initialize every object observes this one, in the most efficient way
// static?
// pause current screen and object
// change screen unload all objects, init again and display
// screen display

void PauseGame::toggle() {
    isPaused ^= 1;
}

bool PauseGame::Paused() {
    return isPaused;
}

void PauseGame::pause() {
    notifyObjects();
}

void PauseGame::registerObject(Object* obj) {
    obs.push_back(obj);
}

void PauseGame::notifyObjects() {
    for (int i = 0; i < obs.size(); i++) {
        obs[i] -> pause();
    }
}
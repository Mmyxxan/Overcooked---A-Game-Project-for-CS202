#include <Controller.hpp>

void Controller::registerObject(Object* o) {
    obj.push_back(o);
}

bool Controller::isKeyPressed(char x) {
    return IsKeyDown(x);
}

void Controller::control() {
    // undo = false;
    // for (int i = 0; i < obj.size() - 1; i++) {
    //     for (int j = i + 1; j < obj.size(); j++) {
    //         if (CheckCollisionBoxes(obj[i] -> getBoundingBox(), obj[j] -> getBoundingBox())) {
    //             undo = true;
    //             return;
    //         }
    //     }
    // }
    // std::cout << undo << '\n';
    // optimization;
    if (IsKeyDown(KEY_A)) key = 'A';
    else if (IsKeyDown(KEY_S)) key = 'S';
    else if (IsKeyDown(KEY_D)) key = 'D';
    else if (IsKeyDown(KEY_W)) key = 'W';
    else key = '\n';
    
}

void Controller::notifyObservers() {
    for (int i = 0; i < obj.size(); i++) obj[i] -> update(key);
}
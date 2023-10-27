#include <ControllableObject.hpp>
// posofAttachment = posofChef + vectorpos chênh lệch;
std::string ControllableObject::getDescription() {
    return description;
}

void ControllableObject::setKeyLeft(char x) {
    left = x;
}
void ControllableObject::setKeyRight(char x) {
    right = x;
}
void ControllableObject::setKeyUp(char x) {
    up = x;
}
void ControllableObject::setKeyDown(char x) {
    down = x;
}
char ControllableObject::keyLeft() {
    return left;
}
char ControllableObject::keyRight() {
    return right;
}
char ControllableObject::keyUp() {
    return up;
}
char ControllableObject::keyDown() {
    return down;
}
void ControllableObject::setLeft() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setDirection(-90.0f);
    }
    setDirection(-90.0f);
}
void ControllableObject::setRight() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setDirection(90.0f);
    }
    setDirection(90.0f);
}
void ControllableObject::setUp() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setDirection(180.0f);
    }
    setDirection(180.0f);
}
void ControllableObject::setDown() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setDirection(0.0f);
    }
    setDirection(0.0f);
}
void ControllableObject::setMoveLeft() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos({tmp -> getPos().x - speed, tmp -> getPos().y, tmp -> getPos().z});
    }
    setPos({getPos().x - speed, getPos().y, getPos().z});
}
void ControllableObject::setMoveRight() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos({tmp -> getPos().x + speed, tmp -> getPos().y, tmp -> getPos().z});
    }
    setPos({getPos().x + speed, getPos().y, getPos().z});
}
void ControllableObject::setMoveUp() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos({tmp -> getPos().x, tmp -> getPos().y + speed, tmp -> getPos().z});
    }
    setPos({getPos().x, getPos().y + speed, getPos().z});
}
void ControllableObject::setMoveDown() {
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos({tmp -> getPos().x, tmp -> getPos().y - speed, tmp -> getPos().z});
        // I ought to wrap this setPos?
    }
    setPos({getPos().x, getPos().y - speed, getPos().z});
}
void ControllableObject::update(const char event) {
    // if (undo) {
    //     if (event == left) {
    //         setMoveRight();
    //     }
    //     else if (event == right) {
    //         setMoveLeft();
    //     }
    //     else if (event == up) {
    //         setMoveDown();
    //     }
    //     else if (event == down) {
    //         setMoveUp();
    //     }
    //     return;
    // }
    if (event == left) {
        setLeft();
        setMoveLeft();
    }
    else if (event == right) {
        setRight();
        setMoveRight();
    }
    else if (event == up) {
        setUp();
        setMoveUp();
    }
    else if (event == down) {
        setDown();
        setMoveDown();
    }
}
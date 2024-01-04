#include <ControllableObject.hpp>

// posofAttachment = posofChef + vectorpos chênh lệch;
// std::string ControllableObject::getDescription() {
//     return description;
// }

void ControllableObject::display()  {
    if (att) att -> display();
    DrawModelEx(*model, position, axis, direction, scale, WHITE);
}

void ControllableObject::attach(Object* o) {
    std::cerr << "att initialized" << std::endl;
    // if (att) return;
    // std::cerr << "att" << std::endl;
    att = o;
    if (!o) return;
    // o -> setPos(Vector3Add(getPos(), getSpace()));
    // knife transform, multiply matrix as parameters
    if (orientation == 'L') setSpace({-2.0f, 0.0f, -1.0f});
    else if (orientation == 'R') setSpace({2.0f, 0.0f, -1.0f});
    else if (orientation == 'U') setSpace({0.0f, 2.0f, -1.0f});
    else if (orientation == 'D') setSpace({0.0f, -2.0f, -1.0f});
    att -> setPos(Vector3Add(getPos(), getSpace()));
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
    orientation = 'L';
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        // tmp -> setDirection(-90.0f);
        // tmp -> display();
    }
    setDirection(-90.0f);
}
void ControllableObject::setRight() {
    orientation = 'R';
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        // tmp -> setDirection(90.0f);s
        // tmp -> display();
    }
    setDirection(90.0f);
}
void ControllableObject::setUp() {
    orientation = 'U';
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        // tmp -> setDirection(180.0f);
        // tmp -> display();
    }
    setDirection(180.0f);
}
void ControllableObject::setDown() {
    orientation = 'D';
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        // tmp -> setDirection(0.0f);
        // tmp -> display();
    }
    setDirection(0.0f);
}
void ControllableObject::setMoveLeft() {
    if (!(map -> Movable(getPos().x - speed, getPos().y, this -> area))) return;
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos(Vector3Add(getPos(), {-2.0f, 0.0f, -1.0f}));
        // tmp -> display();
    }
    setPos({getPos().x - speed, getPos().y, getPos().z});
    // CameraGame::getCamera() -> target = getPos();
    // CameraGame::getCamera() -> position = Vector3Add(CameraGame::getCamera() -> position, {-speed, 0.0f, 0.0f});
}
void ControllableObject::setMoveRight() {
    if (!(map -> Movable(getPos().x + speed, getPos().y, this -> area))) return;
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos(Vector3Add(getPos(), {2.0f, 0.0f, -1.0f}));
    }
    setPos({getPos().x + speed, getPos().y, getPos().z});
    // CameraGame::getCamera() -> target = getPos();
    // CameraGame::getCamera() -> position = Vector3Add(CameraGame::getCamera() -> position, {speed, 0.0f, 0.0f});
}
void ControllableObject::setMoveUp() {
    if (!(map -> Movable(getPos().x, getPos().y + speed, this -> area))) return;
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos(Vector3Add(getPos(), {0.0f, 2.0f, -1.0f}));
    }
    setPos({getPos().x, getPos().y + speed, getPos().z});
    // CameraGame::getCamera() -> target = getPos();
    // CameraGame::getCamera() -> position = Vector3Add(CameraGame::getCamera() -> position, {0.0f, 0.0f + speed, 0.0f});
}
void ControllableObject::setMoveDown() {
    if (!(map -> Movable(getPos().x, getPos().y - speed, this -> area))) return;
    if (this -> getAttachment()) {
        Object* tmp = this -> getAttachment();
        tmp -> setPos(Vector3Add(getPos(), {0.0f, -2.0f, -1.0f}));
        // I ought to wrap this setPos?
    }
    setPos({getPos().x, getPos().y - speed, getPos().z});
    // CameraGame::getCamera() -> target = getPos();
    // CameraGame::getCamera() -> position = Vector3Add(CameraGame::getCamera() -> position, {0.0f, 0.0f - speed, 0.0f});
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
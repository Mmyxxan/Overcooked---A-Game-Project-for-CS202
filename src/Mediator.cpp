#include <Mediator.hpp>

Object* Mediator::getAttachment() {
    att = chef -> getAttachment();
    chef -> deattach();
    return att;
}

void Mediator::assignBack(Object* o) {
    chef -> attach(o);
}

void Mediator::registerObject(Object* o) {
    obj.push_back(o);
}

void Mediator::notifyObjects() {
    for (int i = 0; i < obj.size(); i++) {
        obj[i] -> update(getChefX(), getChefY());
        obj[i] -> Process();
    }
    return;
}

float Mediator::getChefX() {
    return chef -> getPos().x;
}

float Mediator::getChefY() {
    return chef -> getPos().y;
}
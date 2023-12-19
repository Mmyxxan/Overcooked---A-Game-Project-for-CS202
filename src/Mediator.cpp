#include <Mediator.hpp>

void Mediator::drop() {
    att = NULL;
}

Object* Mediator::getAttachment() {
    return att;
}

Object* Mediator::getAttachmentfrom() {
    att = chef -> getAttachment();
    chef -> deattach();
    return att;
}

void Mediator::assignBack(Object* o) {
    if (o) o -> display();
    chef -> attach(o);
    std::cerr << "done assign back" << '\n';
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
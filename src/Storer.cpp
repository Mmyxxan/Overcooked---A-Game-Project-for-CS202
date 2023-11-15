#include <Storer.hpp>

void Storer::display() {
    DrawModelEx(model, position, axis, direction, scale, WHITE);
}

void Storer::setMediator(Mediator* m) {
    this -> m = m;
    m -> registerObject(this);
}

void Storer::update(float x, float y) {
    state = State::rest;
    if (isInArea(x, y)) state = State::activated;
    if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    return;
}

bool Storer::isInArea(float x, float y) {
    return area -> isInArea(x, y);
}

void Storer::Process() {
    if (state != State::functioning) return;
    std::cerr << "Functioning State" << '\n';
    Object* temp = m -> getAttachmentfrom();
    m -> drop();
    temp = new StorerMaterial(temp);
    m -> assignBack(temp);
    state = State::rest;
    return;
}


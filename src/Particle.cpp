#include <Particle.hpp>

void Particle::attach(Object* o) {
    att = o;
    if (!o) return;
    if (o -> getFile() == "3DGodotRobot.glb") setSpace({0.0f, -1.5f, -1.0f});
    else setSpace({0.0f, 0.0f, 0.0f});
    o -> setPos(Vector3Add(getPos(), getSpace()));
    return;
}

void Particle::setNext(Particle* next) {
    this -> next = next;
}
Particle* Particle::getNext() {
    return next;
}
void Particle::setValid() {
    valid = true;
}
void Particle::setInvalid() {
    att = NULL;
    // valid = false;
}

bool Particle::isValid() {
    return (att != NULL);
}
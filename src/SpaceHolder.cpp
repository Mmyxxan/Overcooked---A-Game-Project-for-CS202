#include <SpaceHolder.hpp>

void SpaceHolder::init() {
    head = &p[0];
    for (int i = 0; i < num - 1; i++) p[i].setNext(&p[i + 1]);
    p[num - 1].setNext(nullptr);
    return;
}
// invalid = not in action
Particle* SpaceHolder::manage() {
    for (int i = 0; i < num; i++) {
        if (!p[i].isValid() && p[i].valid) {
            std::cout << "space manage successfully" << std::endl;
            p[i].setInvalid();
            p[i].valid = false;
            p[i].setNext(head);
            head = &p[i];
        }
    }
    return head;
}

Particle* SpaceHolder::get() {
     // manage before get
    manage();
    if (!head) return nullptr;
    head -> setValid();
    Particle* temp = head;
    head = head -> getNext();
    return temp;
}
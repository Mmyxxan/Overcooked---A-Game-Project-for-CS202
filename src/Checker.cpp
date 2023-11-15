#include <Checker.hpp>

void GameManager::init() {

}

void MediatorChecker::notifyChecker(std::string description) {
    checker -> update(description);
}

void MediatorChecker::drop() {
    att = NULL;
}

Object* MediatorChecker::getAttachment() {
    return att;
}

Object* MediatorChecker::getAttachmentfrom() {
    att = chef -> getAttachment();
    chef -> deattach();
    return att;
}

void MediatorChecker::notifyObjects() {
    for (int i = 0; i < obj.size(); i++) {
        obj[i] -> update(getChefX(), getChefY());
        obj[i] -> Process();
        if (obj[i] -> getState() == Customers::outdated) {
            notifyChecker(obj[i] -> selfAssess());
            deregisterObject(obj[i] -> getID());
            i--;
        } // destroy obj by holder, deregister
    }
}

float MediatorChecker::getChefX() {
    return chef -> getPos().x;
}

float MediatorChecker::getChefY() {
    return chef -> getPos().y;
}

void MediatorChecker::deregisterObject(int id) {
    for (int i = 0; i < obj.size(); i++) {
        if (obj[i] -> getID() == id) {
            obj.erase(obj.begin() + i);
            return;
        }
    }
}

void MediatorChecker::registerObject(Object* o) {
    obj.push_back(o); // caution of null
}

bool Checker::isTimeleft() {
    return !(timer -> finish());
}

void Checker::update(const std::string description) {
    if (description == "right") score += 50;
}

void Customer::setMediatorChecker(MediatorChecker* mc) {
    this -> mc = mc;
    mc -> registerObject(this);
}

int Customer::getID() {
    return ID;
}

std::string Customer::selfAssess() {
    if (!att) return "wrong";
    if (f -> assess(att)) {
        return "right";
        // return f -> getDescription();
    }
    return "wrong";
}

bool Customer::isInArea(float x, float y) {
    return area -> isInArea(x, y);
}

// not reusable pattern
// cycle pattern
void Customer::update(float x, float y) {
    if (state == Customers::outdated) return; // check its timer
    state = State::rest;
    if (isInArea(x, y)) state = State::activated;
    if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    // if (timer) {
    //     state = State::invalid;
    //     if (timer -> finish()) state = Customers::outdated;
    // }
    return;
}

void Customer::Process() {
    if (state != State::functioning || state == Customers::outdated) return;
    std::cerr << "Functioning State" << '\n';
    Object* temp = mc -> getAttachmentfrom();
    mc -> drop();
    attach(temp);
    state = State::invalid;
    // start eating; eating done: state outdated
    // state = Customers::outdated;
    return;
}

int Customer::getState() {
    // conditional
    // holder make it outdated state or getstate make it self;
    return state;
}
#include <Cooker.hpp>

void Cooker::display() {
    if (timer && timer -> finish()) {
        Object* temp = m -> getAttachment();
        temp = new CookerWrapper(temp);
        // o = new CookerWrapper(o); another mediator notifies Food and it changes itself
        state = State::rest;
        timer -> stop();
        delete timer;
        timer = nullptr;
    }
    DrawModelEx(model, position, axis, direction, scale, WHITE);
    // display statement;
}

void Cooker::attach(Object* o) {
    
}

bool Cooker::isInArea(float x, float y) {
    return area -> isInArea(x, y);
}

void Cooker::Process() {
    // processor* p = new FoodProcess();
    // FoodProcess: Apple Process, MeatProcess;
    // mediator function: p -> process(food object);
    // every interaction is attach, processing is another thing.
    // chef attach object to cooker, cooker attach object to chef.
    // delete p;
    if (state != State::functioning) return;
    if (getAttachment()) {
        m -> assignBack(getAttachment());
        deattach();
        return;
    }
    if (!timer) {
        timer = new Timer(0, 10);
        timer -> start();
        attach(m -> getAttachment());
        return;
    }
    if (!timer -> finish()) {
        return;
    }
    return;
    // timer display
}

void Cooker::update(float x, float y) {
    state = State::rest;
    if (isInArea(x, y)) state = State::activated; else return;
    if (IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    return;
}

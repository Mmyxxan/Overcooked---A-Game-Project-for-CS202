#include <Cooker.hpp>

int Cooker::getState() {
    if (timer) {
        if (timer -> finish()) return State::invalid;
        return State::functioning;
    } 
    if (isInArea(m -> getChefX(), m -> getChefY())) return State::activated;
    return State::rest;
}
// void setState();

void Cooker::setMediator(Mediator* m) {
    this -> m = m;
    m -> registerObject(this);
}

void Cooker::display() {
    // if (timer && timer -> finish()) {
        
        // o = new CookerWrapper(o); another mediator notifies Food and it changes itself
        
    // }
    DrawModelEx(model, position, axis, direction, scale, WHITE);
    // display statement;
}

void Cooker::attach(Object* o) {
    att = o;
    if (!o) return;
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
    std::cerr << "Functioning State" << '\n';
    if (timer && !(timer -> finish())) {
        std::cerr << "Functioning & cannot take out" << '\n';
        return;
    }
    // if (getAttachment() && (!timer || (timer && timer -> finish()))) {
    if (getAttachment() && ((timer && timer -> finish()))) {
        std::cerr << "Done functioning & take out" << '\n';
        Object* temp = getAttachment();
        temp = new CookerWrapper(temp);
        m -> assignBack(temp);
        deattach();
        state = State::rest;
        timer -> stop();
        delete timer;
        timer = nullptr;
        std::cerr << "Delete timer" << '\n';
        return;
    }
    if (!timer) {
        std::cerr << "Start functioning" << '\n';
        if (m -> getAttachmentfrom() == nullptr) return;
        timer = new Timer(0, 10);
        timer -> start();
        attach(m -> getAttachment());
        m -> drop();
        return;
    }
    if (timer) std::cerr << "Timer is not deleted" << '\n';
    if (getAttachment()) std::cerr << "There is still attachment" << '\n';
    return;
    // timer display
}

void Cooker::update(float x, float y) {
    state = State::rest;
    if (isInArea(x, y)) state = State::activated;
    if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    return;
}

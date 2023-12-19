#include <Cooker.hpp>

void Cooker::pause() {
    if (timer) timer -> togglePause();
}

void Cooker::displayTimer() {
    static int count = 0;
    static int frame = 0;
    if (!timer) return;
    if (timer -> finish()) {
        DrawModelEx(time, {position.x - 0.7f + (float) frame/2, position.y, position.z + 3}, {1.0f, 0.0f, 0.0f}, 90.0f, {0.7f, 0.7f, 0.7f}, WHITE);
        ++count;
        if (count % 4 == 0) {
            frame = (frame + 1) % 2;
            count = 0;
        }
    }
    else DrawModelEx(time, {position.x - 0.7f, position.y, position.z + 3}, {1.0f, 0.0f, 0.0f}, 90.0f, {0.7f, 0.7f, 0.7f}, WHITE);
}

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
    if (att) att -> display();
    displayTimer();
    DrawModelEx(*model, position, axis, direction, scale, WHITE);
    // display statement;
}

void Cooker::attach(Object* o) {
    att = o;
    if (!o) return;
    att -> setPos(getPos());
}

bool Cooker::isInArea(float x, float y) {
    return area -> isInArea(x, y);
}

bool Cooker::wrappable(Object* o) {
    if (!o) return false;
    if (o -> getFile() == "dough.glb") return true; //false;
    return true;
}

void Cooker::wrap() {
    Object* temp = getAttachment();
    if (wrappable(temp)) temp = new Food(temp, food_description);
    else return;
    deattach();
    attach(temp);
}

void Cooker::Process() {
    // overcooked = outdated, most prior to other state, can't be changed easily, if state == overcooked and process mean assign back the spoiled food.
    // processor* p = new FoodProcess();
    // FoodProcess: Apple Process, MeatProcess;
    // mediator function: p -> process(food object);
    // every interaction is attach, processing is another thing.
    // chef attach object to cooker, cooker attach object to chef.
    // delete p;
    // if state == overcooked and 5s is over and getAttachment() return spoiled food, if 5s is not over return wrapped normal food, at this step change back to rest.
    // change state at this step or in cycle?
    if (state != State::functioning) return;
    std::cerr << "Functioning State" << '\n';
    if (timer && !(timer -> finish())) {
        std::cerr << "Functioning & cannot take out" << '\n';
        return;
    }
    // if (getAttachment() && (!timer || (timer && timer -> finish()))) {
    if (getAttachment() && ((timer && timer -> finish()))) {
        std::cerr << "Done functioning & take out" << '\n';
        wrap();
        m -> assignBack(getAttachment());
        deattach();
        state = State::rest;
        // do not make spoil state;
        timer -> stop();
        delete timer;
        timer = nullptr;
        std::cerr << "Delete timer" << '\n';
        return;
    }
    if (!timer) {
        std::cerr << "Start functioning" << '\n';
        if (m -> getAttachmentfrom() == nullptr ||  (m -> getAttachment() && !wrappable(m -> getAttachment()))) {
            m -> assignBack(m -> getAttachment());
            return;
        }
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
    // if (timer && timer -> finish() && state != State::outdated) {
    //     state = State::outdated;
    //     return;
    // }
    state = State::rest;
    if (isInArea(x, y)) state = State::activated;
    if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    return;
}

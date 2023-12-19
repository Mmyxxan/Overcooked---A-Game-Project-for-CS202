#include <Customer.hpp>
#include <State.hpp>

SampleFood* Customer::getSampleFood() {
    return f;
}

void Customer::pause() {
    if (status) status -> pause();
}

void Customer::attach(Object* o) {
    if (!o) return;
    att = o;
    if (getFile() == "3DGodotRobot.glb") setSpace({0.0f, -3.0f, 1.0f});
    else setSpace({0.0f, -4.0f, 0.0f});
    o -> setPos(Vector3Add(getPos(), getSpace()));
}

std::string Customer::getFile() {
    return status -> getFile();
}

void Customer::setNext(Customer* next) {
    this -> next = next;
}
Customer* Customer::getNext() {
    return next;
}

void Customer::bringIntoState() {
    if (status) delete status;
    status = nullptr;
    inUse = true;
    // status = new CustomerState(this);
    CustomerFactory::getCustomerFactory() -> get(Level::getLevel(), this);
    // get from factory customer
    setModel();
    if (getFile() == "3DGodotRobot.glb") {
        setScale({2.0f, 2.0f, 2.0f});
        setAxis({1.0f, 0.0f, 0.0f});
        setDirection(90.0f);
        
    }
    else {
        setScale({8.0f, 8.0f, 8.0f});
        setAxis({0.0f, 0.0f, 1.0f});
        setDirection(0.0f);
    }
    

    
    // customer -> setPos({0.0f, 2.0f, 1.0f});
    // set direction, axis...
}

void Customer::assignSpace(Particle* space) {
    this -> space = space;
}

void Customer::detachfromSpace() {
    space -> setInvalid();
    space = NULL;
}

void Customer::changeState(CustomerState* status) {
    this -> status = status;
}

void Customer::setMediatorChecker(MediatorChecker* mc) {
    this -> mc = mc;
    mc -> registerObject(this);
}

int Customer::getID() {
    return ID;
}

std::string Customer::selfAssess() {
    if (!att) {
        // std::cout << "not assessed" << '\n';
        assess = "wrong";
        return "wrong";
    }
    if (f -> assess(att)) {
        std::cout << "assessed" << '\n';
        assess = "right";
        return "right";
        // return f -> getDescription();
    }
    assess = "wrong";
    return "wrong";
}

bool Customer::isInArea(float x, float y) {
    // area -> resetArea();
    // area -> removeArea({getPos().x, getPos().y}, 2.0f, 2.0f);
    return area -> isInArea(x, y);
}

// not reusable pattern
// cycle pattern
void Customer::update(float x, float y) {
    // if (lifetimer -> finish()) state = Customers::outdated;
    // if (state == Customers::outdated) {
    //     lifetimer -> stop();
    //     if (timer) timer -> stop();
    //     return; // check its timer
    // }
    // state = State::rest;
    // if (isInArea(x, y)) {
    //     // std::cerr << "This object found" << std::endl;
    //     state = State::activated;
    // }
    // else {
    //     std::cerr << "This object found" << std::endl;
    // }
    // if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
    //     state = State::functioning;
    // }
    // if (timer) {
    //     state = State::invalid;
    //     if (timer -> finish()) state = Customers::outdated;
    // }
    // return;
}

void Customer::systemAssess() {
    // if (getState() == Customers::outdated) {
        mc -> notifyChecker(assess);
    // }
}

void Customer::displayDesire() {
    if (status) status -> displayDesire();
    return;
}

void Customer::Process() {
    // std::cout << "customer with ID " << ID << " is processing\n";
    if (isInArea(mc -> getChefX(), mc -> getChefY())) {
        displayDesire();
    }
    if (isInArea(mc -> getChefX(), mc -> getChefY()) && IsKeyPressed(KEY_SPACE)) {
        if (status -> interact()) {
            Object* temp = mc -> getAttachmentfrom();
            mc -> drop();
            attach(temp);
        }
    }
    // status -> action();
    // if (getState() == Customers::outdated) {
    //     mc -> notifyChecker(assess);
    // }
    // if (state != State::functioning || state == Customers::outdated) return;
    // std::cerr << "Functioning State" << '\n';
    // timer = new Timer(0, 10);
    // timer -> start();
    // Object* temp = mc -> getAttachmentfrom();
    // mc -> drop();
    // attach(temp);
    // state = State::invalid;


    // start eating; eating done: state outdated
    // state = Customers::outdated;
    return;
}

int Customer::getState() {
    if (!status) return Customers::outdated;
    int state = status -> getState();
    // if (state == State::outdated) this -> detachfromSpace();
    // conditional
    // holder make it outdated state or getstate make it self;
    // return status -> getState();
    return state;
}
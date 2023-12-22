#include <State.hpp>
#include <Checker.hpp>

KitchenState* KitchenState::getState(int state) {
    if (this -> state == state) return this;
    if (nextState) return nextState -> getState(state);
    return nullptr;
}

void KitchenState::action() {
    obj -> setModel();
    DrawModelEx(*obj -> model, obj -> position, obj -> axis, obj -> direction, obj -> scale, WHITE);
}

KitchenState* KitchenState::getNextState() {
    return nextState;
}

void KitchenState::setNextState(KitchenState* nextState) {
    this -> nextState = nextState;
}

std::string KitchenState::getFile() {
    return file;
}

void KitchenState::setDisplay() {
    obj -> setFile(getFile());
    obj -> setAxis(axis);
    obj -> setDirection(direction);
    obj -> setPos(pos);
    obj -> setScale(scale);
    return;
}

void MotionlessState::action() {
    // std::cerr << "food display: ";
    // std::cerr << description << '\n';
    // DrawModelEx
}

std::string MotionlessState::getFile() {
    return df -> getFile(description);
}

void CustomerState::init() {
    if (state == State::outdated) {
        valid = false; 
        // customer -> detachfromSpace();
    }
    else {
        timer = new Timer(0, getTime(state));
        timer -> start();
        // initCustomerDesire();
        // bring to function init to virtual
    }
}

void CustomerState::initCustomerDesire() {
    // std::cout << "init with customer " << customer -> getID() << '\n';
    if (state == State::functioning && !cd) {
        cd = new CustomerOrder(customer -> getSampleFood(), {4.4f, 5.0f, 5.0f});
    }
    if (state == State::functioning && !cd1) {
        cd1 = new CustomerWaiting(customer -> getSampleFood(), timer);
    }
}

void CustomerState::pause() {
    // if (getFile() == "customer.glb") std::cout << "customer is paused" << '\n';
    // if (getFile() == "3DGodotRobot.glb") std::cout << "customer has a pause" << '\n';
    if (timer) timer -> togglePause();
}

void CustomerState::handleRequest() {
    initCustomerDesire();
    if (state == 2 && customer -> getAttachment()) {
        customer -> changeState(getNextState(customer));
        return;
    }
    // std::cout << state << std::endl;
    if (timer -> finish()) {
        if (state == 3) {
            // if (getState() == Customers::outdated)
            customer -> selfAssess();
            customer -> systemAssess();
            if (cd) delete cd;
            cd = nullptr;
            if (customer -> getAttachment()) customer -> deattach();
            if (customer -> space) customer -> detachfromSpace();
        }
        // if state == 5 && timer -> finish() cooker -> changeState(0, customer)
        // if state == 3 cooker -> display timer
        customer -> changeState(getNextState(customer));
    }
    // if (state == 3 && timer -> finish()) {
    //     if (customer -> getAttachment()) customer -> deattach();
    //     if (customer -> space) customer -> detachfromSpace();
    //     // return;
    // }
    return;
}

void CustomerState::displayDesire() {
    if (cd) cd -> display();
}

//virtual, young and old customer differentiate
CustomerState* CustomerState::getNextState(Customer* customer) {
    if (!valid) return this;
    // if (!(timer -> finish())) return this;s
    timer -> stop();
    CustomerState* temp = new CustomerState(++state, customer);
    return temp;
}

void CustomerState::action() {
    // if (timer && timer -> TimerisRunning()) {
    //     std::cout << "customer " << customer -> getID() << " is still running\n";
    // }
    // std::cout << state << std::endl;
    if (!valid) {
        if (customer -> getAttachment()) customer -> deattach();
        if (customer -> space) customer -> detachfromSpace();
        return;
    }
    // timer -> start();
    // else std::cout << customer -> space -> getPos().x << '\n';
    if (customer -> getAttachment()) customer -> getAttachment() -> display();
    customer -> display();
    handleRequest();
    // if (getState() == Customers::outdated) customer -> selfAssess();
    // display image;
    // customer -> setFile("little_chef_overcooked_like.glb");
    // customer -> setModel();
    
    // customer -> setAxis({0.0f, 0.0f, 1.0f});
    // customer -> setDirection(0.0f);
    // customer -> setPos({0.0f, 2.0f, 1.0f});
    // customer -> setScale({8.0f, 8.0f, 8.0f});
    
    // std::cerr << customer -> getPos().x << ',' << customer -> getPos().x << ',' << customer -> getPos().y << std::endl;
    // {
    //     if (state == 2) std::cout << "waiting" << '\n';
    //     if (state == 3) std::cout << "eating or not" << '\n';
    //     if (state == 4) std::cout << "invalid" << '\n';
    // }
    return;
}

bool CustomerState::isValid() {
    return valid;
}

int CustomerState::getTime(int state) {
    if (!valid) return 0;
    if (state == 2) return 30;
    if (state == 3) {
        if (customer -> getAttachment()) return 5;
        return 0;
    }
    return 0;
    // if state get this time
}

std::string CustomerState::getFile() {
    if (!valid) return "";
    return "";
    // return customer's thinking of food and gratitude: waiting long or not...
}

// get state function
bool CustomerState::interact() {
    if (!valid) return false;
    return (state == 2);
}

int CustomerState::getState() {
    return state;
}

YoungCustomerState* YoungCustomerState::getNextState(Customer* customer) {
    if (!valid) return this;
    // if (!(timer -> finish())) return this;s
    timer -> stop();
    YoungCustomerState* temp = new YoungCustomerState(++state, customer);
    return temp;
}

std::string YoungCustomerState::getFile() {
    return "3DGodotRobot.glb";
} 

int YoungCustomerState::getTime(int state) {
    if (!valid) return 0;
    if (state == 2) return 30;
    if (state == 3) {
        if (customer -> getAttachment()) return 10;
        return 0;
    }
    return 0;
}

std::string OldCustomerState::getFile() {
    return "customer.glb";
    // if (!valid) return "";
}

int OldCustomerState::getTime(int state) {
    if (!valid) return 0;
    if (state == 2) return 25;
    if (state == 3) {
        if (customer -> getAttachment()) return 15;
        return 0;
    }
    return 0;
}

OldCustomerState* OldCustomerState::getNextState(Customer* customer) {
    if (!valid) return this;
    // if (!(timer -> finish())) return this;s
    timer -> stop();
    OldCustomerState* temp = new OldCustomerState(++state, customer);
    return temp;
}

TakeawayCustomerState* TakeawayCustomerState::getNextState(Customer* customer) {
    if (!valid) return this;
    // if (!(timer -> finish())) return this;s
    timer -> stop();
    TakeawayCustomerState* temp = new TakeawayCustomerState(state + 2, customer);
    return temp;
}

std::string TakeawayCustomerState::getFile() {
    if (!valid) return "";
}

int TakeawayCustomerState::getTime(int state) {
    if (!valid) return 0;
    if (state == 2) return 40;
    // if (state == 3) {
    //     if (customer -> getAttachment()) return 15;
    //     return 0;
    // }
    return 0;
}
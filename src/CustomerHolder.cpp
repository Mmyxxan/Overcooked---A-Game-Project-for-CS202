#include <CustomerHolder.hpp>

void CustomerHolder::run() {
    for (int i = 0; i < num; i++) {
        if (p[i] -> getState() != State::outdated) p[i] -> status -> action();
    }
}

void CustomerHolder::init(MediatorChecker* mc, Map* map, PauseGame* pause) {
    for (int i = 0; i < num; i++) {
        p[i] = new Customer(curID); 
        p[i] -> setMediatorChecker(mc);
        p[i] -> registerArea(map);
        pause -> registerObject(p[i]);
        curID++;
    }
    for (int i = 0; i < num - 1; i++) {
        p[i] -> setNext(p[i + 1]);
    }
    head = p[0];
    // factory creates customers into pointer;
}

// holder adapter to particle;
// get and put it to tail
// enable change state, when enable change state is off, check what's outdated and filter it...

Customer* CustomerHolder::manage() {
    // bool inUse right in customer holder
    for (int i = 0; i < num; i++) {
        if (p[i] && p[i] -> inUse && p[i] -> getState() == Customers::outdated) {
            std::cout << "manage successfully" << std::endl;
            p[i] -> inUse = false;
            p[i] -> setNext(head);
            p[i] -> area -> resetArea();
            head = p[i];
            // return head;
        }
    }
    return head;
}

// if (head) donot manage();

Customer* CustomerHolder::get() {
    // manage before get
    // head -> setValid();
    manage();
    if (!head) return nullptr;
    Customer* temp = head;
    // if (temp && temp -> getState() == Customers::outdated) {
    temp -> bringIntoState();
    // setSampleFood
    // set young old state for customer
    head = head -> getNext();
    // }
    // manage();
    return temp;
}
#include <Manager.hpp>

void Manager::run() {
    ch -> run();
    th -> manage();
}

void Manager::init(ControllableObject* chef, Checker* c, Map* map, PauseGame* pause) {
    mc -> setChef(chef);
    mc -> setChecker(c);
    ch -> init(mc, map, pause);
    th -> init(map);
}

void Manager::assign() {
    mc -> notifyObjects();
    // table use a circular linked list
    // if strategy -> getNextCustomer != null
    // th -> get().receive(ch -> get());
    // not-full table is still set invalid to get.
    Table* tmp = th -> get();
    if (tmp && tmp -> receivable()) {
        Customer* temp = ch -> get();
        if (temp) tmp -> receive(temp);
    }
    
    return;
}
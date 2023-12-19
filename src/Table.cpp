#include <Table.hpp>

bool Table::receivable() {    
    Particle* p = sh -> manage();
    if (p && !p -> getAttachment()) {
        // std::cout << "receivable" << std::endl;
        return true;
    }
    // std::cout << "not receivable" << std::endl;
    return false;
}

void Table::setNext(Table* next) {
    this -> next = next;
}

Table* Table::getNext() {
    return next;
}

void Table::receive(Customer* c) {
    Particle* temp = sh -> get();
    if (!temp) return;
    temp -> attach(c);
    c -> assignSpace(temp);
    c -> area -> removeArea({c -> getPos().x - 2.0f, c -> getPos().y - 2.0f}, 4.0f, 4.0f);
    // c -> bringIntoState();
    // std::cout << "receive successfully" << '\n';
    return;
}
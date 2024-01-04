#include <TableHolder.hpp>

Table* TableHolder_3::get() {
    return t[0];
}

void TableHolder_2::manage() {
    for (int i = 0; i < num; i++) {
        // t[i] -> drawArea();
    }
}

void TableHolder::init(Map* map) {
    head = t[0];
    for (int i = 0; i < num; i++) t[i] -> registerArea(map);
    for (int i = 0; i < num - 1; i++) {
        t[i] -> setNext(t[i + 1]);
    }
    t[num - 1] -> setNext(t[0]);
    // for (int i = 0; i < num; i++) {

    // }
}

void TableHolder::manage() {
    for (int i = 0; i < num; i++) {
        t[i] -> display();
    }
}

Table* TableHolder::get() {
    // manage();
    // return nullptr;
    int getRand = rand() % 3;
    switch (getRand) {
        case 0: 
            return t[0];
            break;
        case 1:
            return t[1];
            break;
        case 2:
            return t[2];
            break;
        default:
            break;
    }
    return nullptr;
    // // return &t[1];
    // manage();
    // // head -> setValid();
    // // while (head == NULL) {
    // //     head = head -> getNext();
    // // }
    // Table* temp = nullptr;
    // // while (!(temp && temp -> receivable())) {
    // //     temp = head;
    // //     head = head -> getNext();
    // //     return temp;
    // // }
    // for (int i = 0; i < num; i++) {
    //     temp = head;
    //     head = head -> getNext();
    //     if (temp && temp -> receivable()) return temp;
    // }
    // return nullptr;
}
#pragma once
#ifndef TABLE_HPP
#define TABLE_HPP

#include "Object.hpp"
#include "Customer.hpp"
#include "SpaceHolder.hpp"

class Table : public Object
// , public Particle 
{
private:
    SpaceHolder* sh;
    Table* next;
    // adapter to particle
public:

    Table(int num, Vector3 position) : Object("table"), sh(NULL), next(NULL) {
        this -> position = position;
        setFile("table.glb");
        setModel();
        setAxis({1.0f, 0.0f, 0.0f});
        setDirection(90.0f);
        setScale({2.0f, 2.0f, 2.0f});
        area = new Area(200, 200, false);
        sh = new SpaceHolder(num, position);
        sh -> init();
    }
    Table(Vector3 position) : Object("table"), sh(NULL), next(NULL) {
        this -> position = position;
        setFile("table.glb");
        setModel();
        setAxis({1.0f, 0.0f, 0.0f});
        setDirection(90.0f);
        setScale({2.0f, 2.0f, 2.0f});
        area = new Area(200, 200, false);
        sh = new SpaceHolder(1, position);
        sh -> init();
    }
    Table() : Object("table"), sh(NULL), next(NULL) {
        // this -> position = position;
        // sh = new SpaceHolder(1, position);
        // sh -> init();
    }
    // void manage();
    bool receivable();
    void setNext(Table* next);
    Table* getNext();
    void receive(Customer* c); // or table holder?
    // init table space, set space, lot of space;
};


#endif
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
    Table(Vector3 position, int i) : Object("table"), sh(NULL), next(NULL) {
        this -> position = position;
        setFile("table.glb");
        setModel();
        setAxis({1.0f, 0.0f, 0.0f});
        setDirection(90.0f);
        setScale({2.0f, 2.0f, 2.0f});
        area = new Area(200, 200, false);
        sh = new SpaceHolder(1, Vector3Add(position, {0.0f, -2.0f, -4.0f}));
        sh -> init();
    }
    Table(Vector3 position, float i) : Object("table"), sh(NULL), next(NULL) {
        this -> position = position;
        setFile("table.glb");
        setModel();
        setAxis({1.0f, 0.0f, 0.0f});
        setDirection(90.0f);
        setScale({2.0f, 2.0f, 2.0f});
        area = new Area(200, 200, false);
        sh = new SpaceHolder(1, Vector3Add(position, {0.0f, 0.0f, 0.0f}));
        sh -> init();
    }
    Table() : Object("table"), sh(NULL), next(NULL) {
        // this -> position = position;
        // sh = new SpaceHolder(1, position);
        // sh -> init();
    }
    // void manage();
    void drawArea();
    bool receivable();
    void setNext(Table* next);
    Table* getNext();
    void receive(Customer* c); // or table holder?
    // init table space, set space, lot of space;
};

class Table_2 : public Table {
public:
    Table_2(Vector3 position) : Table(position, 2) {}
};

class Table_3 : public Table {
public:
    Table_3(Vector3 position) : Table(position, 3.0f) {}
};


#endif
#pragma once
#ifndef TABLEHOLDER_HPP
#define TABLEHOLDER_HPP

#include "Libraries.hpp"
#include "Table.hpp"
#include "Map.hpp"

class TableHolder {
protected:
    Table** t;
    int num;
    Table* head;
public:
    TableHolder(float i) : num(1), t(NULL), head(NULL) {
        t = new Table*[num];
        t[0] = new Table_3({0.3f, -12.0f, -6.0f});
        for (int i = 0; i < num; i++) {
            t[i] -> removeArea({t[i] -> getPos().x -3.0f, t[i] -> getPos().y - 3.0f}, 6.0f, 6.0f);
        }
    }
    TableHolder(int i) : num(3), t(NULL), head(NULL) {
        t = new Table*[num];
        t[0] = new Table_2({-8.0f, -10.0f, -1.0f});
        t[1] = new Table_2({4.0f, -10.0f, -1.0f});
        t[2] = new Table_2({16.0f, -10.0f, -1.0f}); // should bring to init
        for (int i = 0; i < num; i++) {
            t[i] -> removeArea({t[i] -> getPos().x -3.0f, t[i] -> getPos().y - 3.0f}, 6.0f, 6.0f);
        }
    }
    TableHolder() : num(3), t(NULL), head(NULL) {
        t = new Table*[num];
        t[0] = new Table({-10.0f, -13.0f, -1.0f});
        t[1] = new Table({-2.0f, -15.0f, -1.0f});
        t[2] = new Table({6.0f, -13.0f, -1.0f}); // should bring to init
        for (int i = 0; i < num; i++) {
            t[i] -> removeArea({t[i] -> getPos().x -3.0f, t[i] -> getPos().y - 3.0f}, 6.0f, 6.0f);
        }
    }
    // TableHolder(int num) : num(num), t(NULL), head(NULL) {
    //     t = new Table[num];
    // }
    void init(Map* map);
    virtual void manage();
    virtual Table* get();
    // almost done
    // pos of table 1, table 2, ...
}; // load from file

class TableHolder_2 : public TableHolder {
public:
    TableHolder_2() : TableHolder(2) {}
    void manage();
};

class TableHolder_3 : public TableHolder {
public:
    TableHolder_3() : TableHolder(3.0f) {};
    void manage() {}
    Table* get();
};

#endif
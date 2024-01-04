#pragma once
#include "Libraries.hpp"
#include "Mediator.hpp"
#include "Food.hpp"
#include "State.hpp"
#include "FoodIterator.hpp"

class KitchenState;

class Storer : public Object {
protected:
    FoodIterator* fi;
    KitchenState* ks;
    Food* food;
    std::string food_description;
    Mediator* m;
    int state;
public:
    Storer() : Object("storer"), state(0), m(NULL), food(NULL), food_description(""), ks(NULL), fi(NULL) {
        // fi = new FoodIterator();
        // fi -> init();
        area = new Area(200, 200, false);
        init();
    }
    Storer(std::string food_description) : Object("storer"), state(0), m(NULL), food(NULL), food_description(food_description), ks(NULL), fi(NULL) {
        if (food_description != "trash" && food_description != "trash2" && food_description != "trash3") {
            fi = new FoodIterator();
            fi -> init();
        }
        area = new Area(200, 200, false);
        init();
    }
    void displayFoodList();
    std::string getFile();
    virtual KitchenState* loadState(std::ifstream &in, KitchenState* &ks);
    virtual void init();
    void setMediator(Mediator* m);
    void display();
    void update(float x, float y);
    void update(char key);
    bool isInArea(float x, float y);
    virtual void Process();
};

class Storer_2 : public Storer {
public:
    Storer_2(std::string food_description) : Storer(food_description) {}
    void init();
};

class TrashBin : public Storer {
private:
public:
    TrashBin() : Storer("trash") {}
    TrashBin(std::string description) : Storer(description) {}
    void Process();
};

class TrashBin_2 : public TrashBin {
private:
public:
    TrashBin_2() : TrashBin("trash2") {}
};

class TrashBin_3 : public TrashBin {
public:
    TrashBin_3() : TrashBin("trash3") {}
};

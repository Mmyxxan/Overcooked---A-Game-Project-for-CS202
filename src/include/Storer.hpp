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
        fi = new FoodIterator();
        fi -> init();
        area = new Area(200, 200, false);
        init();
    }
    Storer(std::string food_description) : Object("storer"), state(0), m(NULL), food(NULL), food_description(food_description), ks(NULL), fi(NULL) {
        fi = new FoodIterator();
        fi -> init();
        area = new Area(200, 200, false);
        init();
    }
    std::string getFile();
    KitchenState* loadState(std::ifstream &in, KitchenState* &ks);
    void init();
    void setMediator(Mediator* m);
    void display();
    void update(float x, float y);
    void update(char key);
    bool isInArea(float x, float y);
    virtual void Process();
};

class TrashBin : public Storer {
private:
public:
    TrashBin() : Storer("trash") {}
    void Process();
};


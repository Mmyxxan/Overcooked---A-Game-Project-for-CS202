#include <StorageHolder.hpp>

void StorageHolder_3::init() {
    o[0] = new Storer_2("dough2");
    o[1] = new TrashBin_3();

    o[0] -> removeArea({20.0f, 8.0f}, 7.0f, 7.0f);
    o[1] -> removeArea({12.0f, -10.0f}, 7.0f, 7.0f);
}

void StorageHolder_3::run() {
    // o[0] -> drawArea();
    // o[1] -> drawArea();
    o[0] -> display();
}

void StorageHolder_2::init() {
    o[0] = new Storer("dough");
    o[1] = new TrashBin_2();

    o[0] -> removeArea({16.0f, 7.5f}, 4.0f, 4.0f);
    o[1] -> removeArea({-2.0f, 2.5f}, 6.0f, 7.0f);
}

void StorageHolder_2::run() {
    // o[0] -> drawArea();
    // o[1] -> drawArea();
}

void StorageHolder::init() {
    // create
    o[0] = new Storer("dough");
    o[1] = new TrashBin();

    // set information
    o[0] -> setFile("fridge1.glb");
    o[0] -> setModel();

    o[1] -> setFile("trash.glb");
    o[1] -> setModel();

    // o[1] -> rotate(Axis::y, PI/2);
    // o[1] -> rotate(Axis::x, -PI/2);
    // o[1] -> rotate(Axis::y, PI/2);
    // o[1] -> rotate(Axis::x, -PI/2);

    o[0] -> setAxis({1.0f, 0.0f, 0.0f});
    o[0] -> setDirection(90.0f);
    o[0] -> setPos({-7.0f, -4.0f, 4.0f});
    o[0] -> setScale({2.7f, 2.7f, 2.7f});
    o[0] -> removeArea({o[0] -> getPos().x - 4.0f, o[0] -> getPos().y - 1.0f}, 6.0f, 7.0f);

    o[1] -> setAxis({0.0f, 0.0f, 1.0f});
    o[1] -> setDirection(0.0f);
    o[1] -> setPos({-1.0f, -1.5f, 3.0f});
    o[1] -> setScale({2.3f, 1.5f, 2.3f});
    o[1] -> removeArea({o[0] -> getPos().x - 1.0f, o[0] -> getPos().y - 3.0f}, 6.0f, 7.0f);

}

void StorageHolder::setMediator(Mediator* m, Map* map) {
    for (int i = 0; i < num; i++) {
        if (o[i]) {
            o[i] -> setMediator(m);
            o[i] -> registerArea(map);
        }
    }
}

void StorageHolder::run() {
    for (int i = 0; i < num; i++) {
        if (o[i]) o[i] -> display();
    }
}
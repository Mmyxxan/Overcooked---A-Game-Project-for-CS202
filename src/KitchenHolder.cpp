#include <KitchenHolder.hpp>

void KitchenHolder::init() {
    // create
    o[0] = new Cooker("baked");

    // set information
    o[0] -> setFile("oven.glb");
    o[0] -> setModel();
    o[0] -> setAxis({0.0f, 0.0f, 1.0f});
    o[0] -> setDirection(0.0f);
    o[0] -> setPos({8.0f, 0.0f, 5.0f});
    o[0] -> setScale({1.5f, 1.5f, 1.5f});
    o[0] -> removeArea({o[0] -> getPos().x - 0.5f, o[0] -> getPos().y + 2.0f}, 4.0f, 8.0f);

    o[1] = new Cooker("baked");

    // set information
    o[1] -> setFile("oven.glb");
    o[1] -> setModel();
    o[1] -> setAxis({0.0f, 0.0f, 1.0f});
    o[1] -> setDirection(0.0f);
    o[1] -> setPos({12.0f, 0.0f, 5.0f});
    o[1] -> setScale({1.5f, 1.5f, 1.5f});
    o[1] -> removeArea({o[1] -> getPos().x - 0.5f, o[1] -> getPos().y + 2.0f}, 4.0f, 8.0f);
}

void KitchenHolder::setMediator(Mediator* m, Map* map, PauseGame* pause) {
    for (int i = 0; i < num; i++) {
        if (o[i]) {
            o[i] -> setMediator(m);
            o[i] -> registerArea(map);
            // o[i] -> registerPause(pause);
            pause -> registerObject(o[i]);
        }
    }
}

void KitchenHolder::run() {
    for (int i = 0; i < num; i++) {
        if (o[i]) o[i] -> display();
    }
}
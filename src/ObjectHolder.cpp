#include <ObjectHolder.hpp>

void ObjectHolder_3::init(Map* map) {
    obj[0] = new Object("map3.glb", {-5.0f, 12.0f, -15.0f}, Axis::Oz, 180.0f, {2.7f, 2.7f, 2.7f});
    // obj[1] = new Object("map3.glb", {-5.0f, 12.0f, -12.0f}, Axis::Oz, 180.0f, {4.0f, 4.0f, 4.0f});

    for (int i = 0; i < num; i++) {
        if (obj[i]) obj[i] -> setModel();
    }

    for (int i = 0; i < num; i++) {
        if (obj[i]) {
            obj[i] -> registerArea(map);
        }
    }
}

void ObjectHolder_2::init(Map* map) {
    obj[0] = new Object("MA_map2.glb", {0.0f, 10.0f, -7.0f}, Axis::Ox, 90.0f, {2.0f, 2.0f, 2.0f});

    for (int i = 0; i < num; i++) {
        if (obj[i]) obj[i] -> setModel();
    }

    for (int i = 0; i < num; i++) {
        if (obj[i]) {
            obj[i] -> registerArea(map);
        }
    }
}

void ObjectHolder::init(Map* map) {
    // create
    for (int i = 0; i < 5; i++) {
        obj[i] = new Object("overwindow.glb", {-14.0f, 6.0f - (float) (i * 6), 0.0f}, Axis::Oy, 0.0f, {1.5f, 1.5f, 1.5f});
    }
    obj[5] = new Object("kitchentable.glb", {11.0f, 5.0f, 0.0f}, Axis::Oz, 90.0f, {2.5f, 4.0f, 2.5f});
    for (int i = 6; i < 11; i++) {
        obj[i] = new Object("wall.glb", {-47.5f + (float) (i * 6), 9.0f, 0.0f}, Axis::Oz, 90.0f, {1.5f, 1.5f, 1.5f});
    }
    obj[11] = new Object("deco1.glb", {4.4f, 5.0f, 0.0f}, Axis::Oz, 90.0f, {2.5f, 2.5f, 2.5f});
    obj[12] = new Object("extractor.glb", {7.0f, 1.0f, 6.0f}, Axis::Oz, 90.0f, {1.5f, 1.5f, 1.5f});
    
    obj[13] = new Object("extractor.glb", {11.0f, 1.0f, 6.0f}, Axis::Oz, 90.0f, {1.5f, 1.5f, 1.5f});
    obj[14] = new Object("decorated.glb", {15.0f, -17.0f, 0.0f}, Axis::Oz, 0.0f, {2.0f, 2.0f, 2.0f});
    obj[15] = new Object("cabinet.glb", {14.0f, -10.0f, -2.0f}, Axis::Oz, 0.0f, {3.0f, 3.0f, 3.0f});
    
    // chef remove area and ismovable&&isinarea
    // obj[0] = new Object("overwindow.glb", {-14.0f, -2.0f, 0.0f}, Axis::Oy, 0.0f, {2.0f, 2.0f, 2.0f});

    // obj[1] = new Object("overwindow.glb", {-14.0f, 6.0f, 0.0f}, Axis::Oy, 0.0f, {2.0f, 2.0f, 2.0f});

    // obj[2] = new Object("overcooked2.glb", {0.0f, 0.0f, 0.0f}, Axis::Ox, 0.0f, {0.05f, 0.05f, 0.05f}); 

    // set model
    for (int i = 0; i < num; i++) {
        if (obj[i]) obj[i] -> setModel();
    }
    // obj[0] -> rotate(Axis::y, PI/2);
    // obj[0] -> rotate(Axis::x, -PI/2);
    // obj[0] -> rotate(Axis::y, PI/2);
    // obj[0] -> rotate(Axis::x, -PI/2);
    
    // obj[5] -> rotate(Axis::y, PI/2);
    // obj[5] -> rotate(Axis::x, -PI/2);
    // obj[5] -> rotate(Axis::y, PI/2);
    // obj[5] -> rotate(Axis::x, -PI/2);

    // obj[6] -> rotate(Axis::y, PI/2);
    // obj[6] -> rotate(Axis::x, -PI/2);
    // obj[6] -> rotate(Axis::y, PI/2);
    // obj[6] -> rotate(Axis::x, -PI/2);

    // obj[11] -> rotate(Axis::y, PI/2);
    // obj[11] -> rotate(Axis::x, -PI/2);
    // obj[11] -> rotate(Axis::y, PI/2);
    // obj[11] -> rotate(Axis::x, -PI/2);

    // obj[12] -> rotate(Axis::y, PI/2);
    // obj[12] -> rotate(Axis::x, -PI/2);
    // obj[12] -> rotate(Axis::y, PI/2);
    // obj[12] -> rotate(Axis::x, -PI/2);

    // obj[14] -> rotate(Axis::y, PI/2);
    // obj[14] -> rotate(Axis::x, -PI/2);
    // obj[14] -> rotate(Axis::y, PI/2);
    // obj[14] -> rotate(Axis::x, -PI/2);

    // obj[15] -> rotate(Axis::y, PI/2);
    // obj[15] -> rotate(Axis::x, -PI/2);
    // obj[15] -> rotate(Axis::y, PI/2);
    // obj[15] -> rotate(Axis::x, -PI/2);
    
    // obj[0] -> setModel();
    // obj[0] -> rotate(Axis::y, PI/2);
    // obj[0] -> rotate(Axis::x, -PI/2);

    // obj[1] -> setModel();
    // obj[1] -> rotate(Axis::y, PI/2);
    // obj[1] -> rotate(Axis::x, -PI/2);

    // obj[2] -> setModel();

    // remove area
    for (int i = 0; i < num; i++) {
        // if (obj[i]) obj[i] -> removeArea({obj[i] -> getPos().x - 3.0f, obj[i] -> getPos().y - 4.0f}, 4.0f, 7.5f);
    }

    // register area
    for (int i = 0; i < num; i++) {
        if (obj[i]) {
            obj[i] -> registerArea(map);
        }
    }
}
void ObjectHolder::run() {
    for (int i = 0; i < num; i++) {
        if (obj[i]) obj[i] -> display();
    }
}
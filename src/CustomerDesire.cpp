#include <CustomerDesire.hpp>

void CustomerEating::setUp() {
    frame = TextureFactory::getTextureFactory() -> getTexture("eating.png");
}

void CustomerEating::display() {
    EndMode3D();
    DrawTexture(*frame, 0, 0, WHITE);
    if (timer) {
        int _m = timer -> getMinute();
        int _s = timer -> getSecond();
        for (int i = 0; i < 2; i++) if (draw[i]) delete draw[i];
        draw[0] = new DrawNumber(277, 130, 50, 40, timer -> getMinute());
        draw[1] = new DrawNumber(345, 130, 50, 40, timer -> getSecond());
    }
    for (int i = 0; i < 2; i++) if (draw[i]) draw[i] -> draw();
    BeginMode3D(*CameraGame::getCamera());
}

void CustomerWaiting::setUp() {
    // std::string file = food -> getDescription() + ".png";
    // frame = TextureFactory::getTextureFactory() -> getTexture(file);
    frame = TextureFactory::getTextureFactory() -> getTexture("waiting.png");
}

void CustomerWaiting::display() {
    EndMode3D();
    DrawTexture(*frame, 0, 0, WHITE);
    if (timer) {
        int _m = timer -> getMinute();
        int _s = timer -> getSecond();
        for (int i = 0; i < 2; i++) if (draw[i]) delete draw[i];
        draw[0] = new DrawNumber(277, 130, 50, 40, timer -> getMinute());
        draw[1] = new DrawNumber(345, 130, 50, 40, timer -> getSecond());
    }
    for (int i = 0; i < 2; i++) if (draw[i]) draw[i] -> draw();
    BeginMode3D(*CameraGame::getCamera());
    // draw text minute and second remaining
}

void CustomerOrder::setUp() {
    food3d = ModelFactory::getModelFactory() -> getModel(food -> getFile());
}

void CustomerOrder::display() {
    // std::cout << "customer order display\n";
    if (!food3d) return;
    DrawModelEx(*food3d, pos, Axis::Ox, -90.0f, {0.02f, 0.02f, 0.02f}, WHITE);
}
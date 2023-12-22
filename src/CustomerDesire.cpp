#include <CustomerDesire.hpp>

void CustomerWaiting::setUp() {
    std::string file = food -> getDescription() + ".png";
    frame = TextureFactory::getTextureFactory() -> getTexture(file);
}

void CustomerWaiting::display() {
    DrawTexture(*frame, 0, 0, WHITE);
    if (timer) {
        int _m = timer -> getMinute();
        int _s = timer -> getSecond();
    }
    // draw text minute and second remaining
}

void CustomerOrder::setUp() {
    food3d = ModelFactory::getModelFactory() -> getModel(food -> getFile());
}

void CustomerOrder::display() {
    // std::cout << "customer order display\n";
    if (!food3d) return;
    DrawModelEx(*food3d, pos, Axis::Ox, 0.0f, {0.02f, 0.02f, 0.02f}, WHITE);
}
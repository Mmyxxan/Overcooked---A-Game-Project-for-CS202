#include <CustomerDesire.hpp>

void CustomerOrder::setUp() {
    food3d = ModelFactory::getModelFactory() -> getModel(food -> getFile());
}

void CustomerOrder::display() {
    // std::cout << "customer order display\n";
    if (!food3d) return;
    DrawModelEx(*food3d, pos, Axis::Ox, 0.0f, {0.02f, 0.02f, 0.02f}, WHITE);
}
#include <Food.hpp>
#include <State.hpp>

std::set<std::string> Food::getSet() {
    if (!o) return food_set;
    // std::cerr << description + o -> getDescription() << '\n';
    std::set<std::string> temp = o -> getSet();
    temp.insert(description);
    return temp;
}

void Food::init() {
    if (!o || (o && o -> description == "food")) {
        state = new MotionlessState(getDescription(), getSet());
    }
    else state = new MotionlessState("cannotwrap", {}); // spoiled
    // all first rotate in model factory;
    setModel();
    setAxis({0.0f, 0.0f, 1.0f});
    setDirection(0.0f);
    if (o) setPos(o -> getPos());
    setScale({0.02f, 0.02f, 0.02f});
}

void Food::display() {
    // state -> action();
    DrawModelEx(*model, position, axis, direction, scale, WHITE);
    // DrawModelEx(model, {position.x + 5.0f, position.y, position.z}, axis, direction, scale, WHITE);
    // std::cout << file << '\n';
}

std::string Food::getFile() {
    return state -> getFile();
}

void Food::setDescription() {
    if (!f) return;
    this -> description += f -> getDescription();
}

std::string Food::getDescription() {
    if (!o) return description;
    // std::cerr << description + o -> getDescription() << '\n';
    return description + o -> getDescription();
}

bool SampleFood::assess(Object* o) {
    std::cout << o -> getDescription() << " " << this -> getDescription() << '\n';
    return (o -> getDescription() == this -> getDescription());
    // return (o -> getSet() == this -> getSet());
}

bool SampleFood::assess(Food* f) {
    return (f -> getDescription() == this -> getDescription());
    // return (f -> getSet() == this -> getSet());
}

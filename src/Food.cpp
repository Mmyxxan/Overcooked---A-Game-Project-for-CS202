#include <Food.hpp>

DisplayFactory* DisplayFactory::df = NULL;

std::string DisplayFactory::getFile(std::string description) {
    if (description == "cookerwrapperonion") return "onioncookerwrapper.glb";
    return "kirby.glb";
}

void MotionlessState::action() {
    std::cerr << "food display: ";
    std::cerr << description << '\n';
}

std::string MotionlessState::getFile() {
    return df -> getFile(description);
}

void Food::display() {
    state -> action();
    // DrawModelEx(model, position, axis, direction, scale, WHITE);
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
    return (o -> getDescription() == this -> getDescription());
}

bool SampleFood::assess(Food* f) {
    return (f -> getDescription() == this -> getDescription());
}

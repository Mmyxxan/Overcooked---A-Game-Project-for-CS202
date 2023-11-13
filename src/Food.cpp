#include <Food.hpp>

DisplayFactory* DisplayFactory::df = NULL;

std::string DisplayFactory::getFile(std::string description) {
    if (description == "knifecookerwrapper") return "cooker.glb";
    return "kirby.glb";
}

std::string MotionlessState::getFile() {
    return df -> getFile(description);
}

// void Food::display() {
//     state -> action();
// }

std::string Food::getFile() {
    return state -> getFile();
}

void Food::setDescription() {
    if (!f) return;
    this -> description += f -> getDescription();
}

std::string Food::getDescription() {
    return description;
}

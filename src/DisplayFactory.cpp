#include <DisplayFactory.hpp>

DisplayFactory* DisplayFactory::df = NULL;

std::string DisplayFactory::getFile(std::string description) {
    // return description + ".glb";
    // std::cout << description << '\n';
    // if (description == "cookerwrapperonion") return "onioncookerwrapper.glb";
    if (description == "dough") return "dough.glb";
    if (description == "bakeddough") return "base.glb";
    if (description == "onionbakeddough") {
        return description + ".glb";
    }
    if (description == "pepperonibakeddough") {
        return description + ".glb";
    }
    if (description == "sausagebakeddough") {
        return description + ".glb";
    }
    sort(description.begin(), description.end());
    std::string temp = "pepperonionionbakeddough";
    sort(temp.begin(), temp.end());
    if (description == temp) {
        return "pepperonionionbakeddough.glb";
    }
    temp = "oniontomatobakeddough";
    sort(temp.begin(), temp.end());
    if (description == temp) {
        return "oniontomatobakeddough.glb";
    }
    // if (description == "cookerwrapperdough") return "kirby.glb";
    // if (description == "cookerwrappercookerwrapperdough") return "knife.glb";
    return "kirby.glb";
}
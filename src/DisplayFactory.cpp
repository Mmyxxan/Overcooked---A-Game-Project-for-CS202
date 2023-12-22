#include <DisplayFactory.hpp>

DisplayFactory* DisplayFactory::df = NULL;

std::string DisplayFactory::getFile(std::string description) {
    // return description + ".glb";
    std::cout << description << '\n';
    if (description == "cookerwrapperonion") return "onioncookerwrapper.glb";
    if (description == "dough") return "base.glb";
    if (description == "cookerwrapperdough") return "kirby.glb";
    if (description == "cookerwrappercookerwrapperdough") return "knife.glb";
    return "kirby.glb";
}
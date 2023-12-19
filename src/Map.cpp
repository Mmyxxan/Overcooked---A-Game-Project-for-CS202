#include <Map.hpp>

void Map::registerArea(Area* area) {
    areas[cur] = area;
    cur++;   
}

bool Map::Movable(float x, float y, Area* area) {
    for (int i = 0; i < num; i++) {
        if (areas[i] && !areas[i] -> isMovable(x, y) && area != areas[i]) return false;
    }
    return true;
}
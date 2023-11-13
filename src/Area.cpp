#include <Area.hpp>

bool Area::isInArea(float cx, float cy) {
    return cell[(int) (cx + BIAS)][(int) (cy + BIAS)];
}

// mediator interactive objects & controllable, remove the proper area for each object when initialized 
void Area::removeArea(Vector2 root, float height, float width) {
    for (int i = (int) (root.x + BIAS); i <= (int) (root.x + height + BIAS); i++) {
        for (int j = (int) (root.y + BIAS); j <= (int) (root.y + width + BIAS); j++) cell[i][j] = !isControllable;
    }
}
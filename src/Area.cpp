#include <Area.hpp>

// void Area::registerArea(Map* map) {
//     return;
// }

void Area::resetArea() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) cell[i][j] = isControllable;
    }
    return;
}

bool Area::isInArea(float cx, float cy) {
    return cell[(int) (cx + BIAS)][(int) (cy + BIAS)];
}

// mediator interactive objects & controllable, remove the proper area for each object when initialized 
void Area::removeArea(Vector2 root, float height, float width) {
    for (int i = (int) (root.x + BIAS); i <= (int) (root.x + height + BIAS); i++) {
        for (int j = (int) (root.y + BIAS); j <= (int) (root.y + width + BIAS); j++) cell[i][j] = !isControllable;
    }
}

void Area::drawArea() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (cell[i][j] == !isControllable) DrawCube({(float) i - BIAS, (float) j - BIAS, -4.0f}, 1.0f, 1.0f, 1.0f, BLACK);
        }
    }
}

bool Area::isMovable(float cx, float cy) {
    if (!cell[(int) (cx + BIAS)][(int) (cy + BIAS)]) return true;
    if (cell[(int) (cx + BIAS)][(int) (cy + BIAS) - 1] && cell[(int) (cx + BIAS)][(int) (cy + BIAS) + 1] && cell[(int) (cx + BIAS) + 1][(int) (cy + BIAS)] && cell[(int) (cx + BIAS) - 1][(int) (cy + BIAS)]) return false;
    return true;
}
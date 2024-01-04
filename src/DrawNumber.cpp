#include <DrawNumber.hpp>

void DrawScore::draw() {
    if (text.size()) {
        DrawTextEx(SharedResources::getResources() -> getCustomerFont(), text.c_str(), GetCenterPos(SharedResources::getResources() -> getCustomerFont(), text, fontSize, spacing, frame), fontSize, spacing, color);
    }
    else DrawTextEx(SharedResources::getResources() -> getCustomerFont(), "0", GetCenterPos(SharedResources::getResources() -> getCustomerFont(), "0", fontSize, spacing, frame), fontSize, spacing, color);
}

Vector2 DrawNumber::GetCenterPos(Font font, std::string text, float fontSize, float spacing, float x, float y, float width, float height) {
	Vector2 centerPos;
	centerPos.x = x + (width - MeasureTextEx(font, text.c_str(), fontSize, spacing).x) / 2;
	centerPos.y = y + (height - MeasureTextEx(font, text.c_str(), fontSize, spacing).y) / 2;
	return centerPos;
}

Vector2 DrawNumber::GetCenterPos(Font font, std::string text, float fontSize, float spacing, Rectangle rect) {
	return GetCenterPos(font, text, fontSize, spacing, rect.x, rect.y, rect.width, rect.height);
}

void DrawNumber::init(int number) {
    if (!number) return;
    init(number / 10);
    text += (number % 10 + '0');
}

void DrawNumber::draw() {
    if (text.size()) {
        DrawTextEx(SharedResources::getResources() -> getCustomerFont(), text.c_str(), GetCenterPos(SharedResources::getResources() -> getCustomerFont(), text, 60, 5, frame), 60, 5, PINK);
    }
    else DrawTextEx(SharedResources::getResources() -> getCustomerFont(), "0", GetCenterPos(SharedResources::getResources() -> getCustomerFont(), "0", 60, 5, frame), 60, 5, PINK);
}
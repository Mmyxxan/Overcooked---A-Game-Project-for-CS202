#include <Button.hpp>

// naked objects

void FirstMap::trigger() {
    
}

void ExitButton::trigger() {
    
}

void SettingButton::display() {
    if (GameAudio::getAudio() -> isBeingPaused()) state = 1;
    if (state) texture = TextureFactory::getTextureFactory() -> getTexture("off.png");
    else texture = TextureFactory::getTextureFactory() -> getTexture("on.png");
    setTexture();
    if (button) {
        // if (description == "checker") std::cout << "drawing checker\n";
        DrawTextureEx(*button, position, 0.0f, 1.0f, color);
    }
    if (texture) DrawTextureEx(*texture, position, 0.0f, 1.0f, WHITE);
}

void SettingButton::trigger() {
    state ^= 1;
    GameAudio::getAudio() -> togglePause();
    if (state) texture = TextureFactory::getTextureFactory() -> getTexture("off.png");
    else texture = TextureFactory::getTextureFactory() -> getTexture("on.png");
}

// void StartButton::display() {
//     std::cout << Button::getFile() << '\n';
// }

void StartButton::trigger() {
    
}

void SelectedButton::trigger() {
    // set next screen?
}

void SelectedButton::update(bool isSelected) {
    this -> isSelected = isSelected;
}

// void SelectedButton::deselect() {
//     isSelected = false;
// }

// void SelectedButton::select() {
//     isSelected = true;
// }

bool SelectedButton::Selected() {
    return isSelected;
}

std::string SelectedButton::getDescription() {
    if (Selected()) return "selected" + description;
    return description;
}

int Button::getNum() {
    return num;
}

void Button::setNum(int num) {
    this -> num = num;
}

void Button::setPos(Vector2 position) {
    this -> position = position;
}

void Button::trigger() {

}

bool Button::Selected() {
    return false;
}

void Button::update(bool isSelected) {

}

std::string Button::getDescription() {
    return description;
}

std::string Button::getFile() {
    // is it virtual?
    return getDescription() + ".png";
}

void Button::display() {
    setTexture();
    if (button) {
        // if (description == "checker") std::cout << "drawing checker\n";
        DrawTextureEx(*button, position, 0.0f, 1.0f, color);
    }
}

void Button::setTexture() {
    button = TextureFactory::getTextureFactory() -> getTexture(getFile());
}
#include <GameInstruction.hpp>

// pause -> instruction -> depause and let user play

void Content::setDescription(std::string description) {
    this -> description = description;
}

std::string Content::getDescription() {
    return description;
}

void GameInstruction::setContent(Content* content) {
    this -> content = content;
}

void  GameInstruction::changeContent() {
    //
}

Content*  GameInstruction::getContent() {
    return content;
}

void GameInstruction::auto_display() {

}

void GameInstruction::display(bool isTriggered) {
    // display on frame, frame == 0 end;
}
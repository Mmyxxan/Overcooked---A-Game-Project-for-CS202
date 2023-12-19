#include <Checker.hpp>
#include <Level.hpp>

// model pool object

// attachment is like stack?

// add more ingredients to object in cooker, more wrapper, same timer.

// space will based on the position of table, or can be loaded from file.

// void manage() {

// }

void Checker::pause() {
    if (timer) timer -> togglePause();
}

void Checker::reset() {
    score = 0;
}

// state display of storer, display food list and iterator pattern to choose

void Checker::start() {
    if (timer) delete timer;
    timer = new Timer(0, Level::getTime());
    timer -> start();
}

void Checker::manage() {
    // std::cout << "checker is processing\n";
    if (!isTimeleft()) timer -> stop();
}

bool Checker::isTimeleft() {
    return !timer || !(timer -> finish());
}

void Checker::update(const std::string description) {
    if (description == "right") {
        score += 50;
        std::cout << score << std::endl;
    }
}
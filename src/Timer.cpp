#include <Timer.hpp>

bool Timer::finish() {
    return (!_minute && !_second && !isPaused);
}

int Timer::getMinute() {
    return _minute;
}

int Timer::getSecond() {
    return _second;
}

void Timer::start() {
    if (isRunning.load()) {
        timerThread = new std::thread([this] { countdown(); });
    }
}

void Timer::togglePause() {
    isPaused ^= 1;
}

int Timer::getTimePaused() {
    if (isPaused) return 2;
    return 1;
}

void Timer::pause() {
    while (isPaused) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}

bool Timer::isStopped() {
    return (_minute == -1 && _second == -1);
}

bool Timer::TimerisRunning() {
    return isRunning.load();
}

void Timer::stop() {
    if (isRunning.load()) {
        isRunning.store(false);
        if (timerThread -> joinable()) {
            timerThread -> join();
            // _minute = -1;
            // _second = -1;
        }
    }
}
void Timer::countdown() {
    auto startTime = std::chrono::high_resolution_clock::now();
    auto endTime = startTime + std::chrono::seconds(totalSeconds);

    while (isRunning.load() && std::chrono::high_resolution_clock::now() < endTime) {
        while (isPaused) {
            endTime = endTime + std::chrono::seconds(1);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        int remainingSeconds = std::chrono::duration_cast<std::chrono::seconds>(endTime - std::chrono::high_resolution_clock::now()).count();
        _minute = remainingSeconds / 60;
        _second = remainingSeconds % 60;
        std::cout << "Time remaining: " << _minute << " minutes " << _second << " seconds\r";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // while (isPaused && ( _minute > 0 || _second > 1)) {
        // std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Time's up!" << std::endl;
}
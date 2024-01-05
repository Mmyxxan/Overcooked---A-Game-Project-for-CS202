#include <GameAudio.hpp>

GameAudio* GameAudio::audio = nullptr;

void GameAudio::musicThreadFunction() {
    while (!stopThread) {
        std::lock_guard<std::mutex> lock(audioMutex);
        UpdateMusicStream(*music);
        timePlayed = GetMusicTimePlayed(*music) / GetMusicTimeLength(*music);
        if (timePlayed > 1.0f) timePlayed = 1.0f;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));  // Adjust sleep duration as needed
    }
}

void GameAudio::play() {
    UpdateMusicStream(*music);

    timePlayed = GetMusicTimePlayed(*music)/GetMusicTimeLength(*music);

    if (timePlayed > 1.0f) timePlayed = 1.0f;
}

void GameAudio::restart() {
    StopMusicStream(*music);
    PlayMusicStream(*music);
}

void GameAudio::togglePause() {
    isPaused = !isPaused;
    if (isPaused) PauseMusicStream(*music);
    else ResumeMusicStream(*music);
}
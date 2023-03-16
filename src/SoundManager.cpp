#include "SoundManager.h"

SoundManager::SoundManager() {
    // Initialize SDL_mixer library
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

SoundManager::~SoundManager() {
    // Free all loaded sounds
    for (auto const& sound : sounds) {
        Mix_FreeChunk(sound.second);
    }
    // Quit SDL_mixer library
    Mix_CloseAudio();
}

bool SoundManager::loadSound(std::string filepath, std::string name) {
    // Load sound file and add to map
    Mix_Chunk* sound = Mix_LoadWAV(filepath.c_str());
    if (sound == NULL) {
        printf("Failed to load sound file %s! SDL_mixer Error: %s\n", filepath.c_str(), Mix_GetError());
        return false;
    }
    sounds.insert(std::pair<std::string, Mix_Chunk*>(name, sound));
    return true;
}

void SoundManager::playSound(std::string name) {
    // Play sound with given name
    Mix_PlayChannel(-1, sounds[name], 0);
}

void SoundManager::stopSound(std::string name) {
    // Stop playing sound with given name
    Mix_HaltChannel(-1);
}

void SoundManager::pauseSound(std::string name) {
    // Pause playing sound with given name
    Mix_Pause(-1);
}

void SoundManager::resumeSound(std::string name) {
    // Resume playing sound with given name
    Mix_Resume(-1);
}
#include "SoundManager.h"

SoundManager::~SoundManager() {
    // Free all loaded sounds
    for (auto const& sound : sounds) {
        Mix_FreeChunk(sound.second);
    }
    // Quit SDL_mixer library
    Mix_CloseAudio();
}

bool SoundManager::LoadSound(std::string filepath, std::string name) {
    // Load sound file and add to map
    Mix_Chunk* sound = Mix_LoadWAV(filepath.c_str());
    if (sound == NULL) {
        printf("Failed to load sound file %s\n SDL_mixer Error: %s\n", filepath.c_str(), Mix_GetError());
        return false;
    }
    std::cout << "Sound loaded successfully: " << filepath << std::endl;
    sounds.insert(std::pair<std::string, Mix_Chunk*>(name, sound));
    return true;
}

void SoundManager::PlaySound(std::string name) {
    // Play sound with given name
    Mix_PlayChannel(-1, sounds[name], 0);
}

void SoundManager::StopSound(std::string name) {
    // Stop playing sound with given name
    Mix_HaltChannel(-1);
}

void SoundManager::PauseSound(std::string name) {
    // Pause playing sound with given name
    Mix_Pause(-1);
}

void SoundManager::ResumeSound(std::string name) {
    // Resume playing sound with given name
    Mix_Resume(-1);
}
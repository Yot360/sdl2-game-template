//
// Created by yot on 19/03/23.
//

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SDL_mixer.h>
#include <string>
#include <map>
#include <iostream>

class SoundManager {
public:

    static SoundManager& getInstance() {
        static SoundManager instance;
        return instance;
    }

    SoundManager(SoundManager const&) = delete;
    void operator=(SoundManager const&) = delete;

    /**
     * Loads a sound effect from a file.
     * @param filepath The path to the sound file.
     * @param name The name to assign to the loaded sound effect.
     * @return True if the sound effect was loaded successfully, false otherwise.
     */
    bool LoadSound(std::string filepath, std::string name);

    /**
     * Plays a loaded sound effect.
     * @param name The name of the sound effect to play.
     */
    void PlaySound(std::string name);

    /**
     * Stops a playing sound effect.
     * @param name The name of the sound effect to stop.
     */
    void StopSound(std::string name);

    /**
     * Pauses a playing sound effect.
     * @param name The name of the sound effect to pause.
     */
    void PauseSound(std::string name);

    /**
     * Resumes a paused sound effect.
     * @param name The name of the sound effect to resume.
     */
    void ResumeSound(std::string name);
    
private:

    SoundManager() = default;
    ~SoundManager();

    std::map<std::string, Mix_Chunk*> sounds;
};


#endif // SOUNDMANAGER_H

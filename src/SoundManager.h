#include <SDL_mixer.h>
#include <string>
#include <map>

class SoundManager {
public:

    /**
     * Default constructor that initializes SDL_mixer.
     */
    SoundManager();

    /**
     * Destructor that frees all loaded sounds and closes SDL_mixer.
     */
    ~SoundManager();

    /**
     * Loads a sound effect from a file.
     * @param filepath The path to the sound file.
     * @param name The name to assign to the loaded sound effect.
     * @return True if the sound effect was loaded successfully, false otherwise.
     */
    bool loadSound(std::string filepath, std::string name);

    /**
     * Plays a loaded sound effect.
     * @param name The name of the sound effect to play.
     */
    void playSound(std::string name);

    /**
     * Stops a playing sound effect.
     * @param name The name of the sound effect to stop.
     */
    void stopSound(std::string name);

    /**
     * Pauses a playing sound effect.
     * @param name The name of the sound effect to pause.
     */
    void pauseSound(std::string name);

    /**
     * Resumes a paused sound effect.
     * @param name The name of the sound effect to resume.
     */
    void resumeSound(std::string name);
    
private:
    std::map<std::string, Mix_Chunk*> sounds;
};
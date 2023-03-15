//
// Created by yot on 23/02/23.
//

#include <SDL.h>
#include <string.h>

class InputHandler
{
public:
    static InputHandler& getInstance()
    {
        static InputHandler instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }


    /**
     * Initalize bool function
     * @brief This function is used to initialize the keyboard
     * @return Returns a bool that is true if the initialization succeeded
     */
    void Initialize();

    /**
     * updateKeyStates void function
     * @brief This function is used to update the keyboard states
     * @return void
     */
    void updateKeyStates();

    /**
     * isKeyDown bool function
     * @brief This function is used to check if a key is held down
     * @param key the scancode for the SDL key
     * @return Returns a bool that tells if the key is held down
     */
    bool isKeyDown(SDL_Scancode key);

    /**
     * isKeyPressed bool function
     * @brief This function is used to check if a key is pressed
     * @param key the scancode for the SDL key
     * @return Returns a bool that tells if the key is pressed
     */
    bool isKeyPressed(SDL_Scancode key);

    /**
     * isKeyReleased bool function
     * @brief This function is used to check if a key is released
     * @param key the scancode for the SDL key
     * @return Returns a bool that tells if the key is released
     */
    bool isKeyReleased(SDL_Scancode key);

private:
    InputHandler() {};

    const Uint8* keyStates;
    Uint8* keyHeldStates;
    int keyLength;

public:
    InputHandler(InputHandler const&) = delete;
    void operator=(InputHandler const&) = delete;

};
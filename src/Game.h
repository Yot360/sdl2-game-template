//
// Created by yot on 23/02/23.
//

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "InputHandler.h"
#include "TTFManager.h"
#include "ConfigHelper.h"
#include "SoundManager.h"

class Game
{
public:
    static Game& getInstance()
    {
        static Game instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    /**
     * Initalize bool function
     * @brief This function is used to initialize SDL and its components, the JSON library and some pointers needed for the game
     * @return Returns a bool that is true if the initialization succeeded
     */
    bool Initialize();

    /**
     * Update void function
     * @brief This function is used to update the game
     * @return void
     */
    void Update();

    /**
     * Draw void function
     * @brief This function is used to draw things on the screen
     * @return void
     */
    void Draw();

    /**
     * Clean void function
     * @brief This function is used to quit SDL and its components, the JSON library and delete some pointers needed for the game
     * @return void
     */
    void Clean();

    /**
     * IsRunning getter function
     * @brief This function is used to get the game running state
     * @return Returns a bool that tells if the game is running
     */
    bool IsRunning() const { return isRunning; };

    /**
     * GetScreenWidth int function
     * @brief This function is used to get the screen width
     * @return Returns an int that represents the screen width
     */
    int GetScreenWidth() const { return SCREEN_WIDTH; };

    /**
     * GetScreenHeight int function
     * @brief This function is used to get the screen height
     * @return Returns an int that represents the screen height
     */
    int GetScreenHeight() const { return SCREEN_HEIGHT; };

private:
    Game() = default;

    //Screen dimension constants
    const int SCREEN_WIDTH = 480;
    const int SCREEN_HEIGHT = 750;

    bool isRunning = true;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Event event{};
    TTF_Font* font{};

    int frameCount = 0;

    int thing;

    SoundManager soundManager;

public:
    Game(Game const&) = delete;
    void operator=(Game const&) = delete;
};
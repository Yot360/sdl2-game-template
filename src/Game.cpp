//
// Created by yot on 19/03/23.
//

#include "Game.h"

bool Game::Initialize()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
        return false;
    }

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0) 
    {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n" << Mix_GetError() << std::endl;
        return false;
    }

    // Create window
    Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if (window == nullptr)
    {
        std::cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set logical size of renderer
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Set the scale mode to preserve aspect ratio
    SDL_RenderSetScale(renderer, (float)SDL_GetWindowSurface(window)->w / (float)SCREEN_WIDTH, (float)SDL_GetWindowSurface(window)->h / (float)SCREEN_HEIGHT);

    // Load config
    ConfigHelper::getInstance().Initialize();

    // Load config data
    thing = ConfigHelper::getInstance().GetThing();

    // Initialize inputs
    InputHandler::getInstance().Initialize();

    // Load font
    font = TTF_OpenFont("Assets/OpenSans-Regular.ttf", 60);

    if (font == nullptr)
    {
        std::cout << TTF_GetError() << std::endl;
        return false;
    }

    // Load background music
    // SoundManager::getInstance().LoadSound("Assets/background_music.ogg", "bg_music");

    // Play background music
    // SoundManager::getInstance().PlaySound("bg_music");

    // Load texture
    AssetsManager::getInstance().LoadTexture("Assets/cube.png", "cube", renderer);

    return true;
}

void Game::Update()
{
    while (SDL_PollEvent(&event)) {
        // Handle quit event
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

    }

    // Update key states
    InputHandler::getInstance().UpdateKeyStates();

    // Increment the frame count
    frameCount++;
}

void Game::Draw()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Color White = { 255, 255, 255 };

    TTFManager::getInstance().WriteText(renderer, font, 40, "Hello World", White, 10, 10);

    // Draw loaded texture
    // AssetsManager::getInstance().DrawTexture(renderer, "cube", 10, 10, 100, 100);

    // Render the screen
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    // Save best score
    ConfigHelper::getInstance().SaveJson();

    // Destroy window/renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();
}

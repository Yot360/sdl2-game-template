//
// Created by yot on 23/02/23.
//

#include "Game.h"

bool Game::Initialize()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
        return false;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }

    //Create window
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
    }

    // Load background music
    // soundManager.loadSound("Assets/background_music.ogg", "bg_music");

    // Play background music
    // soundManager.playSound("bg_music");

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
    InputHandler::getInstance().updateKeyStates();

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

    // Render the screen
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    // Save best score
    ConfigHelper::getInstance().SaveJson();

    //Destroy window/renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();
}

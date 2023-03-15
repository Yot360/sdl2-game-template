# sdl2-game-template
A game template for an SDL2 game
- This template uses SDL2, SDL2_image, SDL2_ttf, nlohmann JSON

## Setting up
To use this template, you must change some code to customize it.
First, open the `CMakeLists.txt` file and change the second line to whatever your project name should be:
```cmake
...
project(Project)
...
```
Then, you want to go inside the `src/Game.cpp` file, at line 33, and change the SDL window name :
```cpp
...
window = SDL_CreateWindow("Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
...
```
You can also change the font if you want, simply put the new one in the Assets folder and change the line for it accordingly in the `src/Game.cpp` file, at line 58 :
```cpp
...
font = TTF_OpenFont("Assets/OpenSans-Regular.ttf", 60);
...
```
You are now set up, it's up to you to chose what to do next. 

## Building
To build the project, simply go into a terminal in the current directory and type the following command :
```
cmake -S . -B build ; cmake --build build
```
You can then run the project by finding the executable for your platform in the build directory.

## Documentation
The documentation for this template is created by Doxygen. To read it, simply open https://yot360.github.io/sdl2-game-template/.
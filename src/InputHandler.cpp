//
// Created by yot on 19/03/23.
//

#include "InputHandler.h"

void InputHandler::Initialize()
{
    // Initialize the key states
    keyStates = SDL_GetKeyboardState(&keyLength);
    //Setting mPrevKeyboardState to be the same length as mKeyboardState
    keyHeldStates = new Uint8[keyLength];
    //Copying the contents of mKeyboardState into mPrevKeyboardState so that it contains data on the first frame
    memcpy(keyHeldStates, keyStates, keyLength);
}

void InputHandler::UpdateKeyStates()
{
    //Copying the keyboard state into the previous keyboard state array at the end of the frame
    memcpy(keyHeldStates, keyStates, keyLength);
}

// Check if a key is currently pressed
bool InputHandler::IsKeyDown(SDL_Scancode key)
{
    return (keyStates[key] != 0);
}

// Check if a key was just pressed (i.e. not held down)
bool InputHandler::IsKeyPressed(SDL_Scancode key)
{
    return (keyHeldStates[key]) == 0 && (keyStates[key] != 0);
}

bool InputHandler::IsKeyReleased(SDL_Scancode key)
{
    return (keyHeldStates[key] != 0) && (keyStates[key] == 0);
}

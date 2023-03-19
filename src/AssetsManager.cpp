//
// Created by yot on 19/03/23.
//

#include "AssetsManager.h"

bool AssetsManager::LoadTexture(std::string filePath, std::string id, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface) {
        std::cout << "Error loading image: " << filePath << "\nError: " << IMG_GetError() << std::endl;
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        // Handle error creating texture
        std::cout << "Error creating texture: " << filePath << "\nError: " << IMG_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return false;
    }
    SDL_FreeSurface(surface);
    textureMap[id] = texture;
    std::cout << "Texture loaded successfully: " << filePath << std::endl;

    return true;
}

SDL_Texture* AssetsManager::GetTexture(std::string id) {
    auto iter = textureMap.find(id);
    if (iter == textureMap.end()) {
        std::cout << "Texture: " << id << " not found" << std::endl;
        return nullptr;
    }
    return iter->second;
}

void AssetsManager::FreeTexture(std::string id) {
    auto iter = textureMap.find(id);
    if (iter != textureMap.end()) {
        SDL_DestroyTexture(iter->second);
        textureMap.erase(iter);
    }
}

void AssetsManager::DrawTexture(SDL_Renderer* renderer, std::string id, int x, int y, int width, int height) {
    SDL_Texture* texture = GetTexture(id);
    if (!texture) {
        std::cout << "Texture: " << id << " not found" << std::endl;
        return;
    }
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

}

AssetsManager::~AssetsManager() {
    
    for (auto const& [key, val] : textureMap)
    {
        SDL_DestroyTexture(val);
        textureMap.erase(key);
    }
}
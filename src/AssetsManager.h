#include <SDL_image.h>
#include <map>
#include <string>
#include <iostream>

class AssetsManager
{
public:
    static AssetsManager& getInstance()
    {
        static AssetsManager instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    bool LoadTexture(std::string filePath, std::string id, SDL_Renderer* renderer);
    SDL_Texture* GetTexture(std::string id);
    void FreeTexture(std::string id);
    void DrawTexture(SDL_Renderer* renderer, std::string id, int x, int y, int width, int height);

    
private:
    AssetsManager() = default;
    ~AssetsManager();

    std::map<std::string, SDL_Texture*> textureMap;

public:
    AssetsManager(AssetsManager const&) = delete;
    void operator=(AssetsManager const&) = delete;
};
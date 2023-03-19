//
// Created by yot on 19/03/23.
//

#ifndef TTFMANAGER_H
#define TTFMANAGER_H

#include <SDL_ttf.h>
#include <string>

class TTFManager
{
public:
    static TTFManager& getInstance()
    {
        static TTFManager instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    /**
     * WriteText void function
     * @brief This function is used to write text on the screen
     * @param renderer the screen renderer
     * @param font the font to write the text
     * @param fontSizen the font size
     * @param text the text to write
     * @param color the color of the text
     * @param x where to put the text in the abscissa
     * @param y where to put the text in the ordinate
     * @return void
     */
    void WriteText(SDL_Renderer* renderer, TTF_Font* font, int fontSizen, std::string text, SDL_Color color, int x, int y);

private:
    TTFManager() = default;

public:
    TTFManager(TTFManager const&) = delete;
    void operator=(TTFManager const&) = delete;

};


#endif // TTFMANAGER_H

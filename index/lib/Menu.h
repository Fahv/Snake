#ifndef _MENU_H_
#define _MENU_H_

#include <SDL/SDL.h>
#include "Image.h"
#include "Player.h"
#include "Piece.h"
#include "HighScore.h"
#include "Font.h"
#include "HighScoreItem.h"

class Menu
{
    public:
        Menu();
        bool init();
        void render(SDL_Surface* Surf_Display);
        void cleanup();
        void logic();
        void changeCurrentMenuPos(bool up);
        int executeCMD();


    private:
        enum MENUSTATES{
            MAINMENU = 0x00,
            HIGHSCOREMENU
        };
        int currentMenuPos;
        SDL_Surface* MENU_SURF;
        SDL_Surface* CURRENT_SURF;
        SDL_Surface* HIGHSCORE_SURF;
        SDL_Surface* HIGHSCORETEXT_SURF;

        Player menuSnake;
        uint32_t menuTick;
        MENUSTATES currentMenuState;

        Font highscoreFont;


};
#endif


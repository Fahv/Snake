//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _GAME_H_
    #define _GAME_H_

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "Image.h"
#include "Entity.h"
#include "define.h"
#include "Player.h"
#include "Piece.h"
#include "Font.h"
#include "Menu.h"
#include "HighScore.h"
#include "InputHighName.h"

//==============================================================================
class Game{

    private:
        bool done;
        SDL_Surface* DISPLAY_SURF;
        SDL_Surface* BACKGROUND_SURF;
        SDL_Surface* POINTS_SURF;
        SDL_Surface* NEWHIGHSCORE_SURF;
        SDL_Surface* NEWHIGHNAMESCORE_SURF;
        Player snake;
        Font pointsFont;
        InputHighName newHighScoreName;

        enum GAME_STATES{
            GAME_RUNNING = 0x00,
            GAME_PAUSED,
            GAME_MENU,
            GAME_START,
            GAME_INPUTHIGHSCORE
        };

        GAME_STATES currentState;

        Menu gameMenu;


    public:
        //Constructor
        Game();

        //Game Functions
        bool init();
        void logic();
        void events(SDL_Event* event);
        void render();
        void cleanUp();


        //Event Functions
        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
        void OnExit();

        //Other Functions
        bool getDone();

        uint32_t tick;

};


//==============================================================================

#endif

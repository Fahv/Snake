//=============================================================================
#ifndef _PLAYER_H_
    #define _PLAYER_H_

#include "Animation.h"
#include "Image.h"
#include "FPS.h"
#include "SnakeStack.h"
#include "SnakeCords.h"
#include "Piece.h"

//=============================================================================
class Player{
    public:
        Player();

		bool load();

        void logic();

        void render(SDL_Surface* Surf_Display);

        void cleanUp();

        void animate();

        void changeDir(int dir);

        int speed;

        int getScore();

        void reset();

        bool getDead();

        SnakeStack* snakeBody;

    private:


        bool moveUp;
        bool moveLeft;
        bool moveRight;
        bool moveDown;
        bool dead;

        int score;



        SDL_Surface* HEAD_SURF;
        SDL_Surface* BODY_SURF;
        SDL_Surface* TAIL_SURF;

        bool posValid(int newX, int newY);
};

//=============================================================================

#endif



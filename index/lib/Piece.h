#ifndef _PIECE_H_
#define _PIECE_H_

#include <SDL/SDL.h>
#include "SnakeCords.h"
#include "Image.h"

#include <stdio.h>
#include <time.h>


class Piece
{
    public:

        static Piece pieceControl;

        Piece();
        bool load();
        void logic();
        void render(SDL_Surface* surf_display);
        void cleanUp();
        bool collision(SnakeCords* newCord);
        SnakeCords pieceCord;
        void newPos();



    private:
        SDL_Surface* PIECE_SURF;



};

#endif

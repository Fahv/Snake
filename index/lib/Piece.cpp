#include "Piece.h"

Piece Piece::pieceControl;

Piece::Piece()
{

}

bool Piece::load()
{
    if((PIECE_SURF = Image::loadImage((char *)"img/snakePiece.png")) == NULL)
    {
        return false;
    }
    srand(time(NULL));
    newPos();

    return true;
}

void Piece::logic()
{

}

void Piece::render(SDL_Surface* surf_display)
{
    if(surf_display == NULL) return;
    Image::drawImage(surf_display,PIECE_SURF,pieceCord.x *15,pieceCord.y*15);
}

void Piece::cleanUp()
{
    if(PIECE_SURF)
        SDL_FreeSurface(PIECE_SURF);
}

bool Piece::collision(SnakeCords* newCord)
{
    if(newCord->x == pieceCord.x)
    {
        if(newCord->y == pieceCord.y)
        {
            newPos();
            return true;
        }
    }
    return false;
}

void Piece::newPos()
{
    pieceCord.x = rand() % 38 + 1;
    pieceCord.y = rand() % 38 + 1;
}

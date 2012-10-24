#include "Image.h"

Image::Image()
{

}

SDL_Surface* Image::loadImage(char* fileName)
{
    SDL_Surface* TEMP_SURF = NULL;
    SDL_Surface* RETURN_SURF = NULL;

    if((TEMP_SURF = IMG_Load(fileName)) == NULL) {
        return NULL;
    }

    RETURN_SURF = SDL_DisplayFormatAlpha(TEMP_SURF);
    SDL_FreeSurface(TEMP_SURF);

    return RETURN_SURF;
}

bool Image::drawImage(SDL_Surface* DEST_SURF, SDL_Surface* SRC_SURF, int x, int y)
{
    if(DEST_SURF == NULL  || SRC_SURF == NULL)
    {
        return false;
    }

    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;

    SDL_BlitSurface(SRC_SURF, NULL, DEST_SURF, &destRect);


    return true;
}

bool Image::drawImage(SDL_Surface* DEST_SURF, SDL_Surface* SRC_SURF, int x, int y, int x2, int y2, int w, int h)
{
    if(DEST_SURF == NULL  || SRC_SURF == NULL)
    {
        return false;
    }

    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;


    SDL_Rect srcRect;

    srcRect.x = x2;
    srcRect.y = y2;
    srcRect.w = w;
    srcRect.h = h;

    SDL_BlitSurface(SRC_SURF, &srcRect, DEST_SURF, &destRect);


    return true;
}

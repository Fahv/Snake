#ifndef _IMAGE_H_
    #define _IMAGE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cstddef>

class Image
{
    public:
        Image();

        static SDL_Surface* loadImage(char* file);

        static bool drawImage(SDL_Surface* DEST_SURF, SDL_Surface* SRC_SURF, int x, int y);

        static bool drawImage(SDL_Surface* DEST_SURF, SDL_Surface* SRC_SURF, int x, int y, int x2, int y2, int w, int h);
};


#endif

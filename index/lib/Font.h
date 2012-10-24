#ifndef _FONT_H_
#define _FONT_H_

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <cstdlib>


class Font
{

	public:
		Font();
		bool loadFont(char* fileName,int r,int g, int b, int size);
        SDL_Surface* renderText(char* textToRender);


    private:
        TTF_Font *font;
        SDL_Color textColor;

};

#endif

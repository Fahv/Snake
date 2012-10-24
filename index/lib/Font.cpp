#include "Font.h"


Font::Font(){
    font = NULL;
}

bool Font::loadFont(char* fileName, int r,int g, int b, int size)
{
    int init = TTF_WasInit();
    if (init == 0)       //Hasn't been initalized so initalize it
    {
        if (TTF_Init() < 0)
        {
            return false;
        }
    }
    textColor =  {r,g,b};
    font = TTF_OpenFont(fileName,size);
    if(font == NULL)
    {
        printf("Oh My Goodness, an error : %s", TTF_GetError());
        return false;
    }

    return true;
}

SDL_Surface* Font::renderText(char* textToRender)
{
    return TTF_RenderText_Solid( font,textToRender, textColor );
}

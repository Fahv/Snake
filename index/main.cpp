#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "lib/Game.h"

int main ( int argc, char** argv )
{
    Game theGame;

    if(theGame.init() == false)
    {
        printf("Error Initilizing the game");
        return -1;
    }
    SDL_Event event;
    printf("Start of Game :D \n");
    while(!theGame.getDone())
    {
       // printf("Events \n");
        while(SDL_PollEvent(&event)) {
            theGame.events(&event);
        }
        //printf("Logic \n");
        theGame.logic();
        //printf("Render \n");
        theGame.render();
        SDL_Delay((uint32_t) 3);
    }
    theGame.cleanUp();

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

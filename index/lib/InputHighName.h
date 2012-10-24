#ifndef _INPUTHIGHNAME_H_
#define _INPUTHIGHNAME_H_

#include <SDL/SDL.h>


class InputHighName
{
    public:
        InputHighName();
        int currentPos;
        char HighName[8];
        void events(SDLKey sym);
    private:
        void increasePOS();

};
#endif

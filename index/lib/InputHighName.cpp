#include "InputHighName.h"

InputHighName::InputHighName()
{
    currentPos = 0;
    HighName[0] = ' ';
    HighName[1] = ' ';
    HighName[2] = ' ';
    HighName[3] = ' ';
    HighName[4] = ' ';
    HighName[5] = ' ';
    HighName[6] = ' ';
    HighName[7] = ' ';

}

void InputHighName::events(SDLKey sym)
{
    switch(sym)
        {
            case SDLK_a:
            {
                HighName[currentPos] = 'A';
                increasePOS();
                break;
            };
            case SDLK_b:
            {
                HighName[currentPos] = 'B';
                increasePOS();
                break;
            }
            case SDLK_c:
            {
                HighName[currentPos] = 'C';
                increasePOS();
                break;
            }
            case SDLK_d:
            {
                HighName[currentPos] = 'D';
                increasePOS();
                break;
            }
            case SDLK_e:
            {
                HighName[currentPos] = 'E';
                increasePOS();
                break;
            }
            case SDLK_f:
            {
                HighName[currentPos] = 'F';
                increasePOS();
                break;
            }
            case SDLK_g:
            {
                HighName[currentPos] = 'G';
                increasePOS();
                break;
            }
            case SDLK_h:
            {
                HighName[currentPos] = 'H';
                increasePOS();
                break;
            }
            case SDLK_i:
            {
                HighName[currentPos] = 'I';
                increasePOS();
                break;
            }
            case SDLK_j:
            {
                HighName[currentPos] = 'J';
                increasePOS();
                break;
            }
            case SDLK_k:
            {
                HighName[currentPos] = 'K';
                increasePOS();
                break;
            }
            case SDLK_l:
            {
                HighName[currentPos] = 'L';
                increasePOS();
                break;
            }
            case SDLK_m:
            {
                HighName[currentPos] = 'M';
                increasePOS();
                break;
            }
            case SDLK_n:
            {
                HighName[currentPos] = 'N';
                increasePOS();
                break;
            }
            case SDLK_o:
            {
                HighName[currentPos] = 'O';
                increasePOS();
                break;
            }
            case SDLK_p:
            {
                HighName[currentPos] = 'P';
                increasePOS();
                break;
            }
            case SDLK_q:
            {
                HighName[currentPos] = 'Q';
                increasePOS();
                break;
            }
            case SDLK_r:
            {
                HighName[currentPos] = 'R';
                increasePOS();
                break;
            }
            case SDLK_s:
            {
                HighName[currentPos] = 'S';
                increasePOS();
                break;
            }
            case SDLK_t:
            {
                HighName[currentPos] = 'T';
                increasePOS();
                break;
            }
            case SDLK_u:
            {
                HighName[currentPos] = 'U';
                increasePOS();
                break;
            }
            case SDLK_v:
            {
                HighName[currentPos] = 'V';
                increasePOS();
                break;
            }
            case SDLK_w:
            {
                HighName[currentPos] = 'W';
                increasePOS();
                break;
            }
            case SDLK_x:
            {
                HighName[currentPos] = 'X';
                increasePOS();
                break;
            }
            case SDLK_y:
            {
                HighName[currentPos] = 'Y';
                increasePOS();
                break;
            }
            case SDLK_z:
            {
                HighName[currentPos] = 'Z';
                increasePOS();
                break;
            }
            case SDLK_BACKSPACE:
                {
                    if(currentPos !=0)
                    {
                        if(HighName[currentPos] == ' ')
                        {
                            HighName[currentPos -1] = ' ';
                            currentPos--;
                        }
                        else
                        {
                            HighName[currentPos] = ' ';
                            currentPos--;
                        }
                    }
                    else if(currentPos == 0)
                    {
                        HighName[currentPos] = ' ';
                    }
                    break;
                }
            default:{
                break;
            };
        }
}

void InputHighName::increasePOS()
{
    if(currentPos < 7)
    {
        currentPos++;
    }
}

#include "SnakeCords.h"

SnakeCords::SnakeCords()
{
    x = y =0;
}

bool SnakeCords::operator== (SnakeCords param)
{
    if(x == param.x && y == param.y)
        return true;
    return false;
}

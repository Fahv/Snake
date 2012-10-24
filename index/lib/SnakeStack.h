#ifndef _SNAKESTACK_H_
#define _SNAKESTACK_H_

#include "SnakeCords.h"
#include <vector>

class SnakeStack
{
    public:
        SnakeStack();
        SnakeStack(SnakeCords cords);
        SnakeStack(int x,int y);
        ~SnakeStack();

        SnakeCords getPart(int i);

        void add(SnakeCords cord);
        void add(int x,int y);

        void increaseSize(SnakeCords addMeCord);
        int getSize();

    private:
        //int size;
        std::vector<SnakeCords> body;

};
#endif

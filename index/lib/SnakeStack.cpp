#include "SnakeStack.h"

SnakeStack::SnakeStack()
{
}
SnakeStack::SnakeStack(SnakeCords cords)
{
    body[0]=cords;
}
SnakeStack::SnakeStack(int x,int y)
{
    SnakeCords tmpCords;
    tmpCords.x = x;
    tmpCords.y = y;
    body.push_back(tmpCords);
}

SnakeStack::~SnakeStack()
{
    body.clear();
}

void SnakeStack::add(SnakeCords cords)
{
    if(body.size() !=1)
    {
        for(int i=body.size()-1;i>0;i--)
        {
            body[i] =  body[i-1];
        }
        body[0] = cords;
    }
    else
    {
        body[0] = cords;
    }
}

void SnakeStack::add(int x,int y)
{
    SnakeCords addMe;
    addMe.x = x;
    addMe.y = y;

    if(body.size() !=1)
    {
        for(int i=body.size()-1;i>0;i--)
        {
            body[i] =  body[i-1];
        }
        body[0] = addMe;
    }
    else
    {
        body[0] = addMe;
    }
}

// TODO (robert#2#): Dynamic Memory

void SnakeStack::increaseSize(SnakeCords addMeCord)
{
    body.push_back(addMeCord);
}

int SnakeStack::getSize()
{
    return body.size();
}

SnakeCords SnakeStack::getPart(int i)
{
    if(i>= body.size())
    {
        SnakeCords tmpCords;
        return tmpCords;
    }
    return body[i];
}

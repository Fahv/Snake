#ifndef _SNAKECORDS_H_
#define _SNAKECORDS_H_

class SnakeCords
{
    public:
        SnakeCords();
        int x;
        int y;
        bool operator == (SnakeCords);
};

#endif

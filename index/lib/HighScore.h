#ifndef _HIGHSCORE_H_
#define _HIGHSCORE_H_

#include <SDL/SDL.h>
#include "HighScoreItem.h"
#include <stdio.h>
#include <errno.h>
#include <string>


#define NUMBEROFSCORES 10


class HighScore
{
    public:
        static HighScore HighScoreControl;
        HighScore();
        bool init();
        HighScoreItem* getScore(int num);
        void cleanup();
        int getNumberOfScores();
        void insertNewScore(char* scorer, int score);


    private:
        HighScoreItem highScores[NUMBEROFSCORES];
};
#endif

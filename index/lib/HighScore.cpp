#include "HighScore.h"

HighScore HighScore::HighScoreControl;

HighScore::HighScore(){
}

bool HighScore::init()
{
    FILE* fileHandle = fopen("highscores.txt","r");
    if(fileHandle == NULL)
    {
         printf ("Error opening file unexist.ent: %s\n",strerror(errno));
        return false;
    }
    for(int i = 0;i<NUMBEROFSCORES;i++)
    {
        char tmpName[8];
        int tmpScore;
        fscanf(fileHandle,"%s",&tmpName);
        fscanf(fileHandle,"%d",&tmpScore);
        fscanf(fileHandle,"\n");
        highScores[i].name = tmpName;
        highScores[i].score = tmpScore;
    }

    fclose(fileHandle);


    return true;
}

HighScoreItem* HighScore::getScore(int num)
{
    if(num < NUMBEROFSCORES)
        return &highScores[num];
    return NULL;
}

void HighScore::cleanup()
{
    FILE* fileHandle = fopen("highscores.txt","w");
    if(fileHandle == NULL)
    {
        printf("Error opening file");
        return;
    }
    for(int i = 0;i<NUMBEROFSCORES;i++)
    {
        fprintf(fileHandle,"%s %d",(char *)highScores[i].name.c_str(),highScores[i].score);
        fprintf(fileHandle,"\n");
    }
    fclose(fileHandle);
}

int HighScore::getNumberOfScores()
{
    return NUMBEROFSCORES;
}

void HighScore::insertNewScore(char* scorer,int score)
{
    highScores[NUMBEROFSCORES -1].name = scorer;
    highScores[NUMBEROFSCORES -1].score = score;
    bool inOrder = false;
    while(inOrder == false)
    {
        inOrder = true;
        for(int i = 0;i<NUMBEROFSCORES-1;i++)
        {
            if(highScores[i].score < highScores[i+1].score)
            {
                HighScoreItem tmpItem;
                tmpItem.score = highScores[i + 1].score;
                tmpItem.name = highScores[i + 1].name;
                highScores[i+1].score = highScores[i].score;
                highScores[i+1].name = highScores[i].name;
                highScores[i].score = tmpItem.score;
                highScores[i].name = tmpItem.name;
                inOrder = false;
            }
        }
    }
}

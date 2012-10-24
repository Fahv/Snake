#include "Menu.h"

Menu::Menu()
{
    MENU_SURF = NULL;
    CURRENT_SURF = NULL;
    HIGHSCORE_SURF = NULL;
    HIGHSCORETEXT_SURF = NULL;
}

bool Menu::init()
{
    if((MENU_SURF = Image::loadImage((char *)"img/Menu.png")) == NULL)
    {
        return false;
    }
    if((CURRENT_SURF = Image::loadImage((char *)"img/snakeBody.png")) == NULL)
    {
        return false;
    }
    if((HIGHSCORE_SURF = Image::loadImage((char *)"img/HighScores.png")) == NULL)
    {
        return false;
    }
    if((menuSnake.load()) == false)
    {
        return false;
    }
    if(highscoreFont.loadFont((char *)"fonts/acknowtt.ttf",0,0,0,25)== false)
    {
        return false;
    }
    currentMenuPos = 0;
    menuTick =0;
    currentMenuState = MAINMENU;

    return true;
}

void Menu::logic()
{
    uint32_t now;
    now = SDL_GetTicks();
    if(menuTick <= now)
    {
        menuTick = now+menuSnake.speed;
        menuSnake.logic();
        printf("%d\n",menuSnake.getScore());
    }
    if(menuSnake.snakeBody->getPart(0).x != Piece::pieceControl.pieceCord.x)
    {
        if(menuSnake.snakeBody->getPart(0).x < Piece::pieceControl.pieceCord.x)
        {
            menuSnake.changeDir(3);

        }
        else
        {
            menuSnake.changeDir(2);
        }
    }
    else
    {
        if(menuSnake.snakeBody->getPart(0).y < Piece::pieceControl.pieceCord.y)
        {
            menuSnake.changeDir(1);

        }
        else
        {
            menuSnake.changeDir(0);
        }
    }
    if(menuSnake.getScore() >100000)
    {
        menuSnake.reset();
    }

}

void Menu::render(SDL_Surface* DISPLAY_SURF)
{
    Piece::pieceControl.render(DISPLAY_SURF);
    menuSnake.render(DISPLAY_SURF);
    if(currentMenuState == MAINMENU)
    {
        Image::drawImage(DISPLAY_SURF,MENU_SURF,0,0);
        Image::drawImage(DISPLAY_SURF,CURRENT_SURF,168,256+40*currentMenuPos);
    }
    else
    {
        Image::drawImage(DISPLAY_SURF,HIGHSCORE_SURF,0,0);
        Image::drawImage(DISPLAY_SURF,CURRENT_SURF,259,551);
        for(int i =0;i<HighScore::HighScoreControl.getNumberOfScores();i++)
        {

            char tmpHS[8+2+25];
            HighScoreItem* tmpItem;
            tmpItem = HighScore::HighScoreControl.getScore(i);
            sprintf(tmpHS,"%s \t\t %d",HighScore::HighScoreControl.getScore(i)->name.c_str(),HighScore::HighScoreControl.getScore(i)->score);
            HIGHSCORETEXT_SURF = highscoreFont.renderText((char *)tmpHS);
            Image::drawImage(DISPLAY_SURF,HIGHSCORETEXT_SURF,150,185 + (27 * i));
        }
        SDL_FreeSurface(HIGHSCORETEXT_SURF);
    }
}

void Menu::changeCurrentMenuPos(bool up)
{
    if(up == true)
    {
        if(currentMenuPos!=0)
        {
            currentMenuPos--;
        }

    }
    else
    {
        if(currentMenuPos!=2)
        {
            currentMenuPos++;
        }
    }
}

int Menu::executeCMD()
{
    if(currentMenuPos == 1 && currentMenuState == MAINMENU)
    {
        currentMenuState = HIGHSCOREMENU;
    }
    else if(currentMenuPos == 1 && currentMenuState == HIGHSCOREMENU)
    {
        currentMenuState = MAINMENU;
    }
    return currentMenuPos;
}

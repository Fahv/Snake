#include "Game.h"


Game::Game()
{
    done = false;
    DISPLAY_SURF = NULL;
    BACKGROUND_SURF = NULL;
    POINTS_SURF = NULL;
    NEWHIGHNAMESCORE_SURF = NULL;
}

bool Game::getDone()
{
    return done;
}

bool Game::init()
{
    currentState = GAME_START;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        return false;
    }
    if((DISPLAY_SURF = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    if((BACKGROUND_SURF = Image::loadImage((char *)"img/background.png"))==NULL)
    {
        return false;
    }
    if((NEWHIGHSCORE_SURF = Image::loadImage((char *)"img/NewHighScore.png")) == NULL)
    {
        return false;
    }

    if((snake.load()) == false)
    {
        return false;
    }
    tick = SDL_GetTicks();
    if(Piece::pieceControl.load() == false)
    {
        return false;
    }
    if(pointsFont.loadFont((char *)"fonts/acknowtt.ttf",0,0,255,15)== false)
    {
        return false;
    }
    if(gameMenu.init() == false)
    {
        return false;
    }
    if(HighScore::HighScoreControl.init() == false)
    {
        return false;
    }
    currentState = GAME_MENU;
    return true;
}

void Game::events(SDL_Event* event)
{
     switch(event->type)
     {
        case SDL_KEYDOWN: {
            OnKeyDown(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
            break;
        }

        case SDL_KEYUP: {
            OnKeyUp(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
            break;
        }
        case SDL_QUIT:{
            OnExit();
            break;

        }
     }
}

void Game::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    if(currentState == GAME_RUNNING)
    {
        switch(sym) {
            case SDLK_LEFT: {
                snake.changeDir(2);
                break;
            }

            case SDLK_RIGHT: {
                snake.changeDir(3);
                break;
            }
            case SDLK_UP: {
                snake.changeDir(0);
                break;
            }

            case SDLK_DOWN: {
                snake.changeDir(1);
                break;
            }
            case SDLK_p:{
                currentState = GAME_PAUSED;
                break;
            }

            default: {
            }
        }
    }
    else if(currentState == GAME_PAUSED)
    {
        switch(sym)
        {
            case SDLK_p:{
                currentState = GAME_RUNNING;

            }
            default:{
            }
        }
    }
    else if(currentState == GAME_MENU)
    {
        switch(sym)
        {
            case SDLK_UP:{
                gameMenu.changeCurrentMenuPos(true);
                break;
            }
            case SDLK_DOWN:{
                gameMenu.changeCurrentMenuPos(false);
                break;
            }
            case SDLK_RETURN:{
                int CMDReturn = gameMenu.executeCMD();
                if(CMDReturn == 0)
                {
                    currentState = GAME_RUNNING;
                }
                else if(CMDReturn == 2)
                {
                    OnExit();
                }
                break;
            }
            default:{
            };
        }
    }
    else if(currentState == GAME_INPUTHIGHSCORE)
    {
        newHighScoreName.events(sym);
        switch(sym)
        {
            case SDLK_RETURN:{
                HighScore::HighScoreControl.insertNewScore(newHighScoreName.HighName,snake.getScore());
                snake.reset();
                currentState = GAME_MENU;
                break;
            };
            default:{
                break;
            };
        }
    }
}

void Game::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{

}

void Game::OnExit()
{
    done = true;
}
void Game::logic()
{
    if(currentState == GAME_RUNNING)
    {
        FPS::FPSControl.logic();

        char Buffer[255];
        sprintf(Buffer, "FPS: %d", FPS::FPSControl.getFPS());


        uint32_t now;
        now = SDL_GetTicks();
        if(tick <= now)
        {
            tick = now+snake.speed;
            snake.logic();
        }
        SDL_WM_SetCaption(Buffer, Buffer);
        sprintf(Buffer,"Points: %d",snake.getScore());
        POINTS_SURF = pointsFont.renderText((char *)Buffer);
        if(snake.getDead() == true)
        {
            if(snake.getScore() > HighScore::HighScoreControl.getScore(HighScore::HighScoreControl.getNumberOfScores() - 1)->score)
            {
                currentState = GAME_INPUTHIGHSCORE;
                //HighScore::HighScoreControl.insertNewScore("Player 1",snake.getScore());

            }
            else
            {
                snake.reset();
            }

            //currentState = GAME_MENU;
        }
    }
    else if(currentState == GAME_PAUSED)
    {
        char Buffer[255];
        sprintf(Buffer, "Paused!");
        SDL_WM_SetCaption(Buffer, Buffer);
        sprintf(Buffer,"Points: %d",snake.getScore());
        POINTS_SURF = pointsFont.renderText((char *)Buffer);

    }
    else if(currentState == GAME_MENU)
    {
        char Buffer[255];
        sprintf(Buffer, "Awesome Snake Game :D");
        SDL_WM_SetCaption(Buffer, Buffer);
        gameMenu.logic();
    }
    else if(currentState == GAME_INPUTHIGHSCORE)
    {
        char NameBuffer[8];
        sprintf(NameBuffer, newHighScoreName.HighName);
        NEWHIGHNAMESCORE_SURF = pointsFont.renderText((char *)NameBuffer);
        //char PointsBuffer[255];
        //sprintf(PointsBuffer,"%d",snake.getScore());
        //POINTS_SURF = pointsFont.renderText((char *)PointsBuffer);
    }

}

void Game::render()
{
    SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = WWIDTH;
	rect.h = WHEIGHT;

	SDL_FillRect(DISPLAY_SURF, &rect, 0);       //Reset Display
    Image::drawImage(DISPLAY_SURF,BACKGROUND_SURF,0,0);
    if(currentState == GAME_RUNNING)      //game isn't paused
    {
        Piece::pieceControl.render(DISPLAY_SURF);
        snake.render(DISPLAY_SURF);
        Image::drawImage(DISPLAY_SURF,POINTS_SURF,50,650);
    }
    else if(currentState == GAME_PAUSED)           //game is paused
    {
        SDL_Rect pauseRect;
        pauseRect.x =0;
        pauseRect.y=0;
        pauseRect.w=BACKGROUND_SURF->w;
        pauseRect.h=BACKGROUND_SURF->h;
                //                X            Y            X2                      Y2                   R   G   B    A
        boxRGBA(DISPLAY_SURF, pauseRect.x, pauseRect.y, pauseRect.w+pauseRect.x, pauseRect.h+pauseRect.y,0, 125, 50, 125);
        Image::drawImage(DISPLAY_SURF,POINTS_SURF,50,50);

    }
    else if(currentState == GAME_MENU)
    {
        gameMenu.render(DISPLAY_SURF);
    }
    else if(currentState == GAME_INPUTHIGHSCORE)
    {
        Image::drawImage(DISPLAY_SURF,NEWHIGHSCORE_SURF,0,0);
        //Image::drawImage(DISPLAY_SURF,POINTS_SURF,274,273);
        Image::drawImage(DISPLAY_SURF,NEWHIGHNAMESCORE_SURF,155,400);
    }

    SDL_Flip(DISPLAY_SURF);
    if(POINTS_SURF != NULL)
    {
        SDL_FreeSurface(POINTS_SURF);
        POINTS_SURF = NULL;
    }

}

void Game::cleanUp()
{
    HighScore::HighScoreControl.cleanup();            //Save the HighScores
    SDL_Quit();
}

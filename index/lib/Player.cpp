//=============================================================================
#include "Player.h"

//=============================================================================
Player::Player() {
    snakeBody = NULL;
    HEAD_SURF = NULL;
    BODY_SURF = NULL;
    TAIL_SURF = NULL;
    moveLeft = moveRight = moveUp = moveDown = false;
    dead = false;
    speed = 300;
    score = 0;
}

//=============================================================================
bool Player::load() {
    if((HEAD_SURF = Image::loadImage((char *)"img/snakeBody.png")) == NULL) {
		return false;
	}
	if((BODY_SURF = Image::loadImage((char *)"img/snakeBody.png")) == NULL) {
		return false;
	}
	if((TAIL_SURF = Image::loadImage((char *)"img/snakeBody.png")) == NULL) {
		return false;
	}
    snakeBody = new SnakeStack(20,20);
    return true;
}

void Player::reset()
{
    delete snakeBody;
    snakeBody = new SnakeStack(20,20);
    dead = false;
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = false;
    score = 0;
    speed = 300;
    Piece::pieceControl.newPos();
}

//-----------------------------------------------------------------------------
void Player::logic() {
    if(moveUp == false && moveDown == false && moveLeft == false && moveRight == false)     //No direction to move in
    {
        return;
    }
    SnakeCords tmpCord = snakeBody->getPart(0);
    if(moveUp)
    {
        tmpCord.y--;
    }
    else if(moveDown)
    {
        tmpCord.y++;
    }
    else if(moveLeft)
    {
        tmpCord.x--;
    }
    else if(moveRight)
    {
        tmpCord.x++;
    }
    if(!posValid(tmpCord.x,tmpCord.y))
    {
        dead = true;
    }
    snakeBody->add(tmpCord);
    if(Piece::pieceControl.collision(&tmpCord))  //Collision Happened
    {
        snakeBody->increaseSize(tmpCord);
        snakeBody->add(snakeBody->getPart(0));
        score = score + (snakeBody->getSize() * 100);
        speed = 300 -(snakeBody->getSize() * 5);
        if(speed <25)
        {
            speed = 25;
        }
    }
    score += speed;
}

//-----------------------------------------------------------------------------
void Player::render(SDL_Surface* Surf_Display)
{
    SnakeCords tmpCord;
    if(snakeBody->getSize() == 1)
    {
        tmpCord = snakeBody->getPart(0);
        Image::drawImage(Surf_Display,HEAD_SURF,tmpCord.x*15,tmpCord.y*15);
    }
    else if(snakeBody->getSize() == 2)
    {
        tmpCord = snakeBody->getPart(0);
        Image::drawImage(Surf_Display,HEAD_SURF,tmpCord.x*15,tmpCord.y*15);

        tmpCord = snakeBody->getPart(1);
        Image::drawImage(Surf_Display,TAIL_SURF,tmpCord.x*15,tmpCord.y*15);
    }
    else
    {
        tmpCord = snakeBody->getPart(0);
        Image::drawImage(Surf_Display,HEAD_SURF,tmpCord.x*15,tmpCord.y*15);
        for(int i=1;i<=snakeBody->getSize()-2;i++)
        {
            tmpCord = snakeBody->getPart(i);
            Image::drawImage(Surf_Display,BODY_SURF,tmpCord.x*15,tmpCord.y*15);
        }
        tmpCord = snakeBody->getPart(snakeBody->getSize()-1);
        Image::drawImage(Surf_Display,TAIL_SURF,tmpCord.x*15,tmpCord.y*15);
    }

}

//-----------------------------------------------------------------------------
bool Player::posValid(int newX, int newY)
{
    if(newX <1 || newX >39)
        return false;
    if(newY<1 || newY>39)
        return false;
    for(int i =0; i<snakeBody->getSize();i++)
    {
        if(newX == snakeBody->getPart(i).x && newY == snakeBody->getPart(i).y)
        {
            return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
void Player::cleanUp() {
	if(HEAD_SURF)
        SDL_FreeSurface(HEAD_SURF);
    if(BODY_SURF)
        SDL_FreeSurface(BODY_SURF);
    if(TAIL_SURF)
        SDL_FreeSurface(TAIL_SURF);
}

//------------------------------------------------------------------------------
void Player::animate() {
	/*if(speed != 0) {
		anim_Control.MaxFrames = 8;
	}else{
		anim_Control.MaxFrames = 0;
	}

	Entity::animate();
*/
}

void Player::changeDir(int dir)
{
    switch(dir)
    {
        case 0:
        {
            //printf("Up ");
            if(!moveDown)
            {
                moveUp = true;
                moveDown = false;
                moveLeft = false;
                moveRight = false;
            }
            break;
        }
        case 1:
        {
            //printf("Down ");
            if(!moveUp)
            {
                moveUp = false;
                moveDown = true;
                moveLeft = false;
                moveRight = false;
            }
            break;
        }
        case 2:
        {
            //printf("Left ");
            if(!moveRight)
            {
            moveUp = false;
            moveDown = false;
            moveLeft = true;
            moveRight = false;
            }
            break;
        }
        case 3:
        {
            //printf("Right ");
            if(!moveLeft)
            {
            moveUp = false;
            moveDown = false;
            moveLeft = false;
            moveRight = true;
            }
            break;
        }

    }
}

int Player::getScore()
{
    return score;
}

bool Player::getDead()
{
    return dead;
}
//=============================================================================

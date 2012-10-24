//==============================================================================
#include "Entity.h"

//==============================================================================
std::vector<Entity*> Entity::EntityList;

//==============================================================================
Entity::Entity() {
    ENTITY_SURF = NULL;

    x = y = 0.0f;

    width = height = 0;

    animState = 0;

    moveLeft = moveRight = moveUp = moveDown = false;

    type = ENTITY_TYPE_GENERIC;

    dead = false;

    flags = ENTITY_FLAG_NONE;

    speed = 0;

    accel = 0;

    maxSpeed = 5;

    currentFrameCol = currentFrameRow = 0;

    col_X = col_Y = 0;

    col_Width = col_Height =0;
}

Entity::~Entity()
{
}

//==============================================================================
bool Entity::load(char* file, int width, int height, int maxFrames) {
	if((ENTITY_SURF = Image::loadImage(file)) == NULL) {
		return false;
	}

	this->width = width;
	this->height = height;

	anim_Control.MaxFrames = maxFrames;

    return true;
}

//------------------------------------------------------------------------------
void Entity::logic() {
    //We're not moving
    if(moveDown == false && moveLeft == false && moveRight == false && moveUp == false)
    {
        stopMove();
    }
    if(moveLeft)
    {
        accel = 0.5;
    }
    if(flags & ENTITY_FLAG_GRAVITY)
    {
        //Flat Surface
    }
    speed += accel * FPS::FPSControl.getSpeedFactor();

    if(speed > maxSpeed)
        speed = maxSpeed;

    animate();
    move();
}

//------------------------------------------------------------------------------
void Entity::render(SDL_Surface* DISPLAY_SURF) {
    if(ENTITY_SURF == NULL || DISPLAY_SURF == NULL) return;

    Image::drawImage(DISPLAY_SURF, ENTITY_SURF, x, y, animState * width, anim_Control.GetCurrentFrame() * height, width, height);
}

//------------------------------------------------------------------------------
void Entity::cleanUp() {
    if(ENTITY_SURF) {
        SDL_FreeSurface(ENTITY_SURF);
    }

    ENTITY_SURF = NULL;
}

void Entity::animate()
{
    anim_Control.OnAnimate();
}

void Entity::move()
{
    if(moveUp == false && moveDown == false && moveLeft == false && moveRight == false)     //No direction to move in
    {
        return;
    }

    double newX = 0;
    double newY = 0;

    speed *= FPS::FPSControl.getSpeedFactor();
    if(moveUp == true ) {
            newY =  -FPS::FPSControl.getSpeedFactor();
	}
	else if(moveDown == true)
    {
        newY =  FPS::FPSControl.getSpeedFactor();
    }
    else if(moveLeft == true)
    {
        newX =  -FPS::FPSControl.getSpeedFactor();
    }
    else if(moveRight == true)
    {
        newX =  FPS::FPSControl.getSpeedFactor();
    }

		if(flags & ENTITY_FLAG_GHOST) {
			posValid((int)(x + newX), (int)(y + newY)); //We don't care about collisions, but we need to send events to other entities

			x += newX;
			y += newY;
		}else{
			if(posValid((int)(x + newX), (int)(y))) {
				x += newX;
			}else{
				speed = 0;
			}

			if(posValid((int)(x), (int)(y + newY))) {
				y += newY;
			}else{
				speed = 0;
			}
		}

		/*moveX += -newX;
		moveY += -newY;

		if(newX > 0 && moveX <= 0) newX = 0;
		if(newX < 0 && moveX >= 0) newX = 0;

		if(newY > 0 && moveY <= 0) newY = 0;
		if(newY < 0 && moveY >= 0) newY = 0;

		if(moveX == 0) newX = 0;
		if(moveY == 0) newY = 0;

		if(moveX == 0 && moveY 	== 0) 	break;
		if(newX  == 0 && newY 	== 0) 	break;*/

}

void Entity::stopMove()
{
    speed = 0;
    accel = 0;
}

bool Entity::posValid(int newX, int newY)
{
    bool returnVal = true;
    int startX 	= (newX + col_X);
	int startY 	= (newY + col_Y);

	int endX	= ((newX + col_X) + width - col_Width - 1);
	int endY	= ((newY + col_Y) + height - col_Height - 1);


	if(flags & ENTITY_FLAG_MAPONLY) {
	}else{
		for(size_t i = 0;i < EntityList.size();i++) {
			if(posValidEntity(EntityList[i], newX, newY) == false) {
				returnVal = false;
			}
		}
	}

	return returnVal;
}

bool Entity::posValidEntity(Entity* entity, int newX, int newY)
{
    if(this != entity && entity != NULL && entity->dead == false &&
		entity->flags ^ ENTITY_FLAG_MAPONLY &&
		entity->collides(newX + col_X, newY + col_Y, width - col_Width - 1, height - col_Height - 1) == true) {

		EntityCol EntityCol;

		EntityCol.EntityA = this;
		EntityCol.EntityB = entity;

		EntityCol::EntityColList.push_back(EntityCol);

		return false;
	}

	return true;
}

//==============================================================================

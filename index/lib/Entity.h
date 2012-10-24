//==============================================================================
#ifndef _ENTITY_H_
    #define _ENTITY_H_

#include <vector>

#include "Animation.h"
#include "Image.h"
#include "FPS.h"

//=============================
enum{
    ENTITY_TYPE_GENERIC =0,
    ENTITY_TYPE_PLAYER,
    ENTITY_TYPE_WALL
};
//==============================================================================
enum {
	ENTITY_FLAG_NONE 	= 0,

	ENTITY_FLAG_GRAVITY	= 0x00000001,
	ENTITY_FLAG_GHOST	= 0x00000002,
	ENTITY_FLAG_MAPONLY	= 0x00000004
};

//==============================================================================
class Entity {
    public:
        static std::vector<Entity*>    EntityList;

    protected:
        Animation      anim_Control;

        SDL_Surface*    ENTITY_SURF;

    public:
        float           x;
        float           y;

        int             width;
        int             height;

        int             animState;

        bool moveUp;
        bool moveLeft;
        bool moveRight;
        bool moveDown;

        int type;

        bool dead;

        int flags;

    protected:
        float speed;

        float accel;

        int currentFrameCol;
        int currentFrameRow;

        int col_X;
        int col_Y;
        int col_Width;
        int col_Height;

    public:
        float maxSpeed;

	public:
		Entity();

		virtual ~Entity();

	public:
        virtual bool load(char* file, int width, int height, int maxFrames);

        virtual void logic();

		virtual void render(SDL_Surface* DISPLAY_SURF);

		virtual void cleanUp();

		virtual void animate();

		void move();

		void stopMove();

		bool collides(int oX, int oY, int oW, int oH);

    private:

		bool posValid(int newX, int newY);

		bool posValidEntity(Entity* entity, int newX, int newY);
};

//==============================================================================

#endif

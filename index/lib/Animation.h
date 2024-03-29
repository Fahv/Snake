//==============================================================================
// Animation Class
//==============================================================================
#ifndef _ANIMATION_H_
    #define _ANIMATION_H_

#include <SDL.h>

//==============================================================================
class Animation {
	private:
		int	    CurrentFrame;

		int     FrameInc;

    private:
        int     FrameRate; //Milliseconds

		long    OldTime;

	public:
        int	    MaxFrames;

		bool	Oscillate;

	public:
		Animation();

		void OnAnimate();

	public:
        void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
};

//==============================================================================

#endif

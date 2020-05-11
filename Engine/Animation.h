/******************************************************************************
filename Animation.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 08 May 2020
Brief Description: A header file containing definitions for
Animation functions
******************************************************************************/

#ifndef ANIMATION_H
#define ANIMATION_H

class Animation
{
public:
	unsigned int index;
	unsigned int numFrames;
	unsigned int animationSpeed;

	/*Constructor*/
	Animation();
	Animation(int index, int numFrames, int animationSpeed);

};




#endif /*Animation.h*/

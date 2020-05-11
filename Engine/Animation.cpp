/******************************************************************************
filename Animation.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 08 May 2020
Brief Description: A Source file containing definitions for
Animation functions
******************************************************************************/

#include "Animation.h"

/*Constructor*/
Animation::Animation()
{

}

Animation::Animation(int index, int numFrames, int animationSpeed)
{
	(*this).index = index;
	(*this).numFrames = numFrames;
	(*this).animationSpeed = animationSpeed;
	
}
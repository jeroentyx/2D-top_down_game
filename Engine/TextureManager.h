/******************************************************************************
filename TextureManager.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A header file containing
TextureManager functions
******************************************************************************/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "Game.h"



class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture*, SDL_Rect sourceRectangle,
		SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif /*TextureManager.h*/

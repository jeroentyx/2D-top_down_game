/******************************************************************************
filename TextureManager.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A Source file containing definition for
TextureManager functions
******************************************************************************/
#include "TextureManager.h"
#include "SDL_image.h"




/*Function to load texture that takes in fileName, Returns a SDL_Texture*/
SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}


void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, texture, &sourceRectangle, &destinationRectangle, 0.0, NULL, flip);
}
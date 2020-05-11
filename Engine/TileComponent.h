/******************************************************************************
filename TileComponent.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 11 May 2020
Brief Description: A header file containing
tileComponent functions
******************************************************************************/

#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include <SDL.h>
#include "EntityManager.h"
#include "AssetManager.h"
#include "glm.hpp"


class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;
	glm::vec2 position;

	TileComponent(
		int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureID)
	{
		texture = Game::assetManager->GetTexture(assetTextureID);
		sourceRectangle.x = sourceRectX;
		sourceRectangle.y = sourceRectY;
		sourceRectangle.w = tileSize;
		sourceRectangle.h = tileSize;

		destinationRectangle.x = x;
		destinationRectangle.y = y;
		destinationRectangle.w = tileSize * tileScale;
		destinationRectangle.h = tileSize * tileScale;

		position.x = x;
		position.y = y;
	}
	/*Destructor*/
	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void Update(float deltaTime) override
	{
		destinationRectangle.x = position.x - Game::camera.x;
		destinationRectangle.y = position.y - Game::camera.y;

	}

	void Render() override
	{
		TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
	}
};


#endif /*TileComponent.h*/

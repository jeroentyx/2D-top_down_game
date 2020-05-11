/******************************************************************************
filename TransformComponent.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A header file containing
Transform Components functions
******************************************************************************/



#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "EntityManager.h"
#include "glm.hpp"
#include <SDL.h>
#include "Game.h"

/*Component that takes in positionX, positionY, velocityX, velocityY, width, height and scale*/
class TransformComponent : public Component
{
public:
	glm::vec2 position;
	glm::vec2 velocity;
	int width;
	int height;
	int scale;

	/*Constructor that takes in positionX, positionY, velocityX, velocityY, width, height and scale*/
	TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
	{
		/*Assign values*/
		position = glm::vec2(posX, posY);
		velocity = glm::vec2(velX, velY);
		width = w;
		height = h;
		scale = s;
	}

	void Initialize() override
	{

	}
	/*Update the position and velocity*/
	void Update(float deltaTime) override
	{
		position.x += velocity.x * deltaTime;
		position.y += velocity.y * deltaTime;

	}
	void Render() override
	{
		
	}
};

#endif /*TransformComponent.h*/

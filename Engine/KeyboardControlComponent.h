/******************************************************************************
filename KeyboardControlComponent.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 08 May 2020
Brief Description: A header file containing
KeyboardControlComponent functions
******************************************************************************/

#ifndef KEYBOARDCONTROLCOMPONENT_H
#define KEYBOARDCONTROL_COMPONENT_H

#include "Game.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

/*Component that takes in upKey,leftKey,downKey,rightKey ,shootKey*/
class KeyboardControlComponent :public Component
{
public:
	/*Variable declaration*/
	std::string upKey;
	std::string leftKey;
	std::string downKey;
	std::string rightKey;
	std::string shootKey;

	TransformComponent *transform;
	SpriteComponent *sprite;

	/*Constructor*/
	KeyboardControlComponent()
	{

	}
	KeyboardControlComponent(
		std::string upKey, std::string leftKey, std::string downKey, std::string rightKey, std::string shootKey)
	{

		(*this).upKey = GetSDLKeyStringCode(upKey);
		(*this).leftKey = GetSDLKeyStringCode(leftKey);
		(*this).downKey = GetSDLKeyStringCode(downKey);
		(*this).rightKey = GetSDLKeyStringCode(rightKey);
		(*this).shootKey = GetSDLKeyStringCode(shootKey);
	}

	/*Function that takes in a string and return a SDL String*/
	std::string GetSDLKeyStringCode(std::string key)
	{
		/*Check for key. return string code*/
		if (key.compare("up") == 0)
			return "1073741906";
		if (key.compare("down") == 0)
			return "1073741905";
		if (key.compare("left") == 0)
			return "1073741904";
		if (key.compare("right") == 0)
			return "1073741903";

		if (key.compare("space") == 0)
			return "32";
		/*Return integer if it is neither of the keys*/
		return std::to_string(static_cast<int>(key[0]));

	}

	void Initialize() override 
	{
		transform = (*owner).GetComponent<TransformComponent>();
		sprite = (*owner).GetComponent<SpriteComponent>();
	}

	void Update(float deltaTime) override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			std::string keyCode = std::to_string(Game::event.key.keysym.sym);

			if (keyCode.compare(upKey) == 0)
			{
				(*transform).velocity.y = -100;
				(*transform).velocity.x = 0;
				(*sprite).Play("UpAnimation");
			}
			if (keyCode.compare(rightKey) == 0)
			{
				(*transform).velocity.y = 0;
				(*transform).velocity.x = 100;
				(*sprite).Play("RightAnimation");
			}
			if (keyCode.compare(leftKey) == 0)
			{
				(*transform).velocity.y = 0;
				(*transform).velocity.x = -100;
				(*sprite).Play("LeftAnimation");
			}
			if (keyCode.compare(downKey) == 0)
			{
				(*transform).velocity.y = 100;
				(*transform).velocity.x = 0;
				(*sprite).Play("DownAnimation");
			}
			if (keyCode.compare(shootKey) == 0)
			{
			
				/*TODO*/
				/*Shoot projectile*/
			}
		}

		/*Check if the key is released*/
		if (Game::event.type == SDL_KEYUP)
		{
			/*Read keyboard input*/
			std::string keyCode = std::to_string(Game::event.key.keysym.sym);

			if (keyCode.compare(upKey) == 0)
			{
				(*transform).velocity.y = 0;
			}
			if (keyCode.compare(rightKey) == 0)
			{
				(*transform).velocity.x = 0;
			}
			if (keyCode.compare(leftKey) == 0)
			{
				(*transform).velocity.x = 0;
			}
			if (keyCode.compare(downKey) == 0)
			{
				(*transform).velocity.y = 0;
			}
			
		}
	}

	void Render() override
	{

	}
	

};
#endif /*KeyboardControlComponent.h*/

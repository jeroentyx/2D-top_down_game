/******************************************************************************
filename SpriteComponent.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A header file containing
SpriteComponent functions
******************************************************************************/


#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL.h>
#include "TextureManager.h"
#include "AssetManager.h"
#include "Animation.h"
#include "TransformComponent.h"

/*Component that takes in assetTextureID*/
/*Component that takes in assetTextureID, numFrames ,animationSpeed, hasDirections, isFixed*/
class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;


	/*Check if the image is animated*/
	bool isAnimated;

	int numFrames;
	int animationSpeed;


	/*Check if the image is not moving*/
	bool isFixed;

	/*Map to keep track of different animations*/
	std::map<std::string, Animation> animations;
	std::string currentAnimationName;
	unsigned int animationIndex = 0;


public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	/*Constructor*/
	SpriteComponent(std::string assetTextureID)
	{
		(*this).isAnimated = false;
		(*this).isFixed = false;
		SetTexture(assetTextureID);
	}

	/*Constructor*/
	SpriteComponent(std::string assetTextureID, bool isFixed)
	{
		(*this).isAnimated = false;
		(*this).isFixed = isFixed;
		SetTexture(assetTextureID);
	}

	/*Constructor has directions and animationSpeed*/
	SpriteComponent(
		std::string id, int numFrames, int animationSpeed, bool hasDirection, bool isFixed)
	{
		(*this).isAnimated = true;
		(*this).numFrames = numFrames;
		(*this).animationSpeed = animationSpeed;
		(*this).isFixed = isFixed;

		/*Check if Sprite has directions*/
		if (hasDirection)
		{
			Animation downAnimation = Animation(0, numFrames, animationSpeed);
			Animation rightAnimation = Animation(1, numFrames, animationSpeed);
			Animation leftAnimation = Animation(2, numFrames, animationSpeed);
			Animation upAnimation = Animation(3, numFrames, animationSpeed);

			animations.emplace("DownAnimation", downAnimation);
			animations.emplace("RightAnimation", rightAnimation);
			animations.emplace("LeftAnimation", leftAnimation);
			animations.emplace("UpAnimation", upAnimation);

			/*Everytime constructor is called, direction is defaulted to be be down*/
			(*this).animationIndex = 0;
			(*this).currentAnimationName = "DownAnimation";
		}
		else
		{
			Animation singleAnimation = Animation(0, numFrames, animationSpeed);
			animations.emplace("singleAnimation", singleAnimation);

			(*this).animationIndex = 0;
			(*this).currentAnimationName = "singleAnimation";
		}

		/*Play Animation*/
		Play((*this).currentAnimationName);

		SetTexture(id);

	}




	/*Function to play animation*/
	void Play(std::string animationName)
	{
		numFrames = animations[animationName].numFrames;
		animationIndex = animations[animationName].index;
		animationSpeed = animations[animationName].animationSpeed;
		currentAnimationName = animationName;
	}

	/*Setter*/
	void SetTexture(std::string assetTextureID)
	{
		texture = Game::assetManager->GetTexture(assetTextureID);
	}


	void Initialize() override
	{
		/*Keep track of transformComponent*/
		transform = (*owner).GetComponent<TransformComponent>();
		sourceRectangle.x = 0;
		sourceRectangle.y = 0;
		sourceRectangle.w = (*transform).width;
		sourceRectangle.h = (*transform).height;
	}

	void Update(float deltaTime) override
	{
		/*Check if it is Animated*/
		if (isAnimated)
		{
			sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);

		}
		sourceRectangle.y = animationIndex * (*transform).height;

		destinationRectangle.x = static_cast<int>((*transform).position.x) - (isFixed ? 0 :
			Game::camera.x);
		destinationRectangle.y = static_cast<int>((*transform).position.y) - (isFixed ? 0 :
			Game::camera.y);

		destinationRectangle.w = (*transform).width *  (*transform).scale;
		destinationRectangle.h = (*transform).width *  (*transform).scale;
	}

	void Render() override
	{
		TextureManager::Draw(
			texture, sourceRectangle, destinationRectangle, spriteFlip);

	}
};


#endif /*SpriteComponent.h*/
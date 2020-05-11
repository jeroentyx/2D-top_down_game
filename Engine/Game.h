/******************************************************************************
filename Game.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A header file containing
Game loop function
******************************************************************************/



#ifndef  GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Component.h"
#include "EntityManager.h"


class AssetManager;

class Game {

private:
	bool isRunning;
	SDL_Window *window;

public:
	/*Game constructor*/
	Game();
	/*Destructor*/
	~Game();

	bool IsRunning() const;

	static SDL_Renderer* renderer;
	static AssetManager* assetManager;
	static SDL_Event event;
	static SDL_Rect camera;


	void LoadLevel(int levelNumber);

	/*Getter*/
	unsigned int ticksLastFrame;


	void Initialize(int width, int height);
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
	void HandleCameraMovement();

};

#endif /*Game.h*/

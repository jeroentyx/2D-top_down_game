/******************************************************************************
filename Game.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Source file containing definitions for
Game loop functions
******************************************************************************/


#include <SDL.h>
#include <iostream>
#include "Game.h"
#include "AssetManager.h"
#include "Map.h"
#include "Constants.h"
#include "TransformComponent.h"
#include "glm.hpp"
#include "SpriteComponent.h"
#include "KeyboardControlComponent.h"
#include "SDL_image.h"





EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
SDL_Rect Game::camera = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
Map* map;

/*Constructor*/
Game::Game()
{
	(*this).isRunning = false;
}

/*Destructor*/
Game::~Game()
{

}

/*Getter*/
bool Game::IsRunning() const
{
	return (*this).isRunning;
}





void Game::Initialize(int width, int height)
{
	/*Check if SDL Init is initialised*/
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		/*Print Error message*/
		std::cerr << "Error initializing SDL..." << std::endl;
		return;
	}

	/*Check if SDL Init is initialised*/
	if (!(IMG_Init(IMG_INIT_PNG)& IMG_INIT_PNG))
	{
		/*Print Error message*/
		std::cerr << "Failed to initialise SDL_Image for PNG file " <<
			std::endl << IMG_GetError() << std::endl;
	}

	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS
	);


	/*Check if window is valid*/
	if (!window)
	{
		std::cerr << "Error creating SDL window" << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	/*Check if renderer is valid*/
	if (!renderer) {
		std::cerr << " Error creating SDK renderer" << std::endl;
		return;
	}

	LoadLevel(0);

	isRunning = true;
	return;

}

Entity& player(manager.AddEntity("chopper", PLAYER_LAYER));

/*Function to Load level*/
void Game::LoadLevel(int levelNumber)
{
	/*Add new assets to AssetManager List*/

	/*Add texture by creating a new string and pass in as c string*/
	(*assetManager).AddTexture("tank-image", std::string(
		"./Assets/Images/tank-big-right.png").c_str());

	(*assetManager).AddTexture("chopper-image", std::string(
		"./Assets/Images/chopper-spritesheet.png").c_str());

	(*assetManager).AddTexture("radar-image", std::string(
		"./Assets/Images/radar.png").c_str());
	(*assetManager).AddTexture("jungle-tiletexture", std::string(
		"./Assets/Tilemaps/jungle.png").c_str());

	map = new Map("jungle-tiletexture", 2, 32);

	(*map).LoadMap("./Assets/Tilemaps/jungle.map", 25, 20);




	/*Add Entities*/

	Entity& tankEntity(manager.AddEntity("tank", ENEMY_LAYER));
	tankEntity.AddComponent<TransformComponent>(240, 500, 20, 0, 32, 32, 1);
	tankEntity.AddComponent<SpriteComponent>("tank-image");

	player.AddComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
	player.AddComponent<SpriteComponent>("chopper-image", 2, 90, true, false);
	player.AddComponent<KeyboardControlComponent>("up", "left", "down", "right", "space");

	Entity& radarEntity(manager.AddEntity("radar", UI_LAYER));
	radarEntity.AddComponent<TransformComponent>(720, 30, 0, 0, 64, 64, 1);
	radarEntity.AddComponent<SpriteComponent>("radar-image", 8, 150, false, true);










	return;
}

void Game::ProcessInput()
{

	/*Check the reference of the event*/
	SDL_PollEvent(&event);

	/*Check for input*/
	switch (event.type)
	{
	case SDL_QUIT: {
		/*Set isRunning to false*/
		isRunning = false;
		break;
	}
	case SDL_KEYDOWN:
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			/*Set isRunning to false*/
			isRunning = false;
		}
	}
	default:
		break;


	}

}

/*Update the Game object*/
void Game::Update()
{
	/*Compare current time with ticks last frame */
	int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
		SDL_Delay(timeToWait);



	/*Delta time is the difference in ticks from last frame*/
	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	/*Clamp Deltatime*/
	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

	/*Set new ticks for current frame*/
	ticksLastFrame = SDL_GetTicks();

	/*Loop all the entities and component to update*/
	manager.Update(deltaTime);

	HandleCameraMovement();

}

void Game::Render()
{
	/*Set the background color*/
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	/*Clear the back buffer*/
	SDL_RenderClear(renderer);


	/*Check if manager has entity*/
	if (manager.HasNoEntities()) {
		return;
	}

	/*Call manager to render all entities*/
	manager.Render();




	/*Swap front and back buffer*/
	SDL_RenderPresent(renderer);
}

void Game::HandleCameraMovement() {
	TransformComponent* mainPlayerTransform = player.GetComponent<TransformComponent>();
	camera.x = mainPlayerTransform->position.x - (WINDOW_WIDTH / 2);
	camera.y = mainPlayerTransform->position.y - (WINDOW_HEIGHT / 2);

	/*Clamp the camera*/
	camera.x = camera.x < 0 ? 0 : camera.x;
	camera.y = camera.y < 0 ? 0 : camera.y;

	camera.x = camera.x > camera.w ? camera.w : camera.x;
	camera.y = camera.y > camera.h ? camera.h : camera.y;

}
void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
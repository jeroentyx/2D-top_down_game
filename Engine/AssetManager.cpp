/******************************************************************************
filename AssetManager.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A Source file containing definition for 
AssetManager functions
******************************************************************************/

#include "AssetManager.h"
#include "TransformComponent.h"

/*Constructor*/
AssetManager::AssetManager(EntityManager* manager) :manager(manager)
{

}

/*Function to Clear data*/
void AssetManager::ClearData()
{
	/*Clear the map of textures*/
	textures.clear();
}

/*Function to add texture that takes in textureID and filePath*/
void AssetManager::AddTexture(std::string textureID, const char* filePath)
{
	/*Push the textureID to the map*/
	textures.emplace(textureID, TextureManager::LoadTexture(filePath));
}

/*Function to Get textures that takes in textureID and return textures*/
SDL_Texture* AssetManager::GetTexture(std::string textureID)
{
	return textures[textureID];
}

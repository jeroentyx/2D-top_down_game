/******************************************************************************
filename AssetManager.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A header file containing
AssetManager functions
******************************************************************************/


#ifndef  ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include "TextureManager.h"
#include "EntityManager.h"


class AssetManager
{
private:
	EntityManager* manager;
	/*This is the textures in the AssetManager*/
	std::map<std::string, SDL_Texture*> textures;
public:
	/*Constructor*/
	AssetManager(EntityManager* manager);
	/*Destroyer*/
	~AssetManager();

	/*Function to Clear AssetManager*/
	void ClearData();
	/*Function to Add texture*/
	void AddTexture(std::string textureID, const char* filePath);
	/*Function to Get texture*/
	SDL_Texture* GetTexture(std::string textureID);

};



#endif /*AssetManager.h*/

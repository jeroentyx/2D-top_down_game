/******************************************************************************
filename Map.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 11 May 2020
Brief Description: A Source file containing
definitions for Map functions
******************************************************************************/
#include <fstream>
#include "Map.h"
#include "Game.h"
#include "EntityManager.h"
#include "TileComponent.h"

extern EntityManager manager;

/*Constructor that takes in textureID, scale and tileSize*/
Map::Map(std::string textureID, int scale, int tileSize)
{
	(*this).textureID = textureID;
	(*this).scale = scale;
	(*this).tileSize = tileSize;
}

/*Function to Load map, that takes in filePath, mapSizeX and mapSizeY*/
void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
	std::fstream mapFile;
	mapFile.open(filePath);

	for (int y = 0; y < mapSizeY; y++)
	{
		for (int x = 0; x < mapSizeX; x++)
		{
			char ch;
			mapFile.get(ch);
			int sourceRectY = atoi(&ch) * tileSize;
			mapFile.get(ch);
			int sourceRectX = atoi(&ch) * tileSize;
			AddTile(sourceRectX, sourceRectY, x * (scale*tileSize), y * (scale*tileSize));
			/*Ignore the commas*/
			mapFile.ignore();
		}
	}
	/*Close the file*/
	mapFile.close();
}

/*Function to Add tiles that takes in the sourceRectX, sourceRectY,width and height*/
void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y)
{
	Entity& newTile(manager.AddEntity("Tile",TILEMAP_LAYER));
	newTile.AddComponent<TileComponent>(sourceRectX, sourceRectY, x, y, tileSize, scale, textureID);
}


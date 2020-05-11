/******************************************************************************
filename Map.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 11 May 2020
Brief Description: A header file containing
Map functions
******************************************************************************/


#ifndef MAP_H
#define MAP_H


#include <string>

/*Class that takes in textureID, scale and tileSize*/
class Map
{
private:
	int scale;
	int tileSize;
	std::string textureID;
public:
	/*Constructor*/
	Map(std::string textureID, int scale, int tileSize);
	/*Destructor*/
	~Map();

	/*Function that takes in filePath, tilesX and tilesY*/
	void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);

	void AddTile(int sourceRectX, int sourceRectY, int x, int y);

};


#endif /*Map.h*/

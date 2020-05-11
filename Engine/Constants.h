/******************************************************************************
filename Constants.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Header file containing values
for Constants variables
******************************************************************************/


#ifndef CONSTANTS_H
#define CONSTANTS_H

/*Variable declaration*/
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

/*Keep the frames per second constant*/
const unsigned int FPS = 60;

/*The time it takes to render one frame*/
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

enum LayerType {
	TILEMAP_LAYER,
	VEGETATION_LAYER,
	ENEMY_LAYER,
	PLAYER_LAYER,
	PROJECTILE_LAYER,
	UI_LAYER,
};

const unsigned int NUM_LAYERS = 6;








#endif /*CONSTANTS_H*/

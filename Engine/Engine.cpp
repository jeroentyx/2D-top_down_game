/******************************************************************************
filename Engine.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Source file for main function
******************************************************************************/


#include <iostream>
#include "Game.h"
#include "Constants.h"

int main(int argc, char *argv[])
{
	/*Variable Declaration*/
	Game *game = new Game();

	(*game).Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

	/*Check if Game is running*/
	while ((*game).IsRunning())
	{
		(*game).ProcessInput();
		(*game).Update();
		(*game).Render();
	}



	(*game).Destroy();
	return 0;
}
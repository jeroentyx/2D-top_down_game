/******************************************************************************
filename Component.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Header file containing 
Components functions
******************************************************************************/


#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
public:
	Entity* owner;
	virtual ~Component() {}
	virtual void Initialize() {}
	virtual void Update(float deltaTime) {}
	virtual void Render() {}

};



#endif /*Component.c*/

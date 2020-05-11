/******************************************************************************
filename EntityManager.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A header file containing
EntityManager functions
******************************************************************************/


#ifndef  ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Constants.h"
#include "Component.h"
#include <vector>

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	/*Destroy all entries*/
	void ClearData();

	/*Function that updates entity*/
	void Update(float deltaTime);

	void Render();

	/*Function to set entity to 0*/
	bool HasNoEntities();



	/*Function to add entity, takes in entity name*/
	Entity& AddEntity(std::string entityName,LayerType layer);

	/*Get the Number of Entity*/
	unsigned int GetEntityCount();

	std::vector<Entity*> GetEntities() const;
	std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;

	/*Function to list all Entities components*/
	void ListAllEntities() const;



	




};
#endif /*EntityManager.h*/

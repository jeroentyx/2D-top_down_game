/******************************************************************************
filename EntityManager.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Source file containing definitions for
EntityManager functions
******************************************************************************/


#include <iostream>
#include "EntityManager.h"
#include "Constants.h"

/*Destroy all entities*/
void EntityManager::ClearData()
{
	for (auto& entity : entities)
	{
		(*entity).Destroy();
	}
}
/*Function to set entity to 0*/
bool EntityManager::HasNoEntities()
{
	return entities.size() == 0;
}

/*Function that updates entity*/
void EntityManager::Update(float deltaTime)
{
	/*Loop till the end of entities and update*/
	for (auto& entity : entities)
	{
		(*entity).Update(deltaTime);
	}
}

void EntityManager::Render()
{
	for (int layerNumber = 0; layerNumber < NUM_LAYERS; layerNumber++)
	{
		for (auto& entity : GetEntitiesByLayer(static_cast<LayerType>(layerNumber)))
		{
			(*entity).Render();
		}
	}
	return;
}

/*Function to add entity, takes in entity name*/
Entity& EntityManager::AddEntity(std::string entityName,LayerType layer)
{
	/*Create entities*/
	Entity *entity = new Entity(*this, entityName,layer);
	/*Push entities to vector*/
	entities.emplace_back(entity);
	return *entity;
}

/*Function that return list of entities*/
std::vector<Entity*> EntityManager::GetEntities() const
{
	return entities;
}

std::vector<Entity*>EntityManager::GetEntitiesByLayer(LayerType layer) const
{
	std::vector<Entity*>selectedEntities;
	for (auto& entity : entities) 
	{
		/*Check if the layers matched*/
		if ((*entity).layer == layer)
		{
			selectedEntities.emplace_back(entity);
		}
	}
	return selectedEntities;
}


/*Function to print all entities and components*/
void EntityManager::ListAllEntities() const
{
	unsigned int curr = 0;

	/*Loop till the end of entities and update*/
	for (auto& entity : entities)
	{
		std::cout << "Entity[" << curr << "]: " << (*entity).name << std::endl;
		(*entity).ListAllComponents();
		curr++;
	}
}

/*Get the Number of Entity*/
unsigned int EntityManager::GetEntityCount() {
	return entities.size();
}



/******************************************************************************
filename Entity.cpp
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 06 May 2020
Brief Description: A Source file containing definitions for
Entity functions
******************************************************************************/

#include "Entity.h"
#include <iostream>

/*Constructor, Initiate EntityManager*/
Entity::Entity(EntityManager& manager) : manager(manager)
{
	/*Set this instance as active*/
	(*this).isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name,LayerType layer) : manager(manager), name(name) ,layer(layer)
{
	
	(*this).isActive = true;
}

void Entity::Update(float deltaTime)
{
	for (auto& component : components)
	{
		(*component).Update(deltaTime);
	}
}

void Entity::Render()
{
	for (auto& component : components)
	{
		(*component).Render();
	}
}

void Entity::Destroy()
{
	(*this).isActive = false;
}

bool Entity::IsActive() const
{
	return (*this).isActive;
}

void Entity::ListAllComponents() const 
{
	for (auto mapElement : componentTypeMap)
		std::cout << "Components <" << mapElement.first->name() << ">" << std::endl;

}
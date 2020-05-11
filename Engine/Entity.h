/******************************************************************************
filename Entity.h
author Jeroen Tan
email yixujeroen.tan@digipen.edu
date created 07 May 2020
Brief Description: A Header file containing
Entity functions
******************************************************************************/



#ifndef  ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <map>
#include "EntityManager.h"
#include "Component.h"
#include "Constants.h"



class EntityManager;
class Component;

class Entity {
private:
	/*Reference to EntityManager*/
	EntityManager& manager;
	/*Check if Entity is active*/
	bool isActive;
	std::vector<Component*> components;
	/*Map to Keep track component and component type*/
	std::map<const std::type_info*, Component*> componentTypeMap;
public:
	std::string name;
	/*Constructor*/
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name,LayerType layer);
	LayerType layer;

	void Update(float deltaTime);
	void Render();
	void Destroy();

	/*Getter*/
	bool IsActive() const;

	/*Function to print Entity Components*/
	void ListAllComponents() const;

	/*Template*/
	template<typename T>
	bool HasComponent() const {
		/*TODO*/
	}

	/*Template that takes in arguments...*/
	template <typename T, typename... TArgs>
	/*AddComponent takes in arguments*/
	T& AddComponent(TArgs&&...args) {
		/*new T will takes in parameters from arguments*/
		T* newComponent(new T(std::forward<TArgs>(args)...));
		(*newComponent).owner = this;
		/*Push newComponents to the list of components*/
		components.emplace_back(newComponent);
		/*Keep track of all components by typeID*/
		componentTypeMap[&typeid(*newComponent)] = newComponent;
		(*newComponent).Initialize();
		/*Return the object*/
		return *newComponent;

	}

	template <typename T>
	T* GetComponent()
	{
		return static_cast<T*>(componentTypeMap[&typeid(T)]);
	}



};

#endif /*Entity.h*/

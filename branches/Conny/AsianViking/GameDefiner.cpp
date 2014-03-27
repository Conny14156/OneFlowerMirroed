#include "Game.h"
#include "GameObject.h"

//Find the first gameobject pointer inside the gameObjectMap and return the first positive match
GameObject* Game::RequestGameObject(std::string name)
{
	std::map<unsigned int, GameObject*>::iterator it = allGameObjectMap.begin();
	for (int i = 0; it != this->allGameObjectMap.end(); i++)
	{
		if (it->second->name == name)
			return it->second;
	}
	return nullptr;
}


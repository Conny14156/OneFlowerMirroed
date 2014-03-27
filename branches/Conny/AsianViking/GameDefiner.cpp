#include "Game.h"
#include "GameObject.h"
Game gameManager;
//Find the first gameobject pointer inside the gameObjectMap and return the first positive match
GameObject* Game::requestGameObject(std::string name)
{
	for (int i = 0; i < allGameObjectList.size(); i++)
		if (allGameObjectList.at(i)->name == name)
			return allGameObjectList.at(i);	
	return nullptr;
}
const std::vector<GameObject*>* Game::requestAllGameObjecVector() const 
{
	return &allGameObjectList;
}
const Game* requestGame()
{
	return &gameManager;
}
Game* setGame()
{
	return &gameManager;
}





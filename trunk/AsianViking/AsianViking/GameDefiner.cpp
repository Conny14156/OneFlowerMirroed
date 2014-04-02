#include "Game.h"
#include "GameObject.h"
#include "RenderHandler.h"
Game gameManager;
std::vector<GameObject> allGameObjectVector;

void Game::addGameObject(GameObject* entity)
{
	_allGameObjectVector.push_back(entity);
	SetGfx()->insertDrawableObject(entity);
}
void Game::addGameObject(std::string name)
{
	GameObject entity(name);
	/*
	allGameObjectVector.push_back(entity);
	this->_allGameObjectVector.push_back(&allGameObjectVector.at(allGameObjectVector.size() - 1));
	SetGfx()->insertDrawableObject(&allGameObjectVector.at(allGameObjectVector.size()-1));
	//*/
}
void Game::requestRemoveal(GameObject* entity)
{
	for (int i = 0; i < _allGameObjectVector.size(); i++)
	{
		if (_allGameObjectVector[i] == entity)
		{
			_allGameObjectVector.erase(_allGameObjectVector.begin()+i);
			delete entity;
			entity = 0;   
			break;
		}
	}
}

//Find the first gameobject pointer inside the gameObjectMap and return the first positive match
GameObject* Game::requestGameObject(std::string name)
{
	for (int i = 0; i < allGameObjectVector.size(); i++)
		if (allGameObjectVector.at(i).name == name)
			return &allGameObjectVector.at(i);
	return NULL;
}



const std::vector<GameObject>* Game::requestAllGameObjecVector() const 
{
	return &allGameObjectVector;
}
const Game* RequestGame()
{
	return &gameManager;
}
Game* SetGame()
{
	return &gameManager;
}
#include <Windows.h>
#include <list>
#include <math.h>
#include "Window.h"
#include "RenderHandler.h"
#include "Game.h"
#include "GameObject.h"
#include "Component\RenderComponent.h"
Gfx gfx;
bool Gfx::loadTexture(std::string name)
{
	
	sf::Texture tempTexture;
	if (!tempTexture.loadFromFile(name))
	{
		MessageBox(0, "Error loading this file", name.c_str(), MB_OK);
		return false;
	}	
	loadedTextureMap.insert(loadedTextureMap.end(),std::make_pair(name, tempTexture));
		
	return true;

}
const sf::Texture* Gfx::requestTexture(std::string name) const
{
	std::map<std::string, sf::Texture>::const_iterator it;
	it = loadedTextureMap.find(name);
	if (it != loadedTextureMap.end())
		return &it->second;
	return false;
}
void Gfx::insertDrawableObject(GameObject* entityToDraw)
{
	std::map<int, std::vector<GameObject*>>::iterator it;
	int renderID = 5; // entityToDraw->GetComponent<RenderComponent>()->renderlayer;
	it = this->gameObjectDrawList.find(renderID);
	if (it != this->gameObjectDrawList.end())
		it->second.insert(it->second.end(),entityToDraw);
	else
	{
		for (it = gameObjectDrawList.begin(); it != this->gameObjectDrawList.end(); it++)
		{
			if (renderID > it->first)
			{
				if (renderID < it->first + 1)
				{
					gameObjectDrawList.insert	(
													gameObjectDrawList.begin(),
													std::pair	<
																	int,
																	std::vector<GameObject*>
																>//the type of the pair
																	(
																		renderID,
																		{
																			{ entityToDraw }
																		}//For list SequenceClass 
																	)//Constructor value for std::pair
												);//for insert
				}
			}
		}
	}
}

void Gfx::Draw()
{

//	std::list<std::list<GameObject>> drawOrder;
	/*
	for (int i = 0; i < RequestGame()->requestAllGameObjecVector()->size(); i++)
	{
		//SetWindow()->draw(RequestGame()->requestAllGameObjectMap()->at(i));
		
	}
	//*/
}




//ReadOnly, Returns a const value pointer towards gfx
const Gfx* RequestGfx()
{
	return &gfx;
}

//Returns a value pointer toward gfx
Gfx* SetGfx()
{
	return &gfx;
}
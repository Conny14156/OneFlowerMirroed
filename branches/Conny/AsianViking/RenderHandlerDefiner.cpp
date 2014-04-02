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
	int renderID = entityToDraw->GetComponent<RenderComponent>()->renderlayer;



	std::map < int, std::vector<GameObject*>>::iterator endIt;

	endIt = gameObjectDrawList.end();
	it = this->gameObjectDrawList.find(renderID);






	if (it == this->gameObjectDrawList.end())
		gameObjectDrawList.insert(gameObjectDrawList.end(), std::pair<int, std::vector<GameObject*>>(renderID, {entityToDraw}));							//it->second.insert(it->second.end(),entityToDraw);
	else if (it != gameObjectDrawList.end())
	{
		bool temp = false; //Rework this, Somehow: check .end()->first < renderID
		#pragma region EntityToDrawInsertionBetween layers
		for (it = gameObjectDrawList.begin(); it != gameObjectDrawList.end(); it++)
		{
			if (renderID > it->first)
			{
				if (renderID < 1 + it->first)
				{
					gameObjectDrawList.insert
											(	gameObjectDrawList.begin(),
												std::pair<int, std::vector<GameObject*>>(renderID, { entityToDraw })
											);
					temp = true;
					break;
				}
			}
		}
		#pragma endregion
		if(!temp)
			gameObjectDrawList.at(renderID).push_back(entityToDraw);
		
	}
}

void Gfx::Draw()
{
	/*

	std::map<int, std::vector<GameObject*>>::iterator it;
	it = gameObjectDrawList.begin();
	it->second.at(0);
	gameObjectDrawList.at(0).at(0);
	//*/
	for (std::map<int, std::vector<GameObject*>>::iterator it = gameObjectDrawList.begin(); it != gameObjectDrawList.end(); it++)
		for (int j = 0; j < it->second.size(); j++)
		{
			SetWindow()->draw(it->second[j]->GetComponent<RenderComponent>()->sprite);
			SetEditWindow()->draw(it->second[j]->GetComponent<RenderComponent>()->sprite);
		}
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
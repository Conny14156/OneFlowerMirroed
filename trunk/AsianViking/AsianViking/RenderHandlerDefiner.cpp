#include "RenderHandler.h"
#include <Windows.h>
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
	{
		return &it->second;
	}
	return false;
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
#ifndef RenderComponent_H
#define RenderComponent_H
#include <SFML\Graphics\Sprite.hpp>	
#include "BaseComponent.h"
class RenderComponent : BaseComponent
{
public:
	const std::string componentName = "RenderComponent";
	sf::Sprite sprite;
	int renderlayer = 0;
private:

};




#endif
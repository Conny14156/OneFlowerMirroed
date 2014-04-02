#ifndef RenderComponent_H
#define RenderComponent_H
#include <SFML\Graphics\Sprite.hpp>	
#include "BaseComponent.h"
class RenderComponent : public BaseComponent
{
public:
	const std::string componentName = "RenderComponent";
	sf::Sprite sprite;
	int renderlayer = 1;
	std::string getTypeName();
private:

};




#endif
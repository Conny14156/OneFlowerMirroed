#ifndef RenderComponent_H
#define RenderComponent_H
#include <SFML\Graphics\Sprite.hpp>	
#include "BaseComponent.h"
class RenderComponent : BaseComponent
{
public:
	RenderComponent();
	~RenderComponent();
	sf::Sprite sprite;
private:
	const std::string componentName = "RenderComponent";

};




#endif
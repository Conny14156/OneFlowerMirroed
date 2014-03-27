#include "RenderComponent.h"
#include <SFML/System/Vector2.hpp>
#include <SFML\Graphics.hpp> //find specific include for getSize

RenderComponent::RenderComponent()
{
	sf::Vector2u size = sprite.getTexture()->getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);
}

RenderComponent::~RenderComponent()
{
}
#ifndef EnvironmentColliderComponent_H
#define EnvironmentColliderComponent_H
#include <SFML\Graphics\Sprite.hpp>
#include "BaseComponent.h"

class EnvironmentColliderComponent : public BaseComponent
{
public:
	std::string getTypeName();
	void environmentCollision(sf::Sprite *movingSprite, sf::Sprite obstacleSprite);
private:
	const std::string componentName = "EnvironmentColliderComponent";
};

#endif
#include "EnvironmentColliderComponent.h"

std::string EnvironmentColliderComponent::getTypeName() {
	return componentName;
}

void EnvironmentColliderComponent::environmentCollision(sf::Sprite *movingSprite, sf::Sprite obstacleSprite) {

	float deltaX = movingSprite->getPosition().x - obstacleSprite.getPosition().x;
	float deltaY = movingSprite->getPosition().y - obstacleSprite.getPosition().y;

	double angleInDegrees = atan2(deltaY, deltaX) * 180 / 3.1415926;

	if (angleInDegrees > -45 && angleInDegrees < 45)
		movingSprite->setPosition(obstacleSprite.getPosition().x + (obstacleSprite.getOrigin().x + movingSprite->getOrigin().x),
		movingSprite->getPosition().y);
	if (angleInDegrees > 135 || angleInDegrees < -135)
		movingSprite->setPosition(obstacleSprite.getPosition().x - (obstacleSprite.getOrigin().x + movingSprite->getOrigin().x),
		movingSprite->getPosition().y);
	if (angleInDegrees > -135 && angleInDegrees < -45)
		movingSprite->setPosition(movingSprite->getPosition().x,
		obstacleSprite.getPosition().y - (obstacleSprite.getOrigin().y + movingSprite->getOrigin().y));
	if (angleInDegrees > 45 && angleInDegrees < 135)
		movingSprite->setPosition(movingSprite->getPosition().x,
		obstacleSprite.getPosition().y + (obstacleSprite.getOrigin().y + movingSprite->getOrigin().y));
}
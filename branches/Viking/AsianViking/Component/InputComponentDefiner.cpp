#include "InputComponent.h"

std::string InputComponent::getTypeName() {
	return componentName;
}

InputComponent::InputComponent() {
	jump = sf::Keyboard::Up;
	duck = sf::Keyboard::Down;
	moveLeft = sf::Keyboard::Left;
	moveRight = sf::Keyboard::Right;
	spellSlots[0] = sf::Keyboard::Num1;
	spellSlots[1] = sf::Keyboard::Num2;
	spellSlots[2] = sf::Keyboard::Num3;
	spellSlots[3] = sf::Keyboard::Num4;
	spellSlots[4] = sf::Keyboard::Num5;
	inventory = sf::Keyboard::I;
	action = sf::Mouse::Left;
}

void InputComponent::moveSprite(sf::Sprite *sprite, float moveSpeedX, float moveSpeedY, float deltaTime) {
	float moveX = 0, moveY = 0;

	if (sf::Keyboard::isKeyPressed(jump))
		moveY -= moveSpeedY * deltaTime;
	if (sf::Keyboard::isKeyPressed(duck))
		moveY += moveSpeedY * deltaTime;
	if (sf::Keyboard::isKeyPressed(moveLeft))
		moveX -= moveSpeedX * deltaTime;
	if (sf::Keyboard::isKeyPressed(moveRight))
		moveX += moveSpeedX * deltaTime;

	sprite->move(moveX, moveY);
}

#ifndef InputComponent_H
#define InputComponent_H
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "BaseComponent.h"

class InputComponent : public BaseComponent
{
public:
	InputComponent();
	std::string getTypeName();
	void moveSprite(sf::Sprite *sprite, float moveSpeedX, float moveSpeedY, float deltaTime);

private:
	const std::string componentName = "InputComponent";
	sf::Keyboard::Key jump;
	sf::Keyboard::Key duck;
	sf::Keyboard::Key moveLeft;
	sf::Keyboard::Key moveRight;
	sf::Keyboard::Key spellSlots[5];
	sf::Keyboard::Key inventory;
	sf::Mouse::Button action;
};

#endif
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Window.h"
#include "RenderHandler.h"
#include "Component\InputComponent.h"
#include "Component\EnvironmentColliderComponent.h"

sf::RenderWindow* mainWindow;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Sprite tSprite;
	//test(2014-03-26)
	sf::Sprite tSprite2;
	//InpComp to be removed (2014-03-26)
	InputComponent InpComp;
	EnvironmentColliderComponent EnvColComp;
	float moveSpeedX = 1, moveSpeedY = 1;

	//test(2014-03-26)
	tSprite.setPosition(100, 50);
	tSprite2.setPosition(400, 300);

	SetGfx()->loadTexture("test.png");
	tSprite.setTexture(*SetGfx()->requestTexture("test.png"));
	//test (2014-03-26)
	tSprite2.setTexture(*SetGfx()->requestTexture("test.png"));

	//test (2014-03-27)
	sf::Vector2u size = tSprite.getTexture()->getSize();
	sf::Vector2u size2 = tSprite2.getTexture()->getSize();
	tSprite.setOrigin(size.x / 2, size.y / 2);
	tSprite2.setOrigin(size2.x / 2, size2.y / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Testing of function - to be removed (2014-03-26)
		InpComp.moveSprite(&tSprite, moveSpeedX, moveSpeedY, 1);


		//Testing collision detection (2014-03-27)
		sf::FloatRect boundingBoxPlayer = tSprite.getGlobalBounds();
		sf::FloatRect boundingBoxOther = tSprite2.getGlobalBounds();
		if (boundingBoxPlayer.intersects(boundingBoxOther))
			EnvColComp.environmentCollision(&tSprite, tSprite2);

		window.clear();
		window.draw(tSprite2);
		window.draw(tSprite);
		window.display();
	}

	return 0;

}
//Read Only
const sf::RenderWindow* GetWindow()
{
	return mainWindow;
}



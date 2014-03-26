#include <SFML/Graphics.hpp>
#include "Window.h"
#include "RenderHandler.h"
#include "Component\InputComponent.h"
#include "Vector.h"
sf::RenderWindow* mainWindow;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Sprite tSprite;
	//test(2014-03-26)
	sf::Sprite tSprite2;
	//InpComp to be removed (2014-03-26)
	InputComponent InpComp;
	float moveSpeedX = 1, moveSpeedY = 1;

	//test(2014-03-26)
	tSprite.setPosition(400, 300);

	SetGfx()->loadTexture("test.png");
	tSprite.setTexture(*SetGfx()->requestTexture("test.png"));
	//test (2014-03-26)
	tSprite2.setTexture(*SetGfx()->requestTexture("test.png"));

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

		//test (2014-03-26)
		sf::FloatRect boundingBoxPlayer = tSprite.getGlobalBounds();
		sf::FloatRect boundingBoxOther = tSprite2.getGlobalBounds();
		if (boundingBoxPlayer.intersects(boundingBoxOther)) {
			tSprite.setPosition(400, 300);
		}

		window.clear();
		window.draw(tSprite);
		//test (2014-03-26)
		window.draw(tSprite2);
		window.display();
	}

	return 0;

}
//Read Only
const sf::RenderWindow* GetWindow()
{
	return mainWindow;
}



#include <SFML/Graphics.hpp>
#include "Window.h"
#include "RenderHandler.h"
#include "Component\InputComponent.h"
sf::RenderWindow* mainWindow;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Sprite tSprite;
	//InpComp to be removed (2014-03-26)
	InputComponent InpComp;
	float moveSpeedX = 1, moveSpeedY = 1;

	SetGfx()->loadTexture("test.png");
	tSprite.setTexture(*SetGfx()->requestTexture("test.png"));
	//*/
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

		window.clear();
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



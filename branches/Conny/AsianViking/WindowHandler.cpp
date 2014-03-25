#include <SFML/Graphics.hpp>
#include "Window.h"
#include "RenderHandler.h"
sf::RenderWindow* mainWindow;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Sprite tSprite;

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

		shape.setFillColor(sf::Color::Green);
		shape.setRadius(100.f);
		window.clear();
		window.draw(shape);

		shape.setFillColor(sf::Color::Black);
		shape.setRadius(50.f);
		window.draw(shape);
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



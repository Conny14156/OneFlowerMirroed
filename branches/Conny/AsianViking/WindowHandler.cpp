#include <SFML/Graphics.hpp>
#include "Window.h"
#include "RenderHandler.h"
#include "GameObject.h"
#include "Component\RenderComponent.h"
#include "Game.h"

sf::RenderWindow* mainWindow;
sf::RenderWindow* editWindow;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::RenderWindow eWindow(sf::VideoMode(800, 600), "Editor!");
	GameObject tGameObject[5];
	mainWindow = &window;
	editWindow = &eWindow;

	SetGfx()->loadTexture("test.png");
	for (size_t i = 0; i < 5; i++)
	{
		tGameObject[i].AddComponent(new RenderComponent);
		tGameObject[i].GetComponent<RenderComponent>()->sprite.setTexture(*SetGfx()->requestTexture("test.png"));
		tGameObject[i].GetComponent<RenderComponent>()->sprite.setScale(0.1 + i * 0.1, 0.1 + i * 0.1);

		tGameObject[i].GetComponent<RenderComponent>()->sprite.setPosition(50, 50 * i);
		SetGame()->addGameObject(&tGameObject[i]);
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		eWindow.clear();

		SetGfx()->Draw();//Change this to const verseion aka Request

		
		eWindow.display();
		window.display();
	}

	return 0;

}
	


//Read Only
const sf::RenderWindow* RequestWindow()
{
	return mainWindow;
}

sf::RenderWindow* SetWindow()
{
	return mainWindow;
}
sf::RenderWindow* SetEditWindow()
{
	   return editWindow;
}	
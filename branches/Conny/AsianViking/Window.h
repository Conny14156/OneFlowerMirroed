#ifndef Window_H
#define Window_H
#include <SFML\Graphics.hpp>

//Read Only
const sf::RenderWindow* RequestWindow();

//Returns a modifiyable pointer towards the main window
sf::RenderWindow* SetWindow();
sf::RenderWindow* SetEditWindow();
#endif
#ifndef BackgroundSprite_HPP
#define BackgroundSprite_HPP
#include <Core/Vector.h>
#include <AssetManager/SpriteRef.hpp>
#include <AssetManager/Database/DBZone.hpp>
#include <Core/String.hpp>
class BackgroundSprite
{
public:
	//Tile();

	// name input for texture, and coordinates for the position
	BackgroundSprite(Core::String n = "test.png", Core::Vector2 pos = Core::Vector2(0, 0));
	// name input for texture, and x, y pos for position
	BackgroundSprite(Core::String n, float x = 0.f, float y = 0.f);
	BackgroundSprite(const DBBackgroundSprite& DbBackground);

	BackgroundSprite(const BackgroundSprite &background);

	//position of the tile
	Core::Vector2 position;
	//the sprite that the tile uses
	SpriteRef sprite;
	// the name of the texture
	Core::String name;
	// for repeated texture
	Core::Vector2i size;

	BackgroundSprite& operator=(const BackgroundSprite &background);
	void setRepeated(bool b);
	void setPosition(int x, int y);
	void setPosition(float x, float y);
private:

	void setSize(Core::Vector2i size);

public:

	// save function for the tile
	template<class Archive>
	void save(Archive &ar) const
	{
		ar(name);
		ar(position.x);
		ar(position.y);
		ar(size.x);
		ar(size.y);
	}
	// load function for the tile
	template<class Archive>
	void load(Archive &ar)
	{
		ar(name);
		sprite.setTexture(Engine::Textureloader.requestTexture(name),false);
		ar(position.x);
		ar(position.y);
		ar(size.x);
		ar(size.y);
		sprite.setTextureRect(sf::IntRect(0,0,size.x, size.y));
	}
};

#endif
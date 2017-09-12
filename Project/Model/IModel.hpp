#ifndef MODEL_HPP
#define MODEL_HPP

#include <SFML\Graphics\RenderTarget.hpp>

#include <Core\String.hpp>
#include <AssetManager\SpriteRef.hpp>

class IModel : sf::Drawable
{
protected:

	SpriteRef* m_render_sprite;
	bool updateRequired = true;
	
public:
	
	virtual void updateFrame() = 0;

	IModel();
	
	virtual ~IModel() = default;

	void setRenderSprite(SpriteRef& texture);

	virtual void setAnimation(Core::String _animation) = 0;

	virtual void setTextureMap(Core::String _modOrigin, Core::String _textureMapName) = 0;

	virtual void preRender();

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};

#endif
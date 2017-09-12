#ifndef TransformComponent_HPP
#define TransformComponent_HPP
#include "IBaseComponent.hpp"
#include "../Vector.h"
namespace Component
{
	class TransformComponent : public IBaseComponent < TransformComponent >
	{
	public:
		TransformComponent();

		TransformComponent(const TransformComponent &tc);
		//Relative to the Window
		Core::Vector2 position;

		//Multiply and not Pixelcount
		Core::Vector2 size;//Dont make this pixel count fuck up to much with rect size

		//Yet TBD
		Core::Vector2 rotation;

		//Get the angle towards target
		double angle(TransformComponent* target);

		//Get distance towards target in Pixels
		double distance(TransformComponent* target);

		Core::Vector2 DirectionTowards(TransformComponent* target);

		//TODO move move() to protect or remove entirly
		//Move relative
		//void move(Vector2 dir,double s);
		virtual TransformComponent* copy();
	
		template<class Archive>
		void serialize(Archive &ar)
		{
			//ar(tc.componentName);
			ar(position.x);
			ar(position.y);
			ar(rotation.x);
			ar(rotation.y);
			ar(size.x);
			ar(size.y);
		}
	protected:
		//Move towrads Absolute World coordinates with Pixel Per Seconds
		//void moveTo(Vector2 newPosition);

		void attachOn(GameObject* go);

	private:

		//template<class Archive>
		//friend void save(Archive &ar, const TransformComponent &tc);
		//template<class Archive>
		//friend void load(Archive &ar, TransformComponent &tc);
	};
}


#endif
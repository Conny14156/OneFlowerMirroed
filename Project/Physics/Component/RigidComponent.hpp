#ifndef RigidComponent_HPP
#define RigidComponent_HPP
#include <Core\Component\IBaseComponent.hpp>
//#include <vector>
//#include "../../Vector.h"
#include "../BoundingBox.hpp"
#include "../Movement.hpp"

enum Material
{
	Standard = 0 //<< 0
};
namespace Physics { class Collider; }

namespace Component
{
	class RigidComponent :public IBaseComponent < RigidComponent >
	{
	public:

		//LOW: Remove this if not needed
		//TODO Add other constructors
		RigidComponent();
		~RigidComponent();
		//bool inMotion();
		//void replaceForce(Vector2 dir,float power);
		//std::vector<std::pair<Vector2,double>> forceQueue;

		Physics::BoundingBox bounding;
		Physics::Movement movement;

		//Vector2 direction;
		//double force;

		//Apply Gravity
		bool gravity = true;

		//Mass in Kilogram
		int mass = 10;

		//Colliding
		//bool colliding = false;

		//Colliding Object. [0] up and than go Clock-Wise
		//GameObject* colisionDirection[4];

		//std::vector<GameObject*> entered;
		//void onCollision(Physics::Collider c);

		Material material = Material::Standard;

		virtual RigidComponent* copy();

		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(bounding.size.x);
			ar(bounding.size.y);
			//ar(gravity);
			ar(mass);
		}

	protected:
		void attachOn(GameObject* go);

	private:
		//template <class Archive>
		//friend void save(Archive& Ar, const RigidComponent& rig);
		//template <class Archive>
		//friend void load(Archive& Ar, RigidComponent& rig);
	};
}

#endif
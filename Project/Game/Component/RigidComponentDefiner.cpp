#include "RigidComponent.hpp"
std::string IBaseComponent<RigidComponent>::componentName = "RigidComponent";
const unsigned int IBaseComponent<RigidComponent>::typeID = 10905;
#include "../../Engine.hpp"

//LOW: Remove this if not needed
RigidComponent::RigidComponent():bounding(0,0,128,128)
{
}
RigidComponent::~RigidComponent()
{
	//Engine::Physics.removePhysics(this);
	Engine::game.removePhysics(this);
}
void RigidComponent::attachOn(GameObject* go)
{
	//Dont put this in constructors, Cause rigidcomponent will call this twice from constructor hierarchy calls

	BaseComponent::attachOn(go);
	Engine::game.addPhysics(this);
}
/*
bool RigidComponent::inMotion()
{
	if(force)
		return true;
	return false;
}
//*/
/*
void RigidComponent::replaceForce(Vector2 dir,float power)
{
	if(dir.normalize())
		direction = dir;
	force = power;
}
//*/
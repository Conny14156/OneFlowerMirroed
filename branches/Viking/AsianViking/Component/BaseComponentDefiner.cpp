#include "BaseComponent.h"

void BaseComponent::attachOn(GameObject* attachTo)
{
	this->attachedOn = attachTo;
}
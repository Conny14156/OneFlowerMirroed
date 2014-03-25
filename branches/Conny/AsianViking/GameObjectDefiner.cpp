#include "GameObject.h"

void GameObject::AddComponent(BaseComponent* componentToAttach)
{
	//use map inbuild function to check if there is a
	if (componentMap.count(componentToAttach->getTypeName()) > 0)
	{
		componentToAttach->attachOn(this);
		componentMap.insert	(	componentMap.end(),
								std::make_pair
									(
										componentToAttach->getTypeName(),
										componentToAttach
									)
							);	
	}
}
#ifndef GameObject_H
#define GameObject_H
#include <map>
#include <string>
#include "Component\BaseComponent.h"
class GameObject
{
public:
	GameObject();
	~GameObject();

	//Attach a derivied component 
	void AddComponent(BaseComponent* componentToAdd);

	template<class templateComponent>
	//Returns a component pointer from the componentMap
	templateComponent* GetComponent()
	{
		std::string componentTypeName = typeid(templateComponent).name;
		//Removes the char's "Class" and ' '
		for (int i = 0; i < 6; i++)
		{
			componentTypeName.erase(componentTypeName.begin());
		}
		std::map<std::string, BaseComponent*>::const_iterator it = componentMap.find(componentTypeName);

		if (it != componentTypeName.end())
		{
			templateComponent ptTComponent;
			ptTComponent = (templateComponent*)it->second;

			return ptTComponent;
		}
		else
			return NULL;

	}

protected:
	//List of all component that is currently attached to the GameObject
	std::map<std::string,BaseComponent*> componentMap;



};
#endif
#ifndef BaseComponent_H
#define BaseComponent_H
#include <string>
class GameObject;
class BaseComponent
{
		
public:

	virtual std::string getTypeName() = 0;
	//Attach the component onto a GameObject
	void attachOn(GameObject* attachTo);

protected:

	//Gameobject this component currently attached to;
	GameObject* attachedOn;

private:

	//Name of the component
	const std::string componentName = "BaseComponent";

};

#endif
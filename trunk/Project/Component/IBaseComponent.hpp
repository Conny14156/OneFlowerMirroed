#ifndef IBaseComponent_HPP
#define IBaseComponent_HPP
#include "BaseComponent.hpp"
#include <string>
#include "../EditorUI/EditorField.hpp"

template<typename>
class IBaseComponent :public BaseComponent
{
public:
	const unsigned int getType()
	{
		return typeID;
	}
	std::string getTypeName()
	{
		return componentName;
	}
	std::map<std::string,BaseField*> getFields()
	{
		return editorFields;
	}
	
	//Name of the component
	static std::string componentName;
	static const unsigned int typeID;
	std::map<std::string,BaseField*> editorFields;

};
#endif
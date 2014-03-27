#ifndef Game_H
#define Game_H
#include <map>
#include <string>

class GameObject;

class Game
{

public:
	//Get a pointer towards a GameObject from the first match via its name
	GameObject* RequestGameObject(std::string);

	//Get a pointer towards a GameObject via a its IdentityCode
	GameObject* RequestGameObject(unsigned int);
	
private:
	std::map<unsigned int, GameObject*> allGameObjectMap;





};


#endif
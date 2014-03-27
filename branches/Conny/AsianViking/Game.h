#ifndef Game_H
#define Game_H
#include <vector>
#include <string>

class GameObject;

class Game
{

public:
	//Get a pointer towards a GameObject from the first match via its name
	GameObject* requestGameObject(std::string);

	//Get a pointer towards a GameObject via a its IdentityCode
	GameObject* requestGameObject(unsigned int ID);
	GameObject* requestGameObject(GameObject* gameObjectPointer);
	
	const std::vector<GameObject*>* requestAllGameObjecVector() const;

private:
	std::vector<GameObject*> allGameObjectList;





};
//ReadOnly, Returns a const pointer towards game
const Game* RequestGame();

//Returns a pointer value towards game
Game* SetGame();

#endif
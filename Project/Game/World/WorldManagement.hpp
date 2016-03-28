#ifndef WorldManagement_HPP
#define WorldManagement_HPP
#include <map>
#include "ModLoader.hpp"
#include "../LoadAndSave/PrefabContainer.hpp"
#include "../LoadAndSave/DatabaseIndex.hpp"
#include "../GUI/Window/Addon/ProgressBar.hpp"
#include "../LoadAndSave/ModHeader.hpp"
#include "DBZone.hpp"
#include "../LoadAndSave/EditorObjectSaveMode.hpp"
#include "../Quest/Quest.hpp"
#include "../Item/Item.hpp"
class Zone;
class GameObject;
class WorldManagement
{
	enum loadstate {
		STATE_NOT_SET,
		STATE_PREPARE_LOAD,
		STATE_UNLOAD_OBJECTS,
		STATE_RELOAD_OBJECTS,
		STATE_DONE,
	};
public:

#ifdef _DEBUG
	//Probably move this to editor
	PrefabContainer editorPrefabContainer;
	std::map<std::pair<std::string,unsigned int>, DBZone> EditorAllZones;
	std::map<std::pair<std::string, size_t>, Items::Item*> EditorAllItems;
	std::map<std::pair<std::string, unsigned int>, Quests::Quest> EditorAllQuests;
#endif
	//to be able to remove gameobjects when unloading;
	std::map<std::pair<std::string,size_t>,GameObject*> listOfZoneObjects;
	ModLoader modLoadOrder;

	std::pair<std::string,unsigned int> lastLoadedZone;

	
	std::map <std::pair<std::string,unsigned int>,Zone*> worldmap;
	Zone* getCurrentZone();
	GUI::Window::Addon::ProgressBar& getLoadingScreenProgressBar();


	WorldManagement();
	~WorldManagement();

	void loadZone(std::string addedFromMod,unsigned int zoneID);
	bool getIsLoading();

	loadstate getCurrentLoadingState();

#ifdef _DEBUG

	std::string openedMod = "<Not Set>";
	ModHeader myModHeader;

	std::string getLoadedMod();

	std::vector<std::string> getModDependencies(std::string mod);
	void newMod(std::string modName, std::vector<std::string> dependencies);
	std::vector<std::string> loadMod(std::string modName);
	std::string loadMods(std::string modName);
	void EditorAddNewZone(std::string zoneName, std::string background, std::string loadingScreen, std::string loadingScreenMessage, size_t ID, double x, double y);
	void EditorEditZone(std::string zoneName, std::string background, std::string loadingScreen, std::string loadingScreenMessage, size_t ID, double x, double y);
	void EditorLoadZone(std::string zoneName,unsigned int ID);
	void EditorRemoveZone();
	std::string EditorSave();
	void EditorSetBackground(std::string textureName);
	void EditorSetBackgroundSize(int x,int y);
	std::pair<std::pair<std::string,size_t>,DBZonePrefabStruct> EditorAddGameObjectToZone(Prefab& prefab,GameObject* go);
	void RemoveGameObjectFromZone(GameObject* go);

	void EditorFlagGameObjectForEdit(GameObject* go);

	void AddQuest(Quests::Quest quest);

	friend void LoadAllZones(std::map<std::pair<std::string,unsigned int>, DBZone>& nameOfAllZones);
	friend void LoadAllPrefabs(PrefabContainer& editorPrefabContainer);
	friend void LoadAllItems(std::map<std::pair<std::string, size_t>, Items::Item*>& editorAllItems);
	friend void LoadAllQuests(std::map<std::pair<std::string, unsigned int>, Quests::Quest> editorAllQuests);
	size_t EditorGetValidID();
	size_t ID = 1;
#endif

	void drawLoadingScreen();
	void loadSome();
private:

	GUI::Window::Addon::ProgressBar loadingScreenProgress;

	void startLoad();

	loadstate loadState = STATE_NOT_SET;
	bool isLoading = false;
	std::map<std::pair<std::string,size_t>, DBZonePrefabStruct>::iterator currentObjIterator;
	std::map<std::pair<std::string, size_t>, GameObject*>::iterator currentObjIteratorUnload;

	size_t currentObj = 0;
	size_t totalLoaded = 0;
	size_t totalToLoad = 0;
	std::pair<std::string, size_t> zoneToLoadID;

	friend bool loadZoneFromSaveFile(std::string saveFile, Zone& zoneToLoad, size_t zoneID);
	friend void loadZoneFromDB(DBZone& zoneToLoad, size_t zoneID);
	Zone* currentZone;
	DBZone zoneToLoad;
	// loads a zone from a specified file
	friend bool loadModOrderFile(ModLoader &mod);
	friend void loadZoneFile(std::string fileName, const DatabaseIndex& index,DBZone &z);
	friend bool loadPrefab(std::string fromMod,unsigned int index, Prefab& prefab);
	friend void loadPrefab(std::string modName, Prefab& prefab, const DatabaseIndex &index);
	friend DatabaseIndex loadIndex(std::string modname, size_t objectID, std::string loadType);
};
#endif
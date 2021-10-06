#pragma once
#include <iostream>
#include "DialogueSys.h"

class MapSys
{
public:
	MapSys();
	~MapSys();
	enum class Map
	{
		GameStart,
		Beginning,
		Forest,
		DeepForest, //Secret Boss?
		Port,
		Shore, //Secret item?
		Town, //SafeArea
		DarkPortal,
		CastleOfFire, //BOSS
		DarkShore,	//Bad ending
		Beach //Good ending
	};
	MapSys::Map GetMapLoc();
	MapSys::Map SetMapLoc(Map NewLoc);
	void LocController();
private:
	int m_setLocation;
	int m_getLocation;
	bool m_roomDone;
	Map m_locations;
};


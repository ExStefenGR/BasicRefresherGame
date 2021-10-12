#pragma once
#include <iostream>
//Programmed by Stefanos

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
	void DialogueSys(Map m_locations);
	Map m_locations;
	void LocController();
private:
	int m_setLocation;
	int m_getLocation;
	bool m_roomDone;
	
	void SpeechPause();
};


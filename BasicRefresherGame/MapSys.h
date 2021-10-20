#pragma once

#include "iostream"
#include "string"
#include "CombatSys.h"
#include "CharacterSys.h"

class MapSys
{
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
	enum class Job
	{
		Sword = 1,
		Staff,
		Bow
	};
public:
	MapSys();
	~MapSys();
	void GetMapLoc();
	MapSys::Map SetMapLoc(Map NewLoc);
	void LocController();
	void SpeechText();

private:
	int m_setLocation;
	int m_getLocation;
	bool m_roomDone;
	Map m_locations;
	CharacterSys m_player;
	CombatSys m_combat;
};


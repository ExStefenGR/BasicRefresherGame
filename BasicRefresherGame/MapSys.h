#pragma once

#include "iostream"
#include "string"

#include "CharacterSys.h"

class MapSys
{
	enum MAP
	{
		GAMESTART, 
		BEGINNING,
		FOREST,
		DEEPFOREST=3, //Secret Boss?
		PORT,
		SHORE, //Secret item?
		TOWN, //SafeArea
		DARKPORTAL,
		CASTLEOFFIRE, //BOSS
		CASTLEOFICE,  //BOSS
		DARKSHORE,	//Bad ending
		BEACH //Good ending
	};
public:
	MapSys();
	~MapSys();
	void GetMapLoc();
	int SetMapLoc(int location);
	void LocController();
	void SpeechText();
private:
	int m_setLocation;
	int m_getLocation;
	MAP m_locations;
	CharacterSys m_player;
};


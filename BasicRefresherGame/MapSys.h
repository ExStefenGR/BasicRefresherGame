#pragma once

#include "iostream"
#include "string"

class MapSys
{
	enum MAP
	{
		GAMESTART, //Gamestart Should redirect to CharacterCreation
		BEGINNING,
		FOREST,
		DEEPFOREST=3, //Secret Boss?
		NEARSEA,
		SHORE, //Secret item?
		TOWN, //SafeArea
		DARKPORTAL,
		CASTLEOFFIRE, //BOSS
		CASTLEOFICE,  //BOSS
		DARKSHORE,	//Bad ending
		BEACH //Good ending
	};
public:
	void GetMapLoc();
	void SetMapLoc();
	void LocController();
private:
	int setLocation_m;
	int getLocation_m;
	MAP playerPos_m;
};


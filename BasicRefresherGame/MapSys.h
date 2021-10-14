#pragma once
#include <iostream>
#include "CharacterSys.h"

//Programmed by Stefanos
//Last edited 12/10/21

class MapSys
{
public:
	enum class Map
	{
		GameStart,
		Beginning,
		Forest,
		Woods, //Bad choice but rewarding fight if won?
		Port,
		Shore, //Secret item?
		Town,	//SafeArea
		Colosseum, //Training Area for XP
		DarkPortal,
		CastleOfFire, //BOSS
		DarkShore,	//Bad ending
		Beach //Good ending
	};
	Map m_locations;
	MapSys();
	~MapSys();
	MapSys::Map GetMapLoc();
	MapSys::Map SetMapLoc(Map NewLoc);
	void DialogueSys(Map& m_locations);
	void ChoiceSys(Map& m_locations);
	void LocController();

private:

	int m_getLocation;
	int m_setLocation;
	bool m_choiceMade;
	bool m_roomDone;
	int m_choice;
	void SpeechPause();
	CharacterSys* m_player;
};
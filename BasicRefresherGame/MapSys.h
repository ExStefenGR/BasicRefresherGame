#pragma once
#include <iostream>
#include <map>
#include <string>
#include "CharacterSys.h"

//Programmed by Stefanos
//Last edited 20/10/21

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
	MapSys::Map GetMapLoc() const;
	MapSys::Map SetMapLoc(Map NewLoc);
	void DialogueSys(Map& m_locations);
	void ChoiceSys(Map& m_locations);
	void LocController();

private:

	struct Area
	{
		std::string dialogue1;
		std::string dialogue2;
		std::string dialogue3;
		std::string dialogue4;
		std::string dialogue5;
	};

	std::map<std::string, Area> dialogue;
	bool m_choiceMade;
	bool m_roomDone;
	int m_getLocation;
	int m_setLocation;
	int m_choice;
	CharacterSys* m_player;
	void SpeechPause() const;
};
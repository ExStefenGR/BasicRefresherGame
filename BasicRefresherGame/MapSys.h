#pragma once
#include <iostream>
#include <map>
#include <string>
#include "CharacterSys.h"
#include "MonsterSys.h"

//Programmed by Stefanos
//Last edited 16/12/21
//MonsterFight() by David 
//CharacterSys() by Isaac

class MapSys
{
public:
	enum class Map
	{
		GameStart,
		Beginning,
		Forest,
		Woods,
		Port,
		Town,
		Colosseum,
		DarkPortal,
		CastleOfFire,
		DarkShore,
		Beach,
		Win
	};
	MapSys();
	~MapSys();
	MapSys::Map GetMapLoc() const;
	void ChoiceSys(const Map& locations);
	void CreateDialog(); 
	void DialogueSys(const Map& locations);
	void LocController();
	void MonsterFight();
	void SetMapLoc(const Map& NewLoc);
	void SpeechPause() const;
private:
	struct Area
	{
		std::string dialogue1;
		std::string dialogue2;
		std::string dialogue3;
		std::string dialogue4;
		std::string dialogue5;
		std::string dialogue6;
		std::string dialogue7;
	};

	bool m_choiceMade;
	bool m_roomDone;
	bool m_optionPicked;
	int m_getLocation;
	int m_setLocation;
	int m_choice;
	int m_option;

	std::map<std::string, Area> dialogue;

	CharacterSys* m_player;
	Map m_lastLocation;
	Map m_locations;
	MonsterSys* m_monster;
};
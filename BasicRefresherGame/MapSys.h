#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "CharacterSys.h"
#include "MonsterSys.h"

//Programmed by Stefanos
//Last edited 06/02/22
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
	int ValidateInput(int playerInput)const;
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

	bool m_choiceMade{ false };
	bool m_roomDone{ false };
	bool m_optionPicked{ false };
	bool m_runAway{ false };
	int m_getLocation{ 0 };
	int m_setLocation{ 0 };
	int m_choice{ 0 };
	int m_option{ 0 };

	std::map<std::string, const Area> dialogue;

	Map m_lastLocation;
	Map m_locations;
	std::unique_ptr<MonsterSys> m_monster = std::make_unique<MonsterSys>();
	std::unique_ptr<CharacterSys> m_player = std::make_unique<CharacterSys>();
};
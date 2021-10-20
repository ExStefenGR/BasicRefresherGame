#pragma once
//TODO: Each class needs their own Skillset
//Sword is for attacks and consumes mana for skills
//Staff is the second class, they deal damage with spells, it costs more mana than sword but deals heavier damage in bursts
//The third class which is shield is used for tank, HP is expotentially increased for the cost of not being able to do spells or skills
//Combat System by David, with help from Isaac
//Last Changed: 19/10/21

#include <iostream>
#include <string>
#include <map>
#include "CharacterSys.h"
#include "MonsterSys.h"
#include "MapSys.h"

typedef std::map<std::string, MonsterSys*> MonsterObjectMap;

class CombatSys
{
	enum class Combat
	{
		Attack,
		Spells,
		Run
	};


public:
	CombatSys();
	~CombatSys();

	void Fight();
	Combat GetCombatOptions(int playerOption);

	CharacterSys* m_player;
	MapSys* m_map;
	MonsterObjectMap monsterObjectMap;
};
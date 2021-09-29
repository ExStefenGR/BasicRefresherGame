#pragma once
//TODO: Each class needs their own Skillset
//Sword is for attacks and consumes mana for skills
//Staff is the second class, they deal damage with spells, it costs more mana than sword but deals heavier damage in bursts
//The third class which is shield is used for tank, HP is expotentially increased for the cost of not being able to do spells or skills


#include <iostream>
#include <string>

#include "CharacterSys.h"
#include "MonsterSys.h"

class CombatSys
{
	enum OPTIONS
	{
		ATTACK,
		DEFEND,
		SPELL,
		ITEM,
		RUN
	};


public:
	CombatSys();
	~CombatSys();

	class getEquipment;
	bool isityourturn;
	bool isittheirturn;
	void CombatOptions;

private:

	int m_setHealth;

};
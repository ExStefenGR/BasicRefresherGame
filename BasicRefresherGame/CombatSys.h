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
	enum Combat
	{
		Attack,
		Block,
		Spells,
		Items,
		Run
	};


public:
	CombatSys();
	~CombatSys();

	class getEquipment;
	bool isityourturn();
	bool isittheirturn();
	void CombatOptions();
	void setSwordSkills();//Hey, you think all this should be in the code for the character?
	int getSwordSkills();
	void setStaffSkills();
	int getStaffSkills();
	void setShieldSkills();
	int getSheildSkills();
	void setSpells(int manaCost);
	int getSpells();

	int m_manaCost;
	int m_healthPoints;



};
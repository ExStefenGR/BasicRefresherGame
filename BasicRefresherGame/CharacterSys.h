#pragma once
#include <string>
#include <iostream>

class CharacterSys
{
	enum JOB
	{
		SWORD = 1,
		STAFF,
		SHIELD
	};
public:
	CharacterSys();
	~CharacterSys();

	std::string GetName();
	void SetName();
	void SetDamage(int damagePoints);
	int GetDamage();
	void SetHealthPoints(int healthPoints);
	int GetHealthPoints();
	void SetManaPoints(int manaPoints);
	int GetManaPoints();
	void SetCharacterClass();
	int GetCharacterClass();
	void PlayerInfo();

	std::string m_name;
	int m_damagePoints;
	int m_healthPoints;
	int m_manaPoints;
	int m_class;
	JOB m_job;
};


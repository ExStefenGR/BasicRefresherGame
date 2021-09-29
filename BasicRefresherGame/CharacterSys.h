#pragma once
#include <string>
#include <iostream>

class CharacterSys
{
	enum class Job
	{
		Sword = 1,
		Staff,
		Shield
	}; //maybe move this in mapsys as well for easier navigation?
public:
	CharacterSys();
	~CharacterSys();

	std::string GetName();
	void SetName();
	void SetDamage(int damagePoints);
	int GetDamage();
	void SetHealthPoints(int healthPoints);
	int GetHP();
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
	Job m_job;
};


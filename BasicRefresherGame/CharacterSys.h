#pragma once
#include <string>
#include <iostream>

class CharacterSys
{
public:
	CharacterSys();
	~CharacterSys();

	enum class Job
	{
		Sword = 1,
		Staff,
		Bow
	};
	enum class Skills
	{
		Berserker = 1,
		Fireball,
		ArrowShower
	};

	void CreateCharacter();
	std::string GetName();
	void SetName();
	void SetDamage(int damagePoints);
	int GetDamage();
	void SetHealthPoints(int healthPoints);
	int GetHealthPoints();
	Skills GetSkills();
	void SetManaPoints(int manaPoints);
	int GetManaPoints();
	void SetCharacterClass();
	int GetCharacterClass();
	void PlayerInfo();

private:
	std::string m_name;
	int m_damagePoints;
	int m_healthPoints;
	int m_manaPoints;
	int m_class;
	Job m_job;
	Skills m_skill;
};


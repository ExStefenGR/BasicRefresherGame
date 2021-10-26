#pragma once
#include <string>
#include <iostream>

class CharacterSys
{

public:

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

	CharacterSys();
	~CharacterSys();

	int GetCharacterClass() const;
	int GetDamage() const; // return the damage points of a character
	int GetHealthPoints() const; // return the actual health of the character
	int GetManaPoints() const;

	std::string GetName(); // return the name of a character

	Skills GetSkills();

	void CreateCharacter(); // creates a character
	void ReceiveDamage(int monsterDamage);
	void SetCharacterClass();
	void SetDamage(int damagePoints); // increase damage points of a the character
	void SetHealthPoints(int healthPoints); // increase maxHealth of the character
	void SetManaPoints(int manaPoints);
	void SetName(); // set a character name
	void PlayerInfo();



private:

	bool m_isAlive;

	int m_class;
	int m_damagePoints;
	int m_healthPoints;
	int m_manaPoints;
	int m_maxHealthPoints;

	Job m_job;

	Skills m_skill;

	std::string m_name;
};
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

	bool IsAlive(); // make it const
	int GetCharacterClass() const;
	int GetDamage() const; // return the damage points of a character
	int GetHealthPoints() const; // return the actual health of the character
	int GetManaPoints() const;
	std::string GetName() const; // make it const
	Skills GetSkills() const; // make it const
	void CreateCharacter(); 
	void SetCharacterClass();
	void SetDamage(int damagePoints);
	void SetHealthPoints(int healthPoints);
	void SetManaPoints(int manaPoints);
	void SetName();
	void PlayerInfo() const; // make it const
	void PlayerReceiveDamage(int monsterDamage, bool runAway);

private:
	bool m_isAlive;
	int m_class;
	int m_damagePoints;
	int m_healthPoints;
	int m_manaPoints;
	int m_maxHealthPoints;
	int m_maxManaPoints;
	Job m_job;
	Skills m_skill;
	std::string m_name;
};
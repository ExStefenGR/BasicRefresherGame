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

	CharacterSys();
	~CharacterSys();

	bool IsAlive() const;
	int GetCharacterClass() const;
	int GetDamage() const;
	int GetHealthPoints() const;
	int GetManaPoints() const;
	std::string GetName() const;
	void CreateCharacter();
	void SetCharacterClass();
	void SetDamage(int damagePoints);
	void SetHealthPoints(int healthPoints);
	void SetManaPoints(int manaPoints);
	void SetName();
	void PlayerInfo() const;
	void PlayerReceiveDamage(const int monsterDamage, const bool runAway);

private:
	bool m_isAlive;
	int m_class;
	int m_damagePoints;
	int m_healthPoints;
	int m_manaPoints;
	int m_maxHealthPoints;
	int m_maxManaPoints;
	Job m_job;
	std::string m_name;
};
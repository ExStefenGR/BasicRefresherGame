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
	void PlayerReceiveDamage(const int monsterDamage);

private:
	bool m_isAlive{ true };
	int m_class{ 0 };
	int m_maxHealthPoints{ 150 };
	int m_maxManaPoints{ 50 };
	int m_healthPoints{ m_maxHealthPoints };
	int m_manaPoints{ m_maxManaPoints };
	int m_damagePoints{ 10 };
	Job m_job{};
	std::string m_name{ 0 };
};
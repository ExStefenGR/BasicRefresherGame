//Character System by Isaac

#include "CharacterSys.h"
#include <string>
#include <iostream>

CharacterSys::CharacterSys()
{
	CharacterSys::m_job = {};
	CharacterSys::m_class = {};
	CharacterSys::m_skill = {};
	m_isAlive = true;
	m_maxHealthPoints = 150;
	m_maxManaPoints = 50;
	m_healthPoints = m_maxHealthPoints;
	m_manaPoints = m_maxManaPoints;
	m_damagePoints = 10;
}
CharacterSys::~CharacterSys() 
{
}
bool CharacterSys::IsAlive() const
{
	return m_isAlive;
}
int CharacterSys::GetCharacterClass() const
{
	return m_class;
}
int CharacterSys::GetDamage() const
{
	return m_damagePoints;
}
int CharacterSys::GetHealthPoints() const
{
	return m_healthPoints;
}
int CharacterSys::GetManaPoints() const
{
	return m_manaPoints;
}
std::string CharacterSys::GetName() const
{
	return m_name;
}
CharacterSys::Skills CharacterSys::GetSkills() const
{
	if (GetCharacterClass() == static_cast<int>(Job::Sword))
	{
		return Skills(Skills::Berserker);
	}
	else if (GetCharacterClass() == static_cast<int>(Job::Staff)) {
		return Skills(Skills::Fireball);
	}
	else if (GetCharacterClass() == static_cast<int>(Job::Bow)) {
		return Skills(Skills::ArrowShower);
	}
}
void CharacterSys::CreateCharacter()
{
	std::cout << "Player name? " << std::endl;
	SetName();
	SetCharacterClass();

	switch (m_class)
	{
	case 1:
		std::cout << "You have unlocked the sword, you're a Knight!" << std::endl;
		SetDamage(+8);
		SetManaPoints(+5);
		SetHealthPoints(+15);
		std::cout << "Damage, Health and Mana Increased" << std::endl;
		std::cout << "Mana can now be used for skills\n" << std::endl;
		break;
	case 2:
		std::cout << "You have unlocked the staff, you're a Mage!" << std::endl;
		SetDamage(+4);
		SetManaPoints(+15);
		SetHealthPoints(+5);
		std::cout << "Damage, Health and Mana Increased" << std::endl;
		std::cout << "Mana can now be used for skills\n" << std::endl;
		break;
	case 3:
		std::cout << "You have unlocked the bow, you're a Archer" << std::endl;
		SetDamage(+6);
		SetManaPoints(+10);
		SetHealthPoints(+10);
		std::cout << "Damage, Health and Mana Increased" << std::endl;
		std::cout << "Mana can now be used for skills\n" << std::endl;
		break;
	default:
		break;
	}
}
void CharacterSys::SetCharacterClass()
{
	while (m_class < 1 || m_class > 3)
	{
		std::cout << "You come accross three different weapons, which will you choose?" << std::endl;
		std::cout << "1. Sword" << std::endl;
		std::cout << "2. Staff" << std::endl;
		std::cout << "3. Bow" << std::endl;

		if (!(std::cin >> m_class))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Invalid Input!" << std::endl << std::endl;
			continue;
			std::cin >> m_class;
		}
	}
}
void CharacterSys::SetDamage(int damagePoints)
{
	m_damagePoints += damagePoints;
}
void CharacterSys::SetHealthPoints(int healthPoints)
{
	m_maxHealthPoints += healthPoints;
	m_healthPoints += healthPoints;
}
void CharacterSys::SetManaPoints(int manaPoints)
{
	m_maxManaPoints += manaPoints;
	m_manaPoints += manaPoints;
}
void CharacterSys::SetName()
{
	std::string name;
	std::cin >> name;
	m_name = name;
}
void CharacterSys::PlayerInfo() const
{
	std::cout << "#========================PLAYER STATS========================#" << std::endl;
	std::cout << "# Name   # " << GetName() << std::endl;
	std::cout << "# Attack # " << GetDamage() << std::endl;
	std::cout << "# Health # " << GetHealthPoints() << "/" << m_maxHealthPoints << std::endl;
	std::cout << "# Mana   # " << GetManaPoints() << "/" << m_maxManaPoints  << std::endl;
	
	switch (GetSkills())
	{
	case Skills::Berserker:
		std::cout << "# Skill  # Berserker" << std::endl;
		break;
	case Skills::Fireball:
		std::cout << "# Skill  # Fireball" << std::endl;
		break;
	case Skills::ArrowShower:
		std::cout << "# Skill  # ArrowShower" << std::endl;
		break;
	default:
		break;
	}
	std::cout << "#============================================================#\n" << std::endl;
}
void CharacterSys::PlayerReceiveDamage(const int monsterDamage, const bool runAway)
{
	if (runAway)
	{
		std::cout << "You tried to run but took " << monsterDamage << " damage." << std::endl;
	}
	else
	{
		std::cout << "Monster deal " << monsterDamage << " damage." << std::endl;
		m_healthPoints -= monsterDamage;
		if (m_healthPoints <= 0)
		{
			m_healthPoints = 0;
			m_isAlive = false;
			
			std::cout << "YOU ARE DEAD.\n" << std::endl;
		}
		
		
		system("pause");
		system("cls");
	}
}

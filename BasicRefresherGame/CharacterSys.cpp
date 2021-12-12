//Character System by Isaac

#include "CharacterSys.h"

#include <string>
#include <iostream>

CharacterSys::CharacterSys()
{
	CharacterSys::m_job = {};
	CharacterSys::m_class = {};
	CharacterSys::m_skill = {};
	m_healthPoints = 150;
	m_manaPoints = 50;
	m_damagePoints = 10;
}

CharacterSys::~CharacterSys() {}

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
		std::cout << "Mana can now be used for skills" << std::endl;
		//m_playerLocation.LocController();
		break;
	case 2:
		std::cout << "You have unlocked the staff, you're a Mage!" << std::endl;
		SetDamage(+4);
		SetManaPoints(+15);
		SetHealthPoints(+5);
		std::cout << "Damage, Health and Mana Increased" << std::endl;
		std::cout << "Mana can now be used for skills" << std::endl;
		//m_playerLocation.LocController();
		break;
	case 3:
		std::cout << "You have unlocked the bow, you're a Archer" << std::endl;
		SetDamage(+6);
		SetManaPoints(+10);
		SetHealthPoints(+10);
		std::cout << "Damage, Health and Mana Increased" << std::endl;
		std::cout << "Mana can now be used for skills" << std::endl;
		//m_playerLocation.LocController();
		break;
	default:
		break;
	}
}

std::string CharacterSys::GetName()
{
	return m_name;
}

void CharacterSys::SetName()
{
	std::string name;
	std::cin >> name;
	m_name = name;
}

void CharacterSys::SetDamage(int damagePoints)
{
	m_damagePoints += damagePoints;
}

int CharacterSys::GetDamage()
{
	return m_damagePoints;
}

void CharacterSys::SetHealthPoints(int healthPoints)
{
	m_healthPoints += healthPoints;
}

int CharacterSys::GetHealthPoints()
{
	return m_healthPoints;
}

CharacterSys::Skills CharacterSys::GetSkills()
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

void CharacterSys::SetManaPoints(int manaPoints)
{
	m_manaPoints += manaPoints;
}

int CharacterSys::GetManaPoints()
{
	return m_manaPoints;
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

int CharacterSys::GetCharacterClass()
{
	return m_class;
}

void CharacterSys::PlayerInfo()
{
	std::cout << "Player Name: " << GetName() << std::endl;
	std::cout << "Player Attack: " << GetDamage() << std::endl;
	std::cout << "Player Health points: " << GetHealthPoints() << std::endl;
	std::cout << "Player Mana points: " << GetManaPoints() << std::endl;

	switch (GetSkills())
	{
	case Skills::Berserker:
		std::cout << "Player Skill: Berserker\n" << std::endl;
		break;
	case Skills::Fireball:
		std::cout << "Player Skill: Fireball\n" << std::endl;
		break;
	case Skills::ArrowShower:
		std::cout << "Player Skill: ArrowShower\n" << std::endl;
		break;
	default:
		break;
	}
}
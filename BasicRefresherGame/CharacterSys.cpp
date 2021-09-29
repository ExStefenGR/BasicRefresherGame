#include "CharacterSys.h"

#include <string>
#include <iostream>

CharacterSys::CharacterSys()
{
	CharacterSys::m_job = {};
	CharacterSys::m_class = {};
	m_healthPoints = 150;
	m_manaPoints = 50;
	m_damagePoints = 10;
}

CharacterSys::~CharacterSys(){}

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

int CharacterSys::GetHP()
{
	return m_healthPoints;
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
	std::cout << "You come accross three different weapons, which will you choose?" << std::endl;
	std::cout << "1. Sword" << std::endl;
	std::cout << "2. Staff" << std::endl;
	std::cout << "3. Door" << std::endl;

	std::cin >> m_class;
}

int CharacterSys::GetCharacterClass()
{
	return m_class;
}

void CharacterSys::PlayerInfo()
{
	std::cout << "Mana can now be used for skills" << std::endl;
	std::cout << "Player Name: " << GetName() << std::endl;
	std::cout << "Player Attack: " << GetDamage() << std::endl;
	std::cout << "Player Health points: " << GetHP() << std::endl;
	std::cout << "Player Mana points: " << GetManaPoints() << std::endl;
}

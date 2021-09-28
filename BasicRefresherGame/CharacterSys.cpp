#include "CharacterSys.h"

#include <string>
#include <iostream>

CharacterSys::CharacterSys()
{
	std::cout << "Type player name" << std::endl;
	std::cin >> m_name;

	m_healthPoints = 150;
	m_manaPoints = 50;
	m_damagePoints = 10;
}

CharacterSys::~CharacterSys()
{
}

std::string CharacterSys::getName()
{
	return m_name;
}

void CharacterSys::setDamage(int damagePoints)
{
	m_damagePoints += damagePoints;
}

int CharacterSys::getDamage()
{
	return m_damagePoints;
}

void CharacterSys::setHealthPoints(int healthPoints)
{
	m_healthPoints += healthPoints;
}

int CharacterSys::getHealthPoints()
{
	return m_healthPoints;
}

void CharacterSys::setManaPoints(int manaPoints)
{
	m_manaPoints += manaPoints;
}

int CharacterSys::getManaPoints()
{
	return m_manaPoints;
}

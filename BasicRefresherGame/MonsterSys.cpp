#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys(Name nameMonster,int Health, int Damage)
{
	m_name = nameMonster;
	m_healthPoints = static_cast<int>(nameMonster) * 10;
	m_damagePoints = static_cast<int>(nameMonster) * 5;
}

MonsterSys::~MonsterSys()
{
}

int MonsterSys::GetDamage()
{
	return m_damagePoints;
}

int MonsterSys::GetHealthPoints()
{
	return m_healthPoints;
}

void MonsterSys::MonsterInfo(Name m_name)
{
	
	std::cout << "Monster Name: " << static_cast<int>(m_name) << std::endl;
	std::cout << "Player Attack: " << GetDamage() << std::endl;
	std::cout << "Player Health points: " << GetHealthPoints() << std::endl;
}
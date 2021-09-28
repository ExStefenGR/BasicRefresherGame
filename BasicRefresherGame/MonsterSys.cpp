#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys(Name nameMonster)
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

void MonsterSys::MonsterInfo(Name nameMonster)
{
	std::cout << "Monster Name: " << nameMonster << std::endl;
	std::cout << "Player Attack: " << GetDamage() << std::endl;
	std::cout << "Player Health points: " << GetHealthPoints() << std::endl;
}
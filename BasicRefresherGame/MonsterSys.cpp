#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys(Name nameMonster)
{
	m_name = nameMonster;
	m_monsterDamage = static_cast<int>(nameMonster) * 5;
	m_monsterHP = static_cast<int>(nameMonster) * 5;
	m_monsterDefence = static_cast<int>(nameMonster) * 5;
	//TODO: Maybe have attributes for each monster So we only call the monster itself without adding HP Def or Damage
}

MonsterSys::~MonsterSys()
{
}

int MonsterSys::GetDamage()
{
	return m_monsterDamage;
}

int MonsterSys::GetHP()
{
	return m_monsterHP;
}

void MonsterSys::SetDamageToMonster(int Damage)
{
	m_monsterHP = Damage;
}

void MonsterSys::MonsterInfo(Name m_name)
{
	
	std::cout << "Monster Name: " << static_cast<int>(m_name) << std::endl;
	std::cout << "Monster attack points: " << GetDamage() << std::endl;
	std::cout << "Monster health points: " << GetHP() << std::endl;
}
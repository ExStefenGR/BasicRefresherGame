#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys(std::string monsterName, MonsterStats monsterStats)
{
	m_monsterName = monsterName;
	m_stats = monsterStats;
	m_monsterDamage = static_cast<int>(monsterStats) * 5;
	m_maxMonsterHP = static_cast<int>(monsterStats) * 5;
	m_monsterDefence = static_cast<int>(monsterStats) * 5;
}

MonsterSys::~MonsterSys()
{
}

int MonsterSys::GetDamage() const
{
	return m_monsterDamage;
}

int MonsterSys::GetHealthPoints() const
{
	return m_monsterHP;
}

void MonsterSys::SetDamageToMonster(int Damage)
{
	m_monsterHP = Damage;
}

void MonsterSys::MonsterInfo(MonsterStats m_name)
{
	std::cout << "Monster Name: " << static_cast<int>(m_name) << std::endl;
	std::cout << "Monster attack points: " << GetDamage() << std::endl;
	std::cout << "Monster health points: " << GetHealthPoints() << std::endl;
}
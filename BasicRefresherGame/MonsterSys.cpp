#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys()
{
	m_monsterHP = 5;
	m_monsterDamage = 5;
	m_maxMonsterHP = 5;
	m_monsterDefence = 5;
	m_isAlive = true;
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
	m_monsterHP = m_monsterHP - Damage;
	if (m_monsterHP < 0)
	{
		m_isAlive = false;
	}
}
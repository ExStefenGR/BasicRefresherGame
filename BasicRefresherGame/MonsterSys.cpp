#include "MonsterSys.h"
#include <iostream>

MonsterSys::MonsterSys()
{
	m_isAlive = true;

	m_maxMonsterHP = 10;
	m_monsterDamage = 2;
	m_monsterDefence = 1;
	m_monsterHP = 10;
}

MonsterSys::~MonsterSys()
{
	m_isAlive = true;

	m_maxMonsterHP = 10;
	m_monsterDamage = 2;
	m_monsterDefence = 1;
	m_monsterHP = 10;
}

std::string MonsterSys::GetMonsterName()
{
	return m_monsterName;
}

bool MonsterSys::MonsterIsAlive() const
{
	return m_isAlive;
}

int MonsterSys::GetMonsterDamage() const
{
	return m_monsterDamage;
}

int MonsterSys::GetMonsterHealthPoints() const
{
	return m_monsterHP;
}

void MonsterSys::CreateMonster(int monsterStats, std::string monsterName)
{
	m_monsterName = monsterName;

	m_maxMonsterHP = m_maxMonsterHP * monsterStats;
	m_monsterDamage = m_monsterDamage * monsterStats;
	m_monsterDefence = m_monsterDefence * monsterStats;
	m_monsterHP = m_monsterHP * monsterStats;
}

void MonsterSys::MonsterInfo()
{
	std::cout << "Monster Name: " << GetMonsterName() << std::endl;
	std::cout << "Monster Attack: " << GetMonsterDamage() << std::endl;
	std::cout << "Monster Health points: " << GetMonsterHealthPoints() << std::endl;
	std::cout << "\n" << std::endl;
}

void MonsterSys::MonsterReceiveDamage(int playerDamage)
{
	m_monsterHP = m_monsterHP - playerDamage;
	if (m_monsterHP <= 0)
	{
		m_monsterHP = 0;
		m_isAlive = false;
		std::cout << "Congratulations!! You won the fight. " << std::endl;
		system("pause");
		system("cls");
	}
}
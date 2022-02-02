#pragma once
#include <string>

class MonsterSys
{

public:
	MonsterSys();
	~MonsterSys();

	std::string GetMonsterName() const;

	bool MonsterIsAlive() const; 

	int GetMonsterDamage() const; 
	int GetMonsterHealthPoints() const;
	void CreateMonster(const int monsterStats, const std::string& monsterName);
	void MonsterInfo() const;
	void MonsterReceiveDamage(const int playerDamage);

private:
	bool m_isAlive;

	int m_maxMonsterHP;
	int m_monsterDamage;
	int m_monsterDefence;
	int m_monsterHP;

	std::string m_monsterName;
};
#pragma once
#include <string>

class MonsterSys
{

public:

	MonsterSys(); // monster constructor
	~MonsterSys(); // monster destructor

	std::string GetMonsterName(); //TODO make it const

	bool MonsterIsAlive() const; // return if monster is alive or not (dead 0 false - alive 1 true).

	int GetMonsterDamage() const; // return monster damage
	int GetMonsterHealthPoints() const; //return monster health points
	void CreateMonster(int monsterStats, const std::string& monsterName); //TODO make paramenters const
	void MonsterInfo(); //TODO make const
	void MonsterReceiveDamage(int playerDamage); // deal damage to monster

private:

	bool m_isAlive;

	int m_maxMonsterHP;
	int m_monsterDamage;
	int m_monsterDefence;
	int m_monsterHP;

	std::string m_monsterName;
};
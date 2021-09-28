#pragma once
#include <string>

class MonsterSys
{
	enum class Name
	{
		RAT = 1,
		SNAKE = 2,
		WOLF = 3,
		BEAR =4,
		TROLL = 5,
		ORC = 6,
		FIRE_ELEMENTAL = 7, //BOSS
		ICE_ELEMENTAL = 8, //BOSS
	};
public:
	MonsterSys(Name);
	~MonsterSys();

	int GetDamage();
	int GetHealthPoints();
	void MonsterInfo(Name);
	int m_damagePoints;
	int m_healthPoints;
	Name m_name;
};


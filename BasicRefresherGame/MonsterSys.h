#pragma once
#include <string>

class MonsterSys
{
	//TODO: Cannot use Enum to Name monsters/Characters, probably we need to include this enum in Mapsys as well as character classes? 
	//TODO: Try making functions that contain information about the monsters instead to make the process simpler since Outside this class no other class can "know" what MonsterSys enums are
	enum class Name
	{
		RAT = 1,
		SNAKE = 2,
		WOLF = 3,
		BEAR = 4,
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


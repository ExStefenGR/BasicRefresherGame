#pragma once
#include <string>

class MonsterSys
{
	//TODO: Cannot use Enum to Name monsters/Characters, probably we need to include this enum in Mapsys as well as character classes? 
	//TODO: Try making functions that contain information about the monsters instead to make the process simpler since Outside this class no other class can "know" what MonsterSys enums are
	enum class MonsterStats
	{
		Rat = 1,
		Snake = 2,
		Wolf = 3,
		Bear = 4,
		Troll = 5,
		Orc = 6,
		Fire_Elemental = 7, //BOSS
		Ice_Elemental = 8, //BOSS
	};

public:

	MonsterSys(std::string monsterName, MonsterStats monsterStats);
	~MonsterSys();

	int GetDamage() const;
	int GetHealthPoints() const;
	
	void SetDamageToMonster(int Damage);
	void MonsterInfo(MonsterStats);

private:
	
	std::string m_monsterName;
	int m_monsterDamage;
	int m_monsterDefence;
	int m_maxMonsterHP;
	int m_monsterHP;

	MonsterStats m_stats;
};


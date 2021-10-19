#include "CombatSys.h"
#include <map>
#include <iostream>
#include <string>

CombatSys::CombatSys()
{
	m_player.GetCharacterClass();
	m_player.GetDamage();
	m_player.GetHealthPoints();
	m_player.GetManaPoints();
	m_player.GetName();
	m_player.GetSkills();	

	MonsterObjectMap monster;

	monster["RAT"] = 
}

CombatSys::~CombatSys()
{

}

void CombatSys::Fight()
{
	int option;

	while (option > 0 || option < 4)
	{
		std::cout << "Select one of the options" << std::endl;
		std::cout << "1 - Attack" << std::endl;
		std::cout << "2 - Spells" << std::endl;
		std::cout << "3 - Run" << std::endl;
		std::cin >> option;
	}
	
	GetCombatOptions(option);
}

CombatSys::Combat CombatSys::GetCombatOptions(int playerOption)
{
	switch (playerOption)
	{
	case static_cast<int>(Combat::Attack):
		std::cout << "You strike the monster, dealing damage!" << std::endl;
		return Combat(Combat::Attack);
		//MonsterSys.DealDamage(m_player.GetDamage());
		break;
	case static_cast<int>(Combat::Spells):
		std::cout << "You tap into your magic to use against the monster..." << std::endl;
		return Combat(Combat::Spells);
		break;
	case static_cast<int>(Combat::Run):
		std::cout << "You just book it!" << std::endl;
		return Combat(Combat::Run);
		break;
	default:
		std::cout << "default value";
		break;
	}
}
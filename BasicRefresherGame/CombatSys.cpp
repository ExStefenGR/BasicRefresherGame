#include "CombatSys.h"
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
}

CombatSys::~CombatSys()
{

}

void CombatSys::Fight()
{
	int option;
	std::cin >> option;

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
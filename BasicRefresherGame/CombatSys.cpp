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

void CombatSys::CombatOptions(int playerOption)
{
	switch (Combat)
	{
	case Combat::Attack:
		std::cout << "You strike the monster, dealing damage!" << std::endl;
		//MonsterSys.DealDamage(m_player.GetDamage());
		break;
	case Combat::Spells:
		std::cout << "You tap into your magic to use against the monster..." << std::endl;
		break;
	case Combat::Run:
		std::cout << "You just book it!" << std::endl;
		break;
	default:
		break;
	}
}

Combat CombatSys::GetCombatOptions()
{
	int option;

	cin option;
		CombatOptions(int playerOption);
	//if (GetCombatOptions())
}
#include "CombatSys.h"
#include <iostream>
#include <string>

CombatSys::CombatSys()
{
	MonsterObjectMap monster;

	Fight();

	//monster["RAT"] = m_monster;
}

CombatSys::~CombatSys()
{

}

void CombatSys::Fight()
{
	MonsterSys m_monster;

	int options;

	std::cin >> options;

	while (options > 0 || options < 4)
	{
		std::cout << "Select one of the options" << std::endl;
		std::cout << "1 - Attack" << std::endl;
		std::cout << "2 - Spells" << std::endl;
		std::cout << "3 - Run" << std::endl;
	}

	if (options == 1)
	{
		m_monster.SetDamageToMonster(m_player->GetDamage());
		std::cout << m_monster.GetHealthPoints() << std::endl;
		system("pause");
	}

	//GetCombatOptions(option);
}

CombatSys::Combat CombatSys::GetCombatOptions(int playerOption)
{
	switch (playerOption)
	{
		case static_cast<int>(Combat::Attack) :
			std::cout << "You strike the monster, dealing damage!" << std::endl;
			return Combat(Combat::Attack);
			//MonsterSys.DealDamage(m_player.GetDamage());
			break;
			case static_cast<int>(Combat::Spells) :
				std::cout << "You tap into your magic to use against the monster..." << std::endl;
				return Combat(Combat::Spells);
				break;
				case static_cast<int>(Combat::Run) :
					std::cout << "You just book it!" << std::endl;
					return Combat(Combat::Run);
					break;
				default:
					std::cout << "default value";
					break;
	}
}
#include "CombatSys.h"
#include <iostream>
#include <string>
#include "MapSys.h"

CombatSys::CombatSys(MapSys* map)
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
	//m_map = new MapSys();
	MonsterSys m_monster;
	int options;

	std::cout << "Select one of the options" << std::endl;
	std::cout << "1 - Attack" << std::endl;
	std::cout << "2 - Spells" << std::endl;
	std::cout << "3 - Run" << std::endl;

	std::cin >> options;

	switch (options)
	{
	case 1:
		//m_monster.SetDamageToMonster(m_map->GetPlayer()->GetDamage());

		std::cout << m_monster.GetMonsterHealthPoints() << std::endl;
		system("pause");
		//auto player = m_map->GetPlayer();
	default:
		break;
	}
	//GetCombatOptions(option);
}
//
//CombatSys::Combat CombatSys::GetCombatOptions(int playerOption)
//{
//	switch (playerOption)
//	{
//		case static_cast<int>(Combat::Attack) :
//			std::cout << "You strike the monster, dealing damage!" << std::endl;
//			return Combat(Combat::Attack);
//			//MonsterSys.DealDamage(m_player.GetDamage());
//			break;
//			case static_cast<int>(Combat::Spells) :
//				std::cout << "You tap into your magic to use against the monster..." << std::endl;
//				return Combat(Combat::Spells);
//				break;
//				case static_cast<int>(Combat::Run) :
//					std::cout << "You just book it!" << std::endl;
//					return Combat(Combat::Run);
//					break;
//				default:
//					std::cout << "default value";
//					return Combat(Combat::Run);
//					break;
//	}
//}
#include "MapSys.h"
//Locations and dialogue fully Programmed by Stefanos
//Combat programmed by David and Isaac
//Last edited 12/12/21

MapSys::MapSys()
{
	m_player->CreateCharacter();
	m_player->PlayerInfo();

	//Dialogue
	CreateDialog();
	SpeechPause();
}
MapSys::~MapSys() = default;
MapSys::Map MapSys::GetMapLoc() const
{
	return m_locations;
}
int MapSys::ValidateInput(int playerInput)const
{
	std::cin >> playerInput;

	while (playerInput != 1 && playerInput != 2)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid Input!" << std::endl;
		std::cin >> playerInput;
	}

	return playerInput;
}
void MapSys::CreateDialog()
{
	Area gameStart, beginning, forest, woods, port, town, colosseum, darkPortal, castleOfFire, darkShore, beach;

	gameStart.dialogue1 = "Welcome to <DungeonTexter>, A text RPG made by Stefanos, Isaac and David!";
	beginning.dialogue1 = "You find yourself in the middle of nowhere, You have 2 Paths, choose wisely..";
	forest.dialogue1 = "Slime has ambushed you!";
	port.dialogue1 = "You arrive at the port and spot a human ready to depart but he stops and waves at you..";
	town.dialogue1 = "You have arrived at the Local Town with the help of the Boat-Man";
	town.dialogue2 = "The Town seems quiet big for it to be called a 'Town'";
	town.dialogue3 = "A masked lady approaches you and hands you a necklace as she whispers";
	town.dialogue4 = "???: Arrive by nine tonight..";
	town.dialogue5 = "That approach seemed frightening, although you now come across a colluseum..";
	colosseum.dialogue1 = "You arrive at the colluseum, Choose what you would like to do..";
	darkPortal.dialogue1 = "???: You're here, then let us go..My name is Rose";
	darkPortal.dialogue2 = "You have entered the Dark portal, Monsters await..";
	darkShore.dialogue1 = "???: You have arrived...";
	darkShore.dialogue2 = "???: I did not expect you so soon...";
	darkShore.dialogue3 = "???: Welcome to my realm, enjoy your stay..Eternally that is..";
	darkShore.dialogue4 = "You find yourself in the shore, although something seems off, everything is dark and it seems like it is night-time..";
	darkShore.dialogue5 = "You seem not to be able to see your reflection in the water...";
	darkShore.dialogue6 = "???: Well, You are dead, what did you expect..?";
	beach.dialogue1 = "Rose: Good Job Traveler, looks like we will live another day";
	beach.dialogue2 = "Rose: Perhaps you would like to join our guild, It is not near town, we tend to travel a lot just like you";
	beach.dialogue3 = "Rose: I'll give you lots of time to think about it...";
	beach.dialogue4 = "It looks like you managed to defeat the Dark Knight and make a friend along the way";
	beach.dialogue5 = "Although you still do not know of your past, following Rose and joining the guild may be beneficial..";
	beach.dialogue6 = "The end...";
	beach.dialogue7 = "You have reached the end of the game, thanks a lot for playing!";

	dialogue.try_emplace("GameStart", gameStart);
	dialogue.try_emplace("Beginning", beginning);
	dialogue.try_emplace("Forest", forest);
	dialogue.try_emplace("Woods", woods);
	dialogue.try_emplace("Port", port);
	dialogue.try_emplace("Town", town);
	dialogue.try_emplace("Colosseum", colosseum);
	dialogue.try_emplace("DarkPortal", darkPortal);
	dialogue.try_emplace("CastleOfFire", castleOfFire);
	dialogue.try_emplace("DarkShore", darkShore);
	dialogue.try_emplace("Beach", beach);
}
void MapSys::DialogueSys(const Map& locations)
{
	switch (GetMapLoc())
	{
	case Map::GameStart:
		if (auto i = dialogue.find("GameStart"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	case Map::Beginning:
		if (auto i = dialogue.find("Beginning"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	case Map::Forest:
		if (auto i = dialogue.find("Forest"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;

	case Map::Woods:
		if (auto i = dialogue.find("Woods"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	case Map::Port:
		if (auto i = dialogue.find("Port"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	case Map::Town:
		for (const auto& [i, it] : dialogue)
		{
			auto ite = i.find("Town");
			if (ite != std::string::npos)
			{
				std::cout << it.dialogue1 << std::endl;
				SpeechPause();
				std::cout << it.dialogue2 << std::endl;
				SpeechPause();
				std::cout << it.dialogue3 << std::endl;
				SpeechPause();
				std::cout << it.dialogue4 << std::endl;
				SpeechPause();
				std::cout << it.dialogue5 << std::endl;
				SpeechPause();
			}
		}
		break;
	case Map::Colosseum:
		if (auto i = dialogue.find("Colosseum"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	case Map::DarkPortal:

		if (auto i = dialogue.find("DarkPortal"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue2 << std::endl;
			SpeechPause();
		}
		break;

	case Map::DarkShore:
		for (const auto& [i, it] : dialogue)
		{
			auto ite = i.find("DarkShore");
			if (ite != std::string::npos)
			{
				std::cout << it.dialogue1 << std::endl;
				SpeechPause();
				std::cout << it.dialogue2 << std::endl;
				SpeechPause();
				std::cout << it.dialogue3 << std::endl;
				SpeechPause();
				std::cout << it.dialogue4 << std::endl;
				SpeechPause();
				std::cout << it.dialogue5 << std::endl;
				SpeechPause();
				std::cout << it.dialogue6 << std::endl;
				SpeechPause();
			}
		}
		break;
	case Map::Beach:
		if (auto i = dialogue.find("Beach"); i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue2 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue3 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue4 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue5 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue6 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue7 << std::endl;
			SpeechPause();
		}
		break;
	default:
		break;
	}
}
void MapSys::LocController()
{
	while (!m_roomDone && m_player->IsAlive())
	{
		switch (m_locations)
		{
		case Map::GameStart:
			system("cls");
			std::cout << "Player location: GameStart\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();
			m_player->SetCharacterClass();
			SetMapLoc(Map::Beginning);
			break;
		case Map::Beginning:
			std::cout << "Player location: Beginning\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Ratta");
			MonsterFight();
			DialogueSys(m_locations);
			SpeechPause();

			std::cout << "1. Towards Forest" << std::endl;
			std::cout << "2. Towards Woods" << std::endl;

			m_choice = ValidateInput(m_choice);

			if (m_choice == 1)
			{
				SetMapLoc(Map::Forest);
			}
			if (m_choice == 2)
			{
				SetMapLoc(Map::Woods);
			}
			break;
		case Map::Forest:
			system("cls");
			std::cout << "Player location: Forest\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Slime");
			DialogueSys(m_locations);
			SpeechPause();
			MonsterFight();
			if (!m_runAway)
			{
				SetMapLoc(Map::Port);
			}
			break;
		case Map::Woods:
			system("cls");
			std::cout << "Player location: Woods\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Aracno");
			DialogueSys(m_locations);
			SpeechPause();
			MonsterFight();
			if (!m_runAway)
			{
				SetMapLoc(Map::Port);
			}
			break;
		case Map::Port:
			std::cout << "Player location: Port\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Nudibranch");
			MonsterFight();
			DialogueSys(m_locations);
			SpeechPause();

			std::cout << "1. Ask the Man for help" << std::endl;
			std::cout << "2. Try and Sabotage him (Will start a fight)" << std::endl;

			m_choice = ValidateInput(m_choice);

			if (m_choice == 1 && !m_runAway)
			{
				SetMapLoc(Map::Town);
			}
			if (m_choice == 2 && !m_runAway)
			{
				std::cout << "You attack the Boat owner" << std::endl;
				SpeechPause();
				//fight here then go to town
				SetMapLoc(Map::Town);
			}
			break;
		case Map::Town:
			std::cout << "Player location: Town\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();

			std::cout << "1. Visit the Lady during the night" << std::endl;
			std::cout << "2. Visit the Colosseum" << std::endl;

			m_choice = ValidateInput(m_choice);

			if (m_choice == 1 && !m_runAway)
			{
				SetMapLoc(Map::DarkPortal);
			}
			if (m_choice == 2 && !m_runAway)
			{
				SetMapLoc(Map::Colosseum);
			}
			break;
		case Map::Colosseum:
			std::cout << "Player location: Colusseum\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Slaughter");
			MonsterFight();
			if (!m_runAway)
			{
				SetMapLoc(Map::CastleOfFire);
			}
			break;
		case Map::DarkPortal:
			std::cout << "Player location: DarkPortal\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();
			MonsterFight();
			if (!m_runAway)
			{
				SetMapLoc(Map::CastleOfFire);
			}
			break;
		case Map::CastleOfFire:
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "BOSS: FireElemental");
			std::cout << "Player location: CastleOfFire\n" << std::endl;
			MonsterFight();
			DialogueSys(m_locations);
			SpeechPause();
			if (!m_runAway)
			{
				SetMapLoc(Map::Beach);
			}
			break;//BOSS
		case Map::DarkShore:
			std::cout << "Dark Shore" << std::endl;
			SpeechPause();
			m_player->PlayerReceiveDamage(m_player->GetHealthPoints());
			m_roomDone = true;
			break;//Bad ending
		case Map::Beach:
			std::cout << "Player location: Beach\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();
			SetMapLoc(Map::Win);
			break;//Good ending
		case Map::Win:
			std::cout << "WINNER WINNER CHICKEN DINNER!!\n" << std::endl;
			SpeechPause();
			m_roomDone = true;
			break;//Good ending
		default:
			m_roomDone = true;
			break;
		}
	}
}
void MapSys::MonsterFight()
{
	m_runAway = false;
	std::cout << "You are confronted by " << m_monster->GetMonsterName() << std::endl;

	while (m_monster->MonsterIsAlive() && m_runAway == false && m_player->IsAlive())
	{
		m_monster->MonsterInfo();

		std::cout << "Select an option:" << std::endl;
		std::cout << "1: Attack" << std::endl;
		std::cout << "2: Run" << std::endl;

		m_choice = ValidateInput(m_choice);

		if (m_choice == 1)
		{
			m_monster->MonsterReceiveDamage(m_player->GetDamage());
			if (m_monster->MonsterIsAlive() && m_player->IsAlive())
			{
				m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage(), m_runAway);
			}
			if (!m_player->IsAlive())
			{
				SetMapLoc(Map::DarkShore);
			}
			m_player->PlayerInfo();
		}
		if (m_choice == 2 && !(m_lastLocation == m_locations))
		{
			m_runAway = true;
			m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage(), m_runAway);
			if (m_player->IsAlive() == false)
			{
				SetMapLoc(Map::DarkShore);
			}
			m_player->PlayerInfo();
			std::cout << "You just book it\n" << std::endl;
			SetMapLoc(m_lastLocation);
		}
		else
		{
			std::cout << "You can`t run twice." << std::endl;
		}
	}
}
void MapSys::SetMapLoc(const Map& NewLoc)
{
	if (m_runAway)
	{
		m_locations = NewLoc;
		m_lastLocation = m_locations;
	}
	else
	{
		m_lastLocation = m_locations;
		m_locations = NewLoc;
	}
}
void MapSys::SpeechPause() const
{
	system("pause");
	system("cls");
}
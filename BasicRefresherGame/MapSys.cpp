#include "MapSys.h"
//Programmed by Stefanos

MapSys::MapSys()
{
	m_locations = Map::GameStart;
	m_getLocation = 0;
	m_setLocation = 0;
	m_choice = 0;
	m_choiceMade = false;
	m_roomDone = false;
	m_player = new CharacterSys();
	m_player->CreateCharacter();
	m_player->PlayerInfo();
}
MapSys::~MapSys() {}
MapSys::Map MapSys::GetMapLoc()
{
	return m_locations;
}
MapSys::Map MapSys::SetMapLoc(Map NewLoc)
{
	m_locations = NewLoc;
	return m_locations;
}
void MapSys::LocController()
{
	while (!m_roomDone)
	{
		switch (m_locations)
		{
		case Map::GameStart:
		{
			DialogueSys(m_locations);
			m_player->SetCharacterClass();
			SetMapLoc(Map::Beginning);
			break;
		}
		case Map::Beginning:
		{
			DialogueSys(m_locations);
			SetMapLoc(Map::Forest);
			break;
		}
		case Map::Forest:
		{
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::Woods:
		{
			DialogueSys(m_locations);
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			ChoiceSys(m_locations);
			SetMapLoc(Map::Town);
			break;
		}
		case Map::Shore:
		{
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			DialogueSys(m_locations);
			SetMapLoc(Map::DarkPortal);
			break;
		}
		case Map::Town:
		{
			DialogueSys(m_locations);
			ChoiceSys(m_locations);
			
			break;
		}
		case Map::Colosseum:
		{
			break;
		}
		case Map::DarkPortal:
		{
			DialogueSys(m_locations);
			SetMapLoc(Map::CastleOfFire);
			break;
		}
		case Map::CastleOfFire:
			DialogueSys(m_locations);
			SetMapLoc(Map::Beach);
			break;//BOSS
		case Map::DarkShore:
			break;//Bad ending
		case Map::Beach:
			break;//Good ending
		default:
			std::cout << "error?" << std::endl;
			break;
		}
	}
}
void MapSys::DialogueSys(Map& m_locations)
{
	switch (GetMapLoc())
	{
	case (Map::GameStart):
	{
		std::cout << "Greetings Traveler, welcome to <DungeonCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		SpeechPause();
		break;
	}
	case (Map::Beginning):
	{
		std::cout << "You find yourself in the middle of nowhere, You have 2 Paths, choose wisely.." << std::endl;
		SpeechPause();
		ChoiceSys(m_locations);
	}
	case (Map::Forest):
	{
		std::cout << "Slime has ambushed you!" << std::endl; //Placeholder, can be accessed once
		SpeechPause();
		break;
	}
	case (Map::Woods):
	{
		std::cout << "???: (Grizly bear sounds)" << std::endl; //Placeholder, can be accessed once
		SpeechPause();
		//TODO:Big bear Fight here
		//TODO:Make him have High def and low HP but higher Attack than slime
		//std::cout << "Your strength has increased!" << std::endl;
		//m_player.SetDamage(+10);
		//m_player.PlayerInfo();
		break;
	}
	case (Map::Port):
	{
		std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
		break;
	}
	case (Map::Shore):
	{
		std::cout << "You are now at the shore after fighting that weird monster, You look beneath you and find an item in the sand" << std::endl;
		SpeechPause();
		break;
	}
	case (Map::Town):
	{
		std::cout << "You have arrived at the Local Town with the help of the Boat-Man" << std::endl;
		SpeechPause();
		//TODO:: Dialogue system std::cout << "Boat-Man: Alright " << m_player.GetName() << " We have arrived, get your things and get going" << std::endl;
		std::cout << "You leave the boat and begin looking around the shops of the town, without any money its of no use, but you browse anyway" << std::endl;
		SpeechPause();
		std::cout << "A lady walks past you and give you a necklace and whispers.." << std::endl;
		SpeechPause();
		std::cout << "???: Come back here at night, There is big trouble in the Woods.." << std::endl;
		SpeechPause();
		std::cout << "You heard the lady and wore the necklace, it seems to hold a magical power to it.." << std::endl;
		SpeechPause();
		break;
	}
	case (Map::DarkPortal):
	{
		std::cout << "???: You're here, then let us go.." << std::endl;
		SpeechPause();
		std::cout << "You have entered the Dark portal, Monsters await.." << std::endl;
		SpeechPause();
		break;
	}
	case (Map::CastleOfFire):
	{
		break;
	}
	case (Map::DarkShore):
	{
		std::cout << "???: You have arrived..." << std::endl;
		SpeechPause();
		std::cout << "???: I did not expect you so soon..." << std::endl;
		SpeechPause();
		std::cout << "???: Welcome to my realm, enjoy your stay..Eternally that is.." << std::endl;
		SpeechPause();
		std::cout << "You find yourself in the shore, although something seems off, everything is dark and it seems like it is night-time.." << std::endl;
		SpeechPause();
		std::cout << "You seem not to be able to see your reflection in the water..." << std::endl;
		SpeechPause();
		std::cout << "???: Well, You are dead, what did you expect..?" << std::endl;
		SpeechPause();
		break;
	}
	case (Map::Beach):
	{
		break;
	}
	default:
	{
		std::cout << "DialogueSystem Malfunction: Beyond Range" << std::endl;
		break;
	}
	}
}
void MapSys::ChoiceSys(Map& m_locations)
{
	switch (m_locations)
	{
	case (Map::Beginning):
	{
		std::cout << "1. Towards Forest" << std::endl;
		std::cout << "2. Towards Woods" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				SetMapLoc(Map::Forest);
				m_choiceMade = true;
				break;
			}
			case 2:
			{
				SetMapLoc(Map::Woods);
				m_choiceMade = true;
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				break;
			}
			}
		}
		break;
	}
	case (Map::Port):
	{
		std::cout << "1. Ask the Man for help" << std::endl;
		std::cout << "2. Try and Sabotage him (Will start a fight)" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				DialogueSys(m_locations);
				m_choiceMade = true;
				break;
			}
			case 2:
			{
				std::cout << "You attack the Boat owner" << std::endl;
				SpeechPause();
				//fight here then go to town
				SetMapLoc(Map::Town);
				m_choiceMade = true;
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				m_choiceMade = true;
				break;
			}
			}
		}
		break;
	}
	case (Map::Town):
	{
		std::cout << "1. Visit the Lady during the night" << std::endl;
		std::cout << "2. Visit the Colosseum" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				SetMapLoc(Map::DarkPortal);
				m_choiceMade = true;
				break;
			}
			case 2:
			{
				SetMapLoc(Map::Colosseum);
				SpeechPause();
				//colluseum will have its own ChoiceSystem where the player can fight different monsters of their choice
				m_choiceMade = true;
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				m_choiceMade = true;
				break;
			}
			}
		}
		break;
	}

	default:
	{
		std::cout << "Function ChoiceSys called outside normal operation" << std::endl;
		break;
	}

	}
}
void MapSys::SpeechPause()
{
	system("pause");
	system("cls");
}
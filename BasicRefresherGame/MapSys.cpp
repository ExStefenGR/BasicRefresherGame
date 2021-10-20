#include "MapSys.h"
//Programmed by Stefanos
//Last edited 20/10/21

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

	Area gameStart;
	Area beginning;
	Area town;

	gameStart.dialogue1 = "Welcome to <DungeonTexter>, A text RPG made by Stefanos, Isaac and David!";
	beginning.dialogue1 = "You find yourself in the middle of nowhere, You have 2 Paths, choose wisely..";
	town.dialogue1 = "You have arrived at the Local Town with the help of the Boat-Man";
	town.dialogue2 = "The Town seems quiet big for it to be called a 'Town'";
	town.dialogue3 = "A masked lady approaches you and hands you a necklace as she whispers";
	town.dialogue4 = "???: Arrive by nine tonight..";
	town.dialogue5 = "That approach seemed frightening, although you now come across a colluseum..";

	dialogue.insert(std::pair<std::string, Area>("GameStart", gameStart));
	dialogue.insert(std::pair<std::string, Area>("Beginning", beginning));
	dialogue.insert(std::pair<std::string, Area>("Town", town));
}
MapSys::~MapSys() {}
MapSys::Map MapSys::GetMapLoc() const
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
			std::cout << "GameStart" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			m_player->SetCharacterClass();
			SetMapLoc(Map::Beginning);
			break;
		}
		case Map::Beginning:
		{
			std::cout << "Beginning" << std::endl;
			DialogueSys(m_locations);
			break;
		}
		case Map::Forest:
		{
			std::cout << "Forest" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::Woods:
		{
			std::cout << "Woods" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			std::cout << "Port" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			ChoiceSys(m_locations);
			SetMapLoc(Map::Town);
			break;
		}
		case Map::Shore:
		{
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			std::cout << "Shore" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::DarkPortal);
			break;
		}
		case Map::Town:
		{
			std::cout << "Town" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			ChoiceSys(m_locations);

			break;
		}
		case Map::Colosseum:
		{
			std::cout << "Colusseum" << std::endl;
			SpeechPause();
			break;
		}
		case Map::DarkPortal:
		{
			std::cout << "DarkPortal" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::CastleOfFire);
			break;
		}
		case Map::CastleOfFire:
			std::cout << "CastleOfFire" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::Beach);
			break;//BOSS
		case Map::DarkShore:
			break;//Bad ending
		case Map::Beach:
			break;//Good ending
		default:
			std::cout << "Location Cotroller malfunction" << std::endl;
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
		auto i = dialogue.find("GameStart");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		else
		{
			std::cout << "Town Not found" << std::endl;
		}
		break;
	}
	case (Map::Beginning):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("Beginning");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
			}
		}
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
		SpeechPause();
		ChoiceSys(m_locations);
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
		//auto i = dialogue.find("Town1");
		//if (i != dialogue.end())

		for (const auto& i : dialogue)
		{
			auto it = i.first.find("Town");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue4 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue5 << std::endl;
			}
		}
		break;
	}
	case (Map::Colosseum):
	{
		std::cout << "You arrive at the colluseum, Choose what you would like to do" << std::endl;
		ChoiceSys(m_locations);
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
				LocController();
				break;
			}
			case 2:
			{
				SetMapLoc(Map::Woods);
				LocController();
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
				SetMapLoc(Map::Town);
				LocController();
				break;
			}
			case 2:
			{
				std::cout << "You attack the Boat owner" << std::endl;
				SpeechPause();
				//fight here then go to town
				SetMapLoc(Map::Town);
				LocController();
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
void MapSys::SpeechPause() const
{
	system("pause");
	system("cls");
}
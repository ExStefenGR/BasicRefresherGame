#include "MapSys.h"
//Programmed by Stefanos
MapSys::MapSys()
{
	//TODO:: MapSystem -> CombatSystem -> CharacterSystem
	m_roomDone = false;
	m_locations = Map::GameStart;
	m_getLocation = 0;
	m_setLocation = 0;
}
MapSys::~MapSys() {} //Gets Destroyed when the game closes
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
			SetMapLoc(Map::Beginning);
			break;
		}
		case Map::Beginning:
		{
			DialogueSys(m_locations);
			SetMapLoc(Map::Forest);
			//TODO:: Add classes intro here
			break;
		}
		case Map::Forest:
		{
			DialogueSys(m_locations);
			//TODO:This will have to do with the Magician Route, add a fight with a magical monster/character
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::DeepForest:
		{
			DialogueSys(m_locations);
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			DialogueSys(m_locations);
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
			SetMapLoc(Map::DarkPortal);
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
void MapSys::DialogueSys(Map m_locations)
{
	switch (GetMapLoc())
	{
	case (MapSys::Map::GameStart):
	{
		std::cout << "Greetings Traveler, welcome to <DungeonCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::Beginning):
	{
		std::cout << "You find yourself in the middle of nowhere" << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::Forest):
	{
		std::cout << "You have encountered a Slime!" << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::DeepForest):
	{
		std::cout << "???: (Grizly bear sounds)" << std::endl; //Secret Boss?
		SpeechPause();
		//TODO:Big bear Fight here
		//TODO:Make him have High def and low HP but higher Attack than slime
		std::cout << "Your strength has increased!" << std::endl;
		//m_player.SetDamage(+10);
		//m_player.PlayerInfo();
		break;
	}
	case (MapSys::Map::Port):
	{
		std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
		break;
	}
	case (MapSys::Map::Shore):
	{
		std::cout << "You are now at the shore after fighting that weird monster, You look beneath you and find an item in the sand" << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::Town):
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
	case (MapSys::Map::DarkPortal):
	{
		std::cout << "???: You're here, then let us go.." << std::endl;
		SpeechPause();
		std::cout << "You have entered the Dark portal, Monsters await.." << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::CastleOfFire):
	{
		break;
	}
	case (MapSys::Map::DarkShore):
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
	case (MapSys::Map::Beach):
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
void MapSys::SpeechPause()
{
	system("pause");
	system("cls");
}


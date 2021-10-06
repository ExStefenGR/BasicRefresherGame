#include "DialogueSys.h"

DialogueSys::DialogueSys()
{
	m_playerLoc.GetMapLoc();
}

DialogueSys::~DialogueSys()
{
}

void DialogueSys::SpeechDialogue()
{
	switch (m_playerLoc.GetMapLoc())
	{
	case (MapSys::Map::GameStart):
	{
		std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		SpeechPause();
		break;
	}
	case (MapSys::Map::Beginning):
	{
		std::cout << "You find yourself in the middle of nowhere" << std::endl;
		SpeechPause();
		MapSys::LocController;
		break;
	}
	case (MapSys::Map::Forest):
	{
		std::cout << "You have encountered a Slime!" << std::endl;
		SpeechPause();
		MapSys::LocController;
		break;
	}
	case (MapSys::Map::DeepForest):
	{
		break;
	}
	case (MapSys::Map::Port):
	{
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
		break;
	}
	case (MapSys::Map::CastleOfFire):
	{
		break;
	}
	case (MapSys::Map::DarkShore):
	{
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

void DialogueSys::SpeechPause()
{
	system("pause");
	system("cls");
}

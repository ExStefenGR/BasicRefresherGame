#include "DialogueSys.h"

DialogueSys::DialogueSys()
{
	MapSys* m_locations = 0;
}

DialogueSys::~DialogueSys()
{
}

void DialogueSys::SpeechDialogue()
{
	switch (const int(m_locations))
	{
	case (static_cast<int>(MapSys::Map::GameStart)):
	{
		std::cout << "Greetings Traveler, welcome to <DungeonCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		SpeechPause();
		break;
	}
	case (static_cast<int>(MapSys::Map::Beginning)):
	{
		std::cout << "You find yourself in the middle of nowhere" << std::endl;
		SpeechPause();
		break;
	}
	case (static_cast<int>(MapSys::Map::Forest)):
	{
		std::cout << "You have encountered a Slime!" << std::endl;
		SpeechPause();
		break;
	}
	case (static_cast<int>(MapSys::Map::DeepForest)):
	{
		break;
	}
	case (static_cast<int>(MapSys::Map::Port)):
	{
		break;
	}
	case (static_cast<int>(MapSys::Map::Shore)):
	{
		std::cout << "You are now at the shore after fighting that weird monster, You look beneath you and find an item in the sand" << std::endl;
		SpeechPause();
		break;
	}
	case (static_cast<int>(MapSys::Map::Town)):
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
	case (static_cast<int>(MapSys::Map::DarkPortal)):
	{
		break;
	}
	case (static_cast<int>(MapSys::Map::CastleOfFire)):
	{
		break;
	}
	case (static_cast<int>(MapSys::Map::DarkShore)):
	{
		break;
	}
	case (static_cast<int>(MapSys::Map::Beach)):
	{
		break;
	}
	default:
	{
		std::cout << "DialogueSystem Malfunction: Beyond Range" << std::endl;
		break;
	}
	}
	MapSys LocController();
}

void DialogueSys::SpeechPause()
{
	system("pause");
	system("cls");
}

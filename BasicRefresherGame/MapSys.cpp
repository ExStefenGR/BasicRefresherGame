#include "MapSys.h"

MapSys::MapSys()
{
	m_roomDone = false;
	m_player = {};
	m_locations = GAMESTART;
	m_getLocation = 0;
	m_setLocation = 0;
}

MapSys::~MapSys() {} //Gets Destroyed when the game closes

void MapSys::GetMapLoc()
{
	m_getLocation = m_locations;
}

int MapSys::SetMapLoc(int location)
{
	location = m_setLocation;
	m_setLocation = m_getLocation;
	return  m_setLocation;
}

void MapSys::LocController()
{
	std::cout << "Player name? " << m_player.GetName() << std::endl;
	m_player.SetName();
	switch (m_locations)
	{
	case GAMESTART:
		std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		m_player.PlayerInfo();
		SpeechText();
		SetMapLoc(BEGINNING);
		//CharacterSysHere

	case BEGINNING:
	{
		while (!m_roomDone)
		{
			std::cout << "You find yourself in the middle of nowhere" << std::endl;
			SpeechText();
			m_player.SetCharacterClass();
			if (m_player.GetCharacterClass() == 1)
			{
				std::cout << "You have unlocked the sword" << std::endl;
				SpeechText();
				m_player.SetDamage(+7);
				std::cout << "Damage Increased" << std::endl;
				m_player.PlayerInfo();
				SpeechText();
				SetMapLoc(DEEPFOREST);
			}
			else if (m_player.GetCharacterClass() == 2)
			{
				std::cout << "You have unlocked the sword" << std::endl;
				SpeechText();
				m_player.SetDamage(+4);
				m_player.SetManaPoints(+10);
				std::cout << "Damage and Mana Increased" << std::endl;
				m_player.PlayerInfo();
				SpeechText();
				SetMapLoc(FOREST);
			}
		}
	}
	case FOREST:
	{
		m_roomDone = false;
		while (m_roomDone)
		{
			//This will have to do with the Magician Route, add a fight with a magical monster/character
			//Note if nothing is written in a case then it will automatically go to the next
			std::cout << "You have encountered a Slime!" << std::endl;
			//TODO:Make the slime have high HP and low attack, def should be medium
		}
	}
	case DEEPFOREST:
		std::cout << "???: h3ll0 My Est33mED [[ONEDOLLAR]] CUSTom er!1" << std::endl;//Secret Boss?
		SpeechText();
		//TODO:Include fight here with spamton from Deltarune Because that is the game I played recently and I'm bored
		//TODO:Make him have High def and low HP but higher Attack than slime

	case PORT: 

	case SHORE: //Secret item?
	case TOWN: //SafeArea
	case DARKPORTAL:
	case CASTLEOFFIRE: //BOSS
	case CASTLEOFICE:  //BOSS
	case DARKSHORE: //Bad ending
	case BEACH: //Good ending
	default:
		std::cout << "error?" << std::endl;
		break;
	}
}

void MapSys::SpeechText()
{
	system("pause");
	system("cls");
}

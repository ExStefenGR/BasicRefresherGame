#include "MapSys.h"

MapSys::MapSys()
{
	m_roomDone = false;
	m_player = {};
	m_locations = Map::GameStart;
	m_getLocation = 0;
	m_setLocation = 0;
}

MapSys::~MapSys() {} //Gets Destroyed when the game closes

void MapSys::GetMapLoc()
{
	auto m_getLocation = static_cast<int>(m_locations);
}

MapSys::Map MapSys::SetMapLoc(Map NewLoc)
{
	m_locations = NewLoc;
	return m_locations;
	//m_setLocation = m_getLocation;
}

void MapSys::LocController()
{
	std::cout << "Player name? " << m_player.GetName() << std::endl;
	m_player.SetName();
	while (!m_roomDone)
	{
		switch (m_locations)
		{
		case Map::GameStart:
			std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
			m_player.PlayerInfo();
			SpeechText();
			SetMapLoc(Map::Beginning);
			break;
		case Map::Beginning:
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
				SetMapLoc(Map::DeepForest);
			}
			else if (m_player.GetCharacterClass() == 2)
			{
				std::cout << "You have unlocked the staff" << std::endl;
				SpeechText();
				m_player.SetDamage(+4);
				m_player.SetManaPoints(+10);
				std::cout << "Damage and Mana Increased" << std::endl;
				m_player.PlayerInfo();
				SpeechText();
				SetMapLoc(Map::Forest);
			}
			break;
		}
		case Map::Forest:
		{
			m_roomDone = false;
			//This will have to do with the Magician Route, add a fight with a magical monster/character
			//Note if nothing is written in a case then it will automatically go to the next
			std::cout << "You have encountered a Slime!" << std::endl;
			SpeechText();
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::DeepForest:
			std::cout << "???: h3ll0 My Est33mED [[ONEDOLLAR]] CUSTom er!1" << std::endl;//Secret Boss?
			SpeechText();
			//TODO:Include fight here with spamton from Deltarune Because that is the game I played recently and I'm bored
			//TODO:Make him have High def and low HP but higher Attack than slime
			break;
		case Map::Port:
			std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
			SpeechText();
			if (m_player.GetCharacterClass() == static_cast<int>(Job::Staff))
			{
				std::cout << "???: Hey are you " << m_player.GetName() << "? I Wasn't expecting you were a Wizard" << std::endl;
			}
			else if (m_player.GetCharacterClass() == static_cast<int>(Job::Shield))
			{
				std::cout << "???: Hey are you " << m_player.GetName() << "? I Wasn't expecting you were a Knight, Why would anyone carry a door for a shield?" << std::endl;
			}
			else
			{
				SetMapLoc(Map::Shore);
			}
			SpeechText();
			break;
		case Map::Shore: 
			break;//Secret item?
		case Map::Town: 
			break;//SafeArea
		case Map::DarkPortal:
			break;
		case Map::CastleOfFire:
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

void MapSys::SpeechText()
{
	system("pause");
	system("cls");
}
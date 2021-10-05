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
				std::cout << "You have unlocked the sword, you're a Knight!" << std::endl;
				SpeechText();
				m_player.SetDamage(+8);
				m_player.SetManaPoints(+5);
				std::cout << "Damage and Mana Increased" << std::endl;
				m_player.PlayerInfo();
				SpeechText();
				SetMapLoc(Map::DeepForest);
			}
			else if (m_player.GetCharacterClass() == 2)
			{
				std::cout << "You have unlocked the staff, you're a Mage!" << std::endl;
				SpeechText();
				m_player.SetDamage(+4);
				m_player.SetManaPoints(+15);
				std::cout << "Damage and Mana Increased" << std::endl;
				m_player.PlayerInfo();
				SpeechText();
				SetMapLoc(Map::Forest);
			}
			else if (m_player.GetCharacterClass() == 3)
			{
				std::cout << "You have unlocked the bow, you're a Archer" << std::endl;
				SpeechText();
				m_player.SetDamage(+6);
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
			SetMapLoc(Map::Shore);
			break;
		case Map::Port:
			std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
			SpeechText();
			if (m_player.GetCharacterClass() == static_cast<int>(Job::Staff))
			{
				std::cout << "???: Hey are you " << m_player.GetName() << "? I Wasn't expecting you were a Wizard" << std::endl;
			}
			else if (m_player.GetCharacterClass() == static_cast<int>(Job::Bow))
			{
				std::cout << "???: Hey are you " << m_player.GetName() << "? I Wasn't expecting you were a Knight, Why would anyone carry a door for a shield?" << std::endl;
			}
			else
			{
				SetMapLoc(Map::Shore);
			}
			SpeechText();
			SetMapLoc(Map::Town);
			break;
		case Map::Shore: 
			std::cout << "You are now at the shore after fighting that weird monster, You look beneath you and find an item in the sand" << std::endl;
			SpeechText();
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			SetMapLoc(Map::DarkPortal);
			break;
		case Map::Town:
			std::cout << "You have arrived at the Local Town with the help of the Boat-Man" << std::endl;
			SpeechText();
			std::cout << "Boat-Man: Alright " << m_player.GetName() << " We have arrived, get your things and get going" << std::endl;
			SpeechText();
			std::cout << "You leave the boat and begin looking around the shops of the town, without any money its of no use, but you browse anyway" << std::endl;
			SpeechText();
			std::cout << "A lady walks past you and give you a necklace and whispers.." << std::endl;
			SpeechText();
			std::cout << "???: Come back here at night, There is big trouble in the Woods.." << std::endl;
			SpeechText();
			std::cout << "You heard the lady and wore the necklace, it seems to hold a magical power to it.." << std::endl;
			SpeechText();
			//Add Item Acquired text and a boost in Magic and Damage 
			break;
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
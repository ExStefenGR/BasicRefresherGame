#include "MapSys.h"

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
	return MapSys::Map(m_locations);
}
MapSys::Map MapSys::SetMapLoc(Map NewLoc)
{
	m_locations = NewLoc;
	return m_locations;
	//m_setLocation = m_getLocation;
}
void MapSys::LocController()
{
	while (!m_roomDone)
	{
		switch (m_locations)
		{
		case Map::GameStart:
			std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
			SpeechText();
			SetMapLoc(Map::Beginning);
			break;
		case Map::Beginning:
		{
			std::cout << "You find yourself in the middle of nowhere" << std::endl;
			SpeechText();
			break;
		}
		case Map::Forest:
		{
			//TODO:his will have to do with the Magician Route, add a fight with a magical monster/character
			std::cout << "You have encountered a Slime!" << std::endl;
			SpeechText();
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::DeepForest:
		{
			std::cout << "???: (Grizly bear sounds)" << std::endl; //Secret Boss?
			SpeechText();
			//TODO:Big bear Fight here
			//TODO:Make him have High def and low HP but higher Attack than slime
			std::cout << "Your strength has increased!" << std::endl;
			//m_player.SetDamage(+10);
			//m_player.PlayerInfo();
			SpeechText();
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
			SpeechText();
			SetMapLoc(Map::Town);
			break;
		}
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
			//TODO:: Dialogue system std::cout << "Boat-Man: Alright " << m_player.GetName() << " We have arrived, get your things and get going" << std::endl;
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
			SpeechText();
			std::cout << "???: You're here, then let us go.." << std::endl;
			SpeechText();
			std::cout << "You have entered the Dark portal, Monsters await.." << std::endl;;
			SpeechText();
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
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
			DialogueSys SpeechDialogue();
			SetMapLoc(Map::Beginning);
			break;
		case Map::Beginning:
		{
			DialogueSys SpeechDialogue();
			//TODO:: Add classes intro here
			break;
		}
		case Map::Forest:
		{
			//TODO:This will have to do with the Magician Route, add a fight with a magical monster/character
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::DeepForest:
		{
			std::cout << "???: (Grizly bear sounds)" << std::endl; //Secret Boss?
			//TODO:Big bear Fight here
			//TODO:Make him have High def and low HP but higher Attack than slime
			std::cout << "Your strength has increased!" << std::endl;
			//m_player.SetDamage(+10);
			//m_player.PlayerInfo();
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			std::cout << "You arrive at the port and spot a human ready to depart but he stops and waves at you.." << std::endl;
			SetMapLoc(Map::Town);
			break;
		}
		case Map::Shore:
			std::cout << "You are now at the shore after fighting that weird monster, You look beneath you and find an item in the sand" << std::endl;
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			SetMapLoc(Map::DarkPortal);
			break;
		case Map::Town:
			//Add Item Acquired text and a boost in Magic and Damage 
			break;
		case Map::DarkPortal:
			std::cout << "???: You're here, then let us go.." << std::endl;
			std::cout << "You have entered the Dark portal, Monsters await.." << std::endl;;
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
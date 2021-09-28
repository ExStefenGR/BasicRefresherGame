#include "MapSys.h"

MapSys::MapSys()
{
	player_m = {};
	playerPos_m = GAMESTART;
	getLocation_m = 0;
	setLocation_m = 0;
}

MapSys::~MapSys(){} //Gets Destroyed when the game closes

void MapSys::GetMapLoc()
{
	getLocation_m = playerPos_m;
}

void MapSys::SetMapLoc()
{
	setLocation_m = playerPos_m;
}

void MapSys::LocController()
{
	std::cout << "Player name: " << player_m.getName() << std::endl;
	std::cout << "Player damage: " << player_m.getDamage() << std::endl;
	std::cout << "Player health points: " << player_m.getHealthPoints() << std::endl;
	std::cout << "Player mana points: " << player_m.getManaPoints() << std::endl;

	switch (playerPos_m)
	{
	case GAMESTART:
		std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		SpeechText();
		//CharacterSysHere

	case BEGINNING:
		std::cout << "You find yourself in the middle of nowhere" << std::endl;
		SpeechText();
	case FOREST:
	case DEEPFOREST: //Secret Boss?
	case NEARSEA:
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

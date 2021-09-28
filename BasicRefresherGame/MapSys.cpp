#include "MapSys.h"

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
	switch (playerPos_m)
	{
	case GAMESTART:
		std::cout << "Greetings Traveler, welcome to <DungeonLikeWithCombatAndStuff>. Made by Stefanos , David and Isaac" << std::endl;
		system("pause");
		system("cls");
		//CharacterSysHere

	case BEGINNING:
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

#include <iostream>
#include <string>
#include "CharacterSys.h"
#include "MapSys.h"

int main()
{
	MapSys playerLoc;
	playerLoc.LocController();

	std::cout << "GAME END" << std::endl;

	return 0;
}
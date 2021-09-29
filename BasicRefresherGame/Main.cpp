/*-Turn based combat
  -Maybe Items or damage multipliers
  -character stats and job system will carry out information throughout the game and we also need to be able to edit them/alter them
  -inter-connected areas
  -boss fights
  -multiple paths, some harder and more rewarding, others easier with less rewards
  */

#include <iostream>
#include <string>
#include "CharacterSys.h"
#include "CombatSys.h"
#include "MapSys.h"

int main()
{
	MapSys playerLoc;
	playerLoc.LocController();
	return 0;
}
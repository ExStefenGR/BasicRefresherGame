/*-Turn based combat
  -Maybe Items or damage multipliers
  -character stats and job system will carry out information throughout the game and we also need to be able to edit them/alter them
  -inter-connected areas
  -boss fights
  -multiple paths, some harder and more rewarding, others easier with less rewards
  */

#include "iostream";
#include "string";
#include "CharacterSys.h"
#include "CombatSys.h"
#include "MapSys.h"

int main()
{
	CharacterSys player;

	std::cout << "Player name: " << player.getName() << std::endl;
	std::cout << "Player damage: " << player.getDamage() << std::endl;
	std::cout << "Player health points: " << player.getHealthPoints() << std::endl;
	std::cout << "Player mana points: " << player.getManaPoints()  << std::endl;
	return 0;
}
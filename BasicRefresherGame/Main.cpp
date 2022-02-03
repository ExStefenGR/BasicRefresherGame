#include <iostream>
#include <string>
#include "CharacterSys.h"
#include "MapSys.h"

int main()
{
	bool playAgain = false;

	do {
		MapSys playerLoc;
		playerLoc.LocController();

		std::cin.clear();
		std::cout << "Do you want to play again?" << std::endl;
		std::cout << "1 - Play again\n 0 - Exit" << std::endl;
		std::cin >> playAgain;

		while (playAgain >= 0 || playAgain <= 1)
		{
			std::cout << "Incorrect input, please type again." << std::endl;
			std::cout << "1 - Play again\n0 - Exit" << std::endl;
			std::cin.clear();
			std::cin >> playAgain;
		}
	} while (playAgain);

	std::cout << "GAME END" << std::endl;

	return 0;
}
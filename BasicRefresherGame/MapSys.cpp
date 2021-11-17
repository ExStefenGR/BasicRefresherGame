#include "MapSys.h"
//Programmed by Stefanos
//Last edited 20/10/21

MapSys::MapSys()
{
	m_locations = Map::GameStart;
	m_getLocation = 0;
	m_setLocation = 0;
	m_choice = 0;
	m_choiceMade = false;
	m_roomDone = false;
	m_monster = new MonsterSys();
	m_player = new CharacterSys();
	m_player->CreateCharacter();
	m_player->PlayerInfo();

	CreateDialog();
}

MapSys::~MapSys()
{

}

MapSys::Map MapSys::GetMapLoc() const
{
	return m_locations;
}

void MapSys::ChoiceSys()
{
	switch (GetMapLoc())
	{
	case (Map::Beginning):
	{
		std::cout << "1. Towards Forest" << std::endl;
		std::cout << "2. Towards Woods" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				SetMapLoc(Map::Forest);
				LocController();
				break;
			}
			case 2:
			{
				SetMapLoc(Map::Woods);
				LocController();
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				break;
			}
			}
		}
		break;
	}
	case (Map::Port):
	{
		std::cout << "1. Ask the Man for help" << std::endl;
		std::cout << "2. Try and Sabotage him (Will start a fight)" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				SetMapLoc(Map::Town);
				LocController();
				break;
			}
			case 2:
			{
				std::cout << "You attack the Boat owner" << std::endl;
				SpeechPause();
				//fight here then go to town
				SetMapLoc(Map::Town);
				LocController();
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				m_choiceMade = true;
				break;
			}
			}
		}
		break;
	}
	case (Map::Town):
	{
		std::cout << "1. Visit the Lady during the night" << std::endl;
		std::cout << "2. Visit the Colosseum" << std::endl;
		m_choiceMade = false;
		while (!m_choiceMade)
		{
			if (!(std::cin >> m_choice))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Invalid Input!" << std::endl << std::endl;
				continue;
			}
			switch (m_choice)
			{
			case 1:
			{
				SetMapLoc(Map::DarkPortal);
				m_choiceMade = true;
				break;
			}
			case 2:
			{
				SetMapLoc(Map::Colosseum);
				SpeechPause();
				//colluseum will have its own ChoiceSystem where the player can fight different monsters of their choice
				m_choiceMade = true;
				break;
			}
			default:
			{
				std::cout << "Choice is not there, try again.." << std::endl;
				m_choiceMade = true;
				break;
			}
			}
		}
		break;
	}
	default:
	{
		std::cout << "Function ChoiceSys called outside normal operation" << std::endl;
		break;
	}
	}
}

void MapSys::CreateDialog()
{
	Area gameStart, beginning, forest, woods, port, shore, town, colosseum, darkPortal, castleOfFire, darkShore, beach;

	gameStart.dialogue1 = "Welcome to <DungeonTexter>, A text RPG made by Stefanos, Isaac and David!";
	beginning.dialogue1 = "You find yourself in the middle of nowhere, You have 2 Paths, choose wisely..";
	forest.dialogue1 = "Slime has ambushed you!";
	woods.dialogue1 = "???:(Grizly bear sounds)";
	port.dialogue1 = "You arrive at the port and spot a human ready to depart but he stops and waves at you..";
	shore.dialogue1 = "You are now at the shore after fighting that weird monster, You look beneath youand find an item in the sand";
	town.dialogue1 = "You have arrived at the Local Town with the help of the Boat-Man";
	town.dialogue2 = "The Town seems quiet big for it to be called a 'Town'";
	town.dialogue3 = "A masked lady approaches you and hands you a necklace as she whispers";
	town.dialogue4 = "???: Arrive by nine tonight..";
	town.dialogue5 = "That approach seemed frightening, although you now come across a colluseum..";
	colosseum.dialogue1 = "You arrive at the colluseum, Choose what you would like to do..";
	darkPortal.dialogue1 = "???: You're here, then let us go..My name is Rose";
	darkPortal.dialogue2 = "You have entered the Dark portal, Monsters await..";
	darkShore.dialogue1 = "???: You have arrived...";
	darkShore.dialogue2 = "???: I did not expect you so soon...";
	darkShore.dialogue3 = "???: Welcome to my realm, enjoy your stay..Eternally that is..";
	darkShore.dialogue4 = "You find yourself in the shore, although something seems off, everything is dark and it seems like it is night-time..";
	darkShore.dialogue5 = "You seem not to be able to see your reflection in the water...";
	darkShore.dialogue6 = "???: Well, You are dead, what did you expect..?";
	castleOfFire.dialogue1 = "???: WHO DARES ENTER MY CASTLE?";
	castleOfFire.dialogue2 = "Rose: I didn't expect the Dark Knight would be already here! Be careful traveler!";
	castleOfFire.dialogue3 = "Dark Knight: Fighter of the Light... I will show you why entering my castle was a terrible idea...";
	beach.dialogue1 = "Rose: Good Job Traveler, looks like we will live another day";
	beach.dialogue2 = "Rose: Perhaps you would like to join our guild, It is not near town, we tend to travel a lot just like you";
	beach.dialogue3 = "Rose: I'll give you lots of time to think about it...";
	beach.dialogue4 = "It looks like you managed to defeat the Dark Knight and make a friend along the way";
	beach.dialogue5 = "Although you still do not know of your past, following Rose and joining the guild may be beneficial..";
	beach.dialogue6 = "The end...";
	beach.dialogue7 = "You have reached the end of the game, thanks a lot for playing!";

	dialogue.insert(std::pair<std::string, Area>("GameStart", gameStart));
	dialogue.insert(std::pair<std::string, Area>("Beginning", beginning));
	dialogue.insert(std::pair<std::string, Area>("Forest", forest));
	dialogue.insert(std::pair<std::string, Area>("Woods", woods));
	dialogue.insert(std::pair<std::string, Area>("Port", port));
	dialogue.insert(std::pair<std::string, Area>("Shore", shore));
	dialogue.insert(std::pair<std::string, Area>("Town", town));
	dialogue.insert(std::pair<std::string, Area>("Colosseum", colosseum));
	dialogue.insert(std::pair<std::string, Area>("DarkPortal", darkPortal));
	dialogue.insert(std::pair<std::string, Area>("CastleOfFire", castleOfFire));
	dialogue.insert(std::pair<std::string, Area>("DarkShore", darkShore));
	dialogue.insert(std::pair<std::string, Area>("Beach", beach));
}

void MapSys::DialogueSys()
{
	switch (GetMapLoc())
	{
	case (Map::GameStart):
	{
		auto i = dialogue.find("GameStart");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	}
	case (Map::Beginning):
	{
		auto i = dialogue.find("Beginning");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		ChoiceSys();
	}
	case (Map::Forest):
	{
		auto i = dialogue.find("Forest");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	}
	case (Map::Woods):
	{
		auto i = dialogue.find("Woods");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		//TODO:Big bear Fight here
		//TODO:Make him have High def and low HP but higher Attack than slime
		//std::cout << "Your strength has increased!" << std::endl;
		break;
	}
	case (Map::Port):
	{
		auto i = dialogue.find("Port");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		ChoiceSys();
		break;
	}
	case (Map::Shore):
	{
		auto i = dialogue.find("Shore");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		break;
	}
	case (Map::Town):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("Town");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue4 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue5 << std::endl;
				SpeechPause();
			}
		}
		break;
	}
	case (Map::Colosseum):
	{
		auto i = dialogue.find("Colosseum");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
		}
		ChoiceSys();
	}
	case (Map::DarkPortal):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("DarkPortal");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
				SpeechPause();
			}
		}
		break;
	}
	case (Map::CastleOfFire):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("CastleOfFire");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
			}
		}
		break;
	}
	case (Map::DarkShore):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("DarkShore");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue4 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue5 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue6 << std::endl;
				SpeechPause();
			}
		}

		break;
	}
	case (Map::Beach):
	{
		for (const auto& i : dialogue)
		{
			auto it = i.first.find("Beach");
			if (it != std::string::npos)
			{
				//If label is there iterate through text
				std::cout << i.second.dialogue1 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue2 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue3 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue4 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue5 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue6 << std::endl;
				SpeechPause();
				std::cout << i.second.dialogue7 << std::endl;
				SpeechPause();
			}
		}
		break;
	}
	default:
	{
		std::cout << "DialogueSystem Malfunction: Beyond Range" << std::endl;
		break;
	}
	}
}

void MapSys::LocController()
{
	while (!m_roomDone)
	{
		switch (GetMapLoc())
		{
		case Map::GameStart:
		{
			std::cout << "GameStart" << std::endl;
			SpeechPause();
			DialogueSys();
			m_player->SetCharacterClass();
			SetMapLoc(Map::Beginning);
			break;
		}
		case Map::Beginning:
		{
			std::cout << "Beginning" << std::endl;
			DialogueSys();
			break;
		}
		case Map::Forest:
		{
			std::cout << "Forest" << std::endl;
			SpeechPause();
			DialogueSys();
			MonsterFight();
			SpeechPause();
			SetMapLoc(Map::Port);
			//TODO:Make the slime have high HP and low attack, def should be medium
			break;
		}
		case Map::Woods:
		{
			MonsterFight();
			std::cout << "Woods" << std::endl;
			SpeechPause();
			DialogueSys();
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			MonsterFight();
			std::cout << "Port" << std::endl;
			SpeechPause();
			DialogueSys();
			ChoiceSys();
			SetMapLoc(Map::Town);
			break;
		}
		case Map::Shore:
		{
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			std::cout << "Shore" << std::endl;
			SpeechPause();
			DialogueSys();
			SetMapLoc(Map::DarkPortal);
			break;
		}
		case Map::Town:
		{
			std::cout << "Town" << std::endl;
			SpeechPause();
			DialogueSys();
			ChoiceSys();
			break;
		}
		case Map::Colosseum:
		{
			std::cout << "Colusseum" << std::endl;
			SpeechPause();
			break;
		}
		case Map::DarkPortal:
		{
			std::cout << "DarkPortal" << std::endl;
			SpeechPause();
			DialogueSys();
			SetMapLoc(Map::CastleOfFire);
			break;
		}
		case Map::CastleOfFire:
			std::cout << "CastleOfFire" << std::endl;
			SpeechPause();
			DialogueSys();
			//bossfight here
			break;//BOSS
		case Map::DarkShore:
			std::cout << "Dark Shore" << std::endl;
			SpeechPause();
			DialogueSys();
			break;//Bad ending
		case Map::Beach:
			std::cout << "Beach" << std::endl;
			SpeechPause();
			DialogueSys();
			break;//Good ending
		default:
			std::cout << "Location Cotroller malfunction" << std::endl;
			break;
		}
	}
}
void MapSys::MonsterFight()
{
	//GetMapLoc();
	int combatOptions;
	bool runAway = false;
	std::cout << "In the forest, you are confronted by" << std::endl;
	m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Rat");
	m_monster->MonsterInfo();
	m_player->PlayerInfo();
	//std::cout << m_monster->MonsterIsAlive() << std::endl;
	//std::cout << runAway << std::endl;
	while (m_monster->MonsterIsAlive() && runAway == false)
	{
		std::cout << "Select an option:" << std::endl;
		std::cout << "1: Attack" << std::endl;
		std::cout << "2: Run" << std::endl;
		std::cin >> combatOptions;
		switch (combatOptions)
		{
		case 1:
			//m_player->GetDamage();
			m_monster->MonsterReceiveDamage(m_player->GetDamage());
			m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage());
			m_monster->MonsterInfo();
			m_player->PlayerInfo();
			break;
		case 2:
			m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage());
			m_player->PlayerInfo();
			std::cout << "You just book it" << std::endl;
			runAway = true;
			m_monster->~MonsterSys();
			break;
		default:
			break;
		}
	}
	m_monster->~MonsterSys(); //-- delete monster after monster die.
	//m_player->ReceiveDamage(m_monster->GetMonsterDamage()) -- Deal damage to Player.
	//m_monster->MonsterReceiveDamage(m_player->GetDamage()); --Deal damage to monster according to player damage.
	//m_monster->MonsterIsAlive(); --return if monster is dead or not.
}

void MapSys::SetMapLoc(Map NewLoc)
{
	m_locations = NewLoc;
}

void MapSys::SpeechPause() const
{
	system("pause");
	system("cls");
}
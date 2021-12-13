#include "MapSys.h"
//Section fully Programmed by Stefanos
//Last edited 12/12/21

MapSys::MapSys()
{
	//Map
	m_choice = 0;
	m_choiceMade = false;
	m_getLocation = 0;
	m_locations = Map::GameStart;
	m_lastLocation = Map::GameStart;
	m_roomDone = false;
	m_setLocation = 0;
	
	//Monster
	m_monster = new MonsterSys();

	//Player
	m_player = new CharacterSys();
	m_player->CreateCharacter();
	m_player->PlayerInfo();

	//Dialogue
	CreateDialog();

	SpeechPause();
	
}
MapSys::~MapSys() 
{
}
MapSys::Map MapSys::GetMapLoc() const
{
	return m_locations;
}
void MapSys::ChoiceSys(Map& m_locations)
{
	switch (m_locations)
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
				m_choiceMade = true;
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
				m_choiceMade = true;
				break;
			}
			case 2:
			{
				std::cout << "You attack the Boat owner" << std::endl;
				SpeechPause();
				//fight here then go to town
				SetMapLoc(Map::Town);
				LocController();
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
	case (Map::Beach):
	{
		break;
		m_choiceMade = true;
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
void MapSys::DialogueSys(Map& m_locations)
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
		ChoiceSys(m_locations);
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
		ChoiceSys(m_locations);
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
		ChoiceSys(m_locations);
	}
	case (Map::DarkPortal):
	{

		auto i = dialogue.find("DarkPortal");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue2 << std::endl;
			SpeechPause();
		}
		break;
	}
	case (Map::CastleOfFire):
	{

		auto i = dialogue.find("CastleOfFire");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue2 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue3 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue4 << std::endl;
			SpeechPause();
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
		auto i = dialogue.find("Beach");
		if (i != dialogue.end())
		{
			std::cout << i->second.dialogue1 << std::endl;
			SpeechPause();
			std::cout << i->second.dialogue2 << std::endl;
			SpeechPause();
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
	auto w = dialogue;
	while (!m_roomDone)
	{
		switch (m_locations)
		{
		case Map::GameStart:
		{
			system("cls");
			std::cout << "Player location: GameStart\n" << std::endl;
			DialogueSys(m_locations);
			//DialogueSys(GetMapLoc()); Function return m_locations, but it's non-const
			m_player->SetCharacterClass();
			SetMapLoc(Map::Beginning);
			SpeechPause();
			break;
		}
		case Map::Beginning:
		{
			std::cout << "Player location: Beginning\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Ratta");
			MonsterFight();
			DialogueSys(m_locations);
			SpeechPause();
			break;
		}
		case Map::Forest:
		{
			system("cls");
			std::cout << "Player location: Forest\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Slime");
			DialogueSys(m_locations);
			SpeechPause();
			MonsterFight();
			SetMapLoc(Map::Port);
			break;
		}
		case Map::Woods:
		{
			system("cls");
			std::cout << "Player location: Woods\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Aracno");
			MonsterFight();
			DialogueSys(m_locations);
			SetMapLoc(Map::Shore);
			break;
		}
		case Map::Port:
		{
			SpeechPause();
			std::cout << "Player location: Port\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Nudibranch");
			MonsterFight();
			DialogueSys(m_locations);
			ChoiceSys(m_locations);
			SetMapLoc(Map::Town);
			break;
		}
		case Map::Shore:
		{
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "RedPuan");
			//add here dialogue that shows the item being in inventory
			//Same Item as in Town Route for Shield and Magician
			std::cout << "Player location: Shore\n" << std::endl;
			MonsterFight();
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::DarkPortal);
			break;
		}
		case Map::Town:
		{
			std::cout << "Player location: Town\n" << std::endl;
			SpeechPause();
			DialogueSys(m_locations);
			ChoiceSys(m_locations);

			break;
		}
		case Map::Colosseum:
		{
			std::cout << "Player location: Colusseum\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Slaughter");
			MonsterFight();
			SpeechPause();
			break;
		}
		case Map::DarkPortal:
		{
			std::cout << "Player location: DarkPortal\n" << std::endl;
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "Flatworm");
			MonsterFight();
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::CastleOfFire);
			break;
		}
		case Map::CastleOfFire:
			m_monster->CreateMonster(static_cast<int>(GetMapLoc()), "BOSS: FireElemental");
			std::cout << "Player location: CastleOfFire\n" << std::endl;
			MonsterFight();
			SpeechPause();
			DialogueSys(m_locations);
			SetMapLoc(Map::Beach);
			break;//BOSS
		case Map::DarkShore:
			std::cout << "Dark Shore" << std::endl;
			MonsterFight();
			SpeechPause();
			DialogueSys(m_locations);
			break;//Bad ending
		case Map::Beach:
			std::cout << "Player location: Beach\n" << std::endl;
			DialogueSys(m_locations);
			SpeechPause();
			SetMapLoc(Map::Win);
			break;//Good ending
		case Map::Win:
			std::cout << "WINNER WINNER CHICKEN DINNER!!\n" << std::endl;
			SpeechPause();
			m_roomDone = true;
			break;//Good ending
		default:
			std::cout << "Player location: Location Cotroller malfunction\n" << std::endl;
			break;
		}
	}
}
void MapSys::MonsterFight()
{
	//GetMapLoc();
	int combatOptions;
	bool runAway = false;

	std::cout << "You are confronted by " << m_monster->GetMonsterName() << std::endl;

	//std::cout << m_monster->MonsterIsAlive() << std::endl;
	//std::cout << runAway << std::endl;

	while (m_monster->MonsterIsAlive() && runAway == false && m_player->IsAlive())
	{
		m_monster->MonsterInfo();

		std::cout << "Select an option:" << std::endl;
		std::cout << "1: Attack" << std::endl;
		std::cout << "2: Run" << std::endl;
		std::cout << "3: Player Stats" << std::endl;
		std::cin >> combatOptions;
		switch (combatOptions)
		{
		case 1:
			//m_player->GetDamage();
			m_monster->MonsterReceiveDamage(m_player->GetDamage());
			if(m_monster->MonsterIsAlive())
			{
				m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage(), runAway);
			}
			//m_player->PlayerInfo();
			break;
		case 2:
			runAway = true;
			m_player->PlayerReceiveDamage(m_monster->GetMonsterDamage(), runAway);
			//m_player->PlayerInfo();
			std::cout << "You just book it" << std::endl;
			SetMapLoc(m_lastLocation);
			m_monster->~MonsterSys();
			break;
		case 3:
			system("cls");
			m_player->PlayerInfo();
			SpeechPause();
			break;
		default:
			std::cout << "Unespected case in fight." << std::endl;
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
	m_lastLocation = m_locations;
	m_locations = NewLoc;
}
void MapSys::SpeechPause() const
{
	system("pause");
	system("cls");
}
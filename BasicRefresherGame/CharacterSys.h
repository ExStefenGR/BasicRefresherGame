#pragma once
#include <string>
#include <iostream>

class CharacterSys
{
	public:
		CharacterSys();
		~CharacterSys();

		std::string getName();

		void setDamage(int damagePoints);
		int getDamage();
		void setHealthPoints(int healthPoints);
		int getHealthPoints();
		void setManaPoints(int manaPoints);
		int getManaPoints();

		std::string m_name;
		int m_damagePoints;
		int m_healthPoints;
		int m_manaPoints;
};


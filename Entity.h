#pragma once
#include <iostream>

struct Entity {
	int health;
	int teamNumber;

	Entity(int health, int teamNumber) 
		: health{ health }, teamNumber{ teamNumber } {

		std::cout << "Entity custom constructor" << std::endl;
	}

	Entity(const Entity& ent)
		: health{ ent.health }, teamNumber{ ent.teamNumber } {

		std::cout << "Entity copy constructor" << std::endl;
	}

};

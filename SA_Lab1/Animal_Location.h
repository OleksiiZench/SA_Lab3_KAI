#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
class Animal_Location
{
public:
	virtual std::string Get_Animal_Location() = 0;

	void Add_Animal(Animal *animal);
	void Release_Animal(Animal *animal);
	void Feed_Animal(Animal *animal);
	void Clean_Animal(Animal *animal);
	std::vector<Animal*> Get_Animals();

private:
	std::vector<Animal*> Animals;
};
//------------------------------------------------------------------------------------------------------------

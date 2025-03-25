#pragma once

#include <conio.h>
#include <cstdlib>
#include <iostream>

#include "Canary.h"
#include "Dog.h"
#include "Emulator.h"
#include "Lizard.h"

//------------------------------------------------------------------------------------------------------------
class Console_Menu
{
public:
	Console_Menu(Emulator *emulator, Owner *owner, Pet_Store *pet_store);

	void Start_Menu();

private:
	void Creating_Animal_Menu();
	void Dog_Creation_Menu();
	void Canary_Creation_Menu();
	void Lizard_Creation_Menu();

	Emulator *Emulator_Manager = nullptr;
	Owner *Owner_Location = nullptr;
	Pet_Store *Pet_Store_Location = nullptr;
};
//------------------------------------------------------------------------------------------------------------

#pragma once

#include <conio.h>
#include <string>
#include <vector>

#include "Animal.h"
#include "Animal_Observer.h"
#include "Canary.h"
#include "Dog.h"
#include "Lizard.h"
#include "Owner.h";
#include "Pet_Store.h"
#include "Thread_Manager.h"

//------------------------------------------------------------------------------------------------------------
class Emulator
{
public:
	Emulator(Thread_Manager *thread_manager, Owner *owner_location, Pet_Store *pet_store_location);

	void Start_Emulator();
	void Add_Free_Animal(Animal *animal);

private:
	void Show_Animal_Info(Animal *animal);
	void Animal_Management();
	void Dog_Management(char choice);
	void Canary_Management(char choice);
	void Lizard_Management(char choice);
	void Stop_Emulator();

	bool Exit_Program = false;
	int Increment = 0;
	std::string Label = "";
	std::vector<Animal*> Free_Animals;
	std::vector<Animal*> All_Animals;
	Dog *Dog_Temp = nullptr;
	Canary *Canary_Temp = nullptr;
	Lizard *Lizard_Temp = nullptr;
	Owner *Owner_Location = nullptr;
	Pet_Store *Pet_Store_Location = nullptr;
	Animal_Location *Current_Animal_Location = nullptr;
	Thread_Manager *Emulator_Thread_Manager = nullptr;
	Animal_Observer *Observer = nullptr;
};
//------------------------------------------------------------------------------------------------------------

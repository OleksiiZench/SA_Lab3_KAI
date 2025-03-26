#include "Emulator.h"

//------------------------------------------------------------------------------------------------------------
Emulator::Emulator(Thread_Manager *thread_manager, Owner *owner_location, Pet_Store *pet_store_location)
{
	Emulator_Thread_Manager = thread_manager;
	Owner_Location = owner_location;
	Pet_Store_Location = pet_store_location;
	Observer = new Animal_Observer;
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Start_Emulator()
{
	int check = 0;
	int counter = 0;

	for (Animal *animal : Owner_Location->Get_Animals() )
		animal->Attach(Observer);

	for (Animal *animal : Pet_Store_Location->Get_Animals() )
		animal->Attach(Observer);

	for (Animal *animal : Free_Animals)
		animal->Attach(Observer);

	Emulator_Thread_Manager->Start_Increment_Time();
	Emulator_Thread_Manager->Start_Animal_Management(std::bind(&Emulator::Animal_Management, this), this);

	while (true)
	{
		system("cls");
		std::cout << "Time Since Start: " << Emulator_Thread_Manager->Get_Time_Since_Start() << std::endl << std::endl;

		if (check < Emulator_Thread_Manager->Get_Time_Since_Start() )
		{// Для додавання часу до тварин з момету їжі
			check++;
			Increment = 1;
		}
		else 
			Increment = 0;

		std::cout << "Owner: \n";
		for (Animal *animal : Owner_Location->Get_Animals() )
		{
			if (Label == animal->Get_Name() )
			{
				std::cout << "-";
				Current_Animal_Location = Owner_Location;
			}

			if ((Emulator_Thread_Manager->Get_Time_Since_Start() > 0) && (Emulator_Thread_Manager->Get_Time_Since_Start() % 24) == 0)  // Коли пройшла доба скидуємо Meal_Per_Day та Is_Clean для тварин які живуть в хазяїна
			{
				animal->Meal_Per_Day = 0;
				animal->Is_Clean = 0;
			}

			animal->Time_Since_Last_Meal += Increment; // Додаємо час до від останнього прийому їжі, бо тварина не на волі

			All_Animals.push_back(animal);
			Show_Animal_Info(animal);
		}

		std::cout << "\nPet_Store: \n";
		for (Animal *animal : Pet_Store_Location->Get_Animals() )
		{
			if (Label == animal->Get_Name() )
			{
				std::cout << "-";
				Current_Animal_Location = Pet_Store_Location;
			}

			if ((Emulator_Thread_Manager->Get_Time_Since_Start() > 0) && (Emulator_Thread_Manager->Get_Time_Since_Start() % 24) == 0)  // Коли пройшла доба скидуємо Meal_Per_Day та Is_Clean для тварин які живуть в зоомагазині
			{
				animal->Meal_Per_Day = 0;
				animal->Is_Clean = 0;
			}

			animal->Time_Since_Last_Meal += Increment; // Додаємо час до від останнього прийому їжі, бо тварина не на волі

			All_Animals.push_back(animal);
			Show_Animal_Info(animal);
		}

		std::cout << "\nFree: \n";
		for (Animal *animal : Free_Animals)
		{
			if (Label == animal->Get_Name() )
			{
				std::cout << "-";
				Current_Animal_Location = nullptr;
			}
			
			if ((Emulator_Thread_Manager->Get_Time_Since_Start() % 24) == 0)  // Тварини чисті та нагодовані, бо живуть на вулиці (оновлюється кожну добу)
			{
				animal->Is_Clean = 0;
				animal->To_Clean();

				animal->Meal_Per_Day = 0;
				animal->To_Eat();
			}

			All_Animals.push_back(animal);
			Show_Animal_Info(animal);
		}

		if (Exit_Program)
		{
			system("cls");
			std::cout << "Stopping the emulator and exiting the program...\n";
			std::this_thread::sleep_for(std::chrono::seconds(3) );
			return;
		}

		std::this_thread::sleep_for(std::chrono::seconds(3) );
	}
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Show_Animal_Info(Animal *animal)
{
	if ((Dog_Temp = dynamic_cast<Dog *>(animal) ) != nullptr)
	{
		std::cout << "Dog: " << Dog_Temp->Get_Name()
			<< ", Is Running: " << Dog_Temp->Get_Is_Running();
	}
	else if((Canary_Temp = dynamic_cast<Canary*>(animal) ) != nullptr )
	{
		std::cout << "Canary: " << Canary_Temp->Get_Name()
			<< ", Is Singing: " << Canary_Temp->Get_Is_Singing()
			<< ", Is Flying: " << Canary_Temp->Get_Is_Flying();
	}
	else if((Lizard_Temp = dynamic_cast<Lizard*>(animal) ) != nullptr )
	{
		std::cout << "Lizard: " << Lizard_Temp->Get_Name()
			<< ", Is Crawling: " << Lizard_Temp->Get_Is_Crawling();
	}

	std::cout << ", Is Alive: " << animal->Get_Is_Alive()
		<< ", Is Happy: " << animal->Get_Is_Happy()
		<< ", Is Walking: " << animal->Get_Is_Walking()
		<< ", Is Clean: " << animal->Get_Is_Clean()
		<< ", Meal Per Day: " << animal->Get_Meal_Per_Day()
		<< ", Time Since Last Meal: " << animal->Get_Time_Since_Last_Meal()
		<< std::endl;
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Animal_Management()
{
	int count_label = 0;
	char choice = -1;

	while (true)
	{
		if (!(choice == 'w' || choice == 's') )
			choice = _getch();

		switch (choice)
		{
		case 'w':
		{
			if (count_label > 0)
				count_label--;
		}
		break;

		case 's':
			count_label++;
			break;

		case 'q':
			Stop_Emulator();
			return;
			
		default:
			continue;
		}

		if (All_Animals[count_label] != nullptr)
			Label = All_Animals[count_label]->Get_Name();

		choice = _getch();
		if (choice == 'w' || choice == 's')
			continue;
		else if (choice == '9' && Current_Animal_Location != nullptr)
		{
			if (Current_Animal_Location->Get_Animal_Location() == "Owner")
				Owner_Location->Release_Animal(All_Animals[count_label]);
			else if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
				Pet_Store_Location->Release_Animal(All_Animals[count_label]);

			Add_Free_Animal(All_Animals[count_label]);
		}

		if ((Dog_Temp = dynamic_cast<Dog *>(All_Animals[count_label]) ) != nullptr)
		{
			Dog_Management(choice);
		}
		else if ((Canary_Temp = dynamic_cast<Canary*>(All_Animals[count_label]) ) != nullptr )
		{
			Canary_Management(choice);
		}
		else if ((Lizard_Temp = dynamic_cast<Lizard*>(All_Animals[count_label]) ) != nullptr )
		{
			Lizard_Management(choice);
		}
	}
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Dog_Management(char choice)
{
	switch (choice)
	{
	case '1':
		Dog_Temp->To_Run();
		break;

	case '2':
		Dog_Temp->To_Walk();
		break;

	case '3':
		{
		if (Current_Animal_Location == nullptr)
			break;

		if (Current_Animal_Location->Get_Animal_Location() == "Owner")
			Owner_Location->Clean_Animal(Dog_Temp);

		if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
			Pet_Store_Location->Clean_Animal(Dog_Temp);
		}
		break;
	case '4':
		{
			if (Current_Animal_Location == nullptr)
				break;

			if (Current_Animal_Location->Get_Animal_Location() == "Owner")
				Owner_Location->Feed_Animal(Dog_Temp);

			if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
				Pet_Store_Location->Feed_Animal(Dog_Temp);
		}
		break;
	}
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Canary_Management(char choice)
{
	switch (choice)
	{
	case '1':
		Canary_Temp->To_Sing();
		break;

	case '2':
		Canary_Temp->To_Fly();
		break;

	case '3':
		Canary_Temp->To_Walk();
		break;

	case '4':
		{
		if (Current_Animal_Location == nullptr)
			break;

		if (Current_Animal_Location->Get_Animal_Location() == "Owner")
			Owner_Location->Clean_Animal(Canary_Temp);

		if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
			Pet_Store_Location->Clean_Animal(Canary_Temp);
	}
		break;
	case '5':
		{
		if (Current_Animal_Location == nullptr)
			break;

		if (Current_Animal_Location->Get_Animal_Location() == "Owner")
			Owner_Location->Feed_Animal(Canary_Temp);

		if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
			Pet_Store_Location->Feed_Animal(Canary_Temp);
	}
		break;
	}
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Lizard_Management(char choice)
{
	switch (choice)
	{
	case '1':
		Lizard_Temp->To_Crawl();
		break;

	case '2':
		Lizard_Temp->To_Walk();
		break;

	case '3':
		{
		if (Current_Animal_Location == nullptr)
			break;

		if (Current_Animal_Location->Get_Animal_Location() == "Owner")
			Owner_Location->Clean_Animal(Lizard_Temp);

		if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
			Pet_Store_Location->Clean_Animal(Lizard_Temp);
	}
		break;
	case '4':
		{
		if (Current_Animal_Location == nullptr)
			break;

		if (Current_Animal_Location->Get_Animal_Location() == "Owner")
			Owner_Location->Feed_Animal(Lizard_Temp);

		if (Current_Animal_Location->Get_Animal_Location() == "Pet_Store")
			Pet_Store_Location->Feed_Animal(Lizard_Temp);
	}
		break;
	}
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Add_Free_Animal(Animal *animal)
{
	Free_Animals.push_back(animal);
}
//------------------------------------------------------------------------------------------------------------
void Emulator::Stop_Emulator()
{
	Emulator_Thread_Manager->Stop_Animal_Management();
	Emulator_Thread_Manager->Stop_Increment_Time();
	Exit_Program = true;
}
//------------------------------------------------------------------------------------------------------------

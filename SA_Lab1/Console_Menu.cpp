#include "Console_Menu.h"

//------------------------------------------------------------------------------------------------------------
Console_Menu::Console_Menu(Emulator *emulator, Owner *owner, Pet_Store *pet_store)
{
	Emulator_Manager = emulator;
	Owner_Location = owner;
	Pet_Store_Location = pet_store;
}
//------------------------------------------------------------------------------------------------------------
void Console_Menu::Start_Menu()
{
	system("cls");
	std::cout << "Before running the emulator, create animals\n\n";
	std::cout << "Press enter to continue...\n";
	std::cin.get();

	Creating_Animal_Menu();

	system("cls");
	std::cout << "You have created animals, now the emulator will be launched.\n\n";
	std::cout << "Press enter to continue...\n";
	std::cin.get();

	Emulator_Manager->Start_Emulator();
}
//------------------------------------------------------------------------------------------------------------
void Console_Menu::Creating_Animal_Menu()
{
	char first_choice;
	char second_choice;

	while (true)
	{
		system("cls");
		std::cout << "1. Create a dog\n";
		std::cout << "2. Create a canary\n";
		std::cout << "3. Create a lizard\n";

		first_choice = _getch();

		switch (first_choice)
		{
		case '1':
			Dog_Creation_Menu();
			break;

		case '2':
			Canary_Creation_Menu();
			break;

		case '3':
			Lizard_Creation_Menu();
			break;

		default:
			continue;
		}

		system("cls");
		std::cout << "Would you like to create another animal?\n";
		std::cout << "1. Yes\n";
		std::cout << "0. No\n";

		second_choice = _getch();

		if (second_choice == '0')
			return;
		else
			continue;
	}
}
//------------------------------------------------------------------------------------------------------------
void Console_Menu::Dog_Creation_Menu()
{
	char choice;
	char name[20];
	Dog *dog = nullptr;

	system("cls");
	std::cout << "Enter a dog's name (max 20 char): ";
	std::cin >> name;

	dog = new Dog(name);

	while (true)
	{
		system("cls");
		std::cout << "Where will the animal live?\n"
			<< "1. With the owner.\n"
			<< "2. In a pet store.\n"
			<< "3. In the wild.\n";

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			Owner_Location->Add_Animal(dog);

			system("cls");
			std::cout << dog->Get_Name() << " lives with his owner\n\n"
												  << "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '2':
		{
			Pet_Store_Location->Add_Animal(dog);

			system("cls");
			std::cout << dog->Get_Name() << " lives in a pet store\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '3':
		{
			Emulator_Manager->Add_Free_Animal(dog);

			system("cls");
			std::cout << dog->Get_Name() << " is free\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		default:
			continue;
		}
	}
}
//------------------------------------------------------------------------------------------------------------
void Console_Menu::Canary_Creation_Menu()
{
	char choice;
	char name[20];
	Canary *canary = nullptr;

	system("cls");
	std::cout << "Enter the name of the canary (max 20 char): ";
	std::cin >> name;

	canary = new Canary(name);

	while (true)
	{
		system("cls");
		std::cout << "Where will the animal live?\n"
			<< "1. With the owner.\n"
			<< "2. In a pet store.\n"
			<< "3. In the wild.\n";

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			Owner_Location->Add_Animal(canary);

			system("cls");
			std::cout << canary->Get_Name() << " lives with his owner\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '2':
		{
			Pet_Store_Location->Add_Animal(canary);

			system("cls");
			std::cout << canary->Get_Name() << " lives in a pet store\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '3':
		{
			Emulator_Manager->Add_Free_Animal(canary);

			system("cls");
			std::cout << canary->Get_Name() << " is free\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		default:
			continue;
		}
	}
}
//------------------------------------------------------------------------------------------------------------
void Console_Menu::Lizard_Creation_Menu()
{
	char choice;
	char name[20];
	Lizard *lizard = nullptr;

	system("cls");
	std::cout << "Enter the name of the lizard (max 20 char): ";
	std::cin >> name;

	lizard = new Lizard(name);

	while (true)
	{
		system("cls");
		std::cout << "Where will the animal live?\n"
			<< "1. With the owner.\n"
			<< "2. In a pet store.\n"
			<< "3. In the wild.\n";

		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			Owner_Location->Add_Animal(lizard);

			system("cls");
			std::cout << lizard->Get_Name() << " lives with his owner\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '2':
		{
			Pet_Store_Location->Add_Animal(lizard);

			system("cls");
			std::cout << lizard->Get_Name() << " lives in a pet store\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		case '3':
		{
			Emulator_Manager->Add_Free_Animal(lizard);

			system("cls");
			std::cout << lizard->Get_Name() << " is free\n\n"
				<< "Press enter to continue...\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		return;

		default:
			continue;
		}
	}
}
//------------------------------------------------------------------------------------------------------------

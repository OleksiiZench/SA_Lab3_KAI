#include "Console_Menu.h"

//------------------------------------------------------------------------------------------------------------
int main()
{
	Thread_Manager *thread_manager = new Thread_Manager();

	Owner *owner = new Owner();
	Pet_Store *pet_store = new Pet_Store();

	Emulator *emulator = new Emulator(thread_manager, owner, pet_store); 

	Console_Menu *console_menu = new Console_Menu(emulator, owner, pet_store);

	console_menu->Start_Menu();

	delete console_menu;
	delete emulator;
	delete thread_manager;
	delete owner;
	delete pet_store;

	return 0;
}
//------------------------------------------------------------------------------------------------------------

#include "Thread_Manager.h"

//------------------------------------------------------------------------------------------------------------
Thread_Manager::Thread_Manager() : Stop_Flag_Increment(false), Stop_Flag_Animal(false)
{
}
//------------------------------------------------------------------------------------------------------------
Thread_Manager::~Thread_Manager()
{
	Stop_Increment_Time();
}
//------------------------------------------------------------------------------------------------------------
void Thread_Manager::Start_Increment_Time()
{
	Stop_Flag_Increment = false;
	Increment_Thread = std::thread(&Thread_Manager::Increment_Time_Since_Start, this);
	Increment_Thread.detach();
}
//------------------------------------------------------------------------------------------------------------
void Thread_Manager::Stop_Increment_Time()
{
	Stop_Flag_Increment = true;
}
//------------------------------------------------------------------------------------------------------------
void Thread_Manager::Start_Animal_Management(std::function<void()> animal_manager, Emulator *ptr_emul)
{
	Stop_Flag_Animal = false;
	Animal_Thread = std::thread(animal_manager);
	Animal_Thread.detach();
}
//------------------------------------------------------------------------------------------------------------
void Thread_Manager::Stop_Animal_Management()
{
	Stop_Flag_Animal = true;
}
//------------------------------------------------------------------------------------------------------------
void Thread_Manager::Increment_Time_Since_Start()
{
	while (!Stop_Flag_Increment)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3) );
		Time_Since_Start++;
	}
}
//------------------------------------------------------------------------------------------------------------
int Thread_Manager::Get_Time_Since_Start()
{
	return static_cast<int>(Time_Since_Start);
}
//------------------------------------------------------------------------------------------------------------

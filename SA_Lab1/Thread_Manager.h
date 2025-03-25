#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

class Emulator;

//------------------------------------------------------------------------------------------------------------
class Thread_Manager
{
public:
	Thread_Manager();

	~Thread_Manager();

	void Start_Increment_Time();
	void Stop_Increment_Time();
	void Start_Animal_Management(std::function<void()> animal_manager, Emulator *ptr_emul);
	void Stop_Animal_Management();
	int Get_Time_Since_Start();

private:
	void Increment_Time_Since_Start();

	bool Stop_Flag_Increment;
	bool Stop_Flag_Animal;
	std::atomic<int> Time_Since_Start = 0;
	std::thread Increment_Thread;
	std::thread Animal_Thread;
};
//------------------------------------------------------------------------------------------------------------

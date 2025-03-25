#pragma once

#include <functional>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------------------------------------
class Event_Manager
{
public:
	void Add_Listener(std::function<void()> callback);
	void Trigger_Event();

private:
	std::vector<std::function<void()>> Listeners;
};
//------------------------------------------------------------------------------------------------------------

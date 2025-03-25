#include "Dog.h"

//------------------------------------------------------------------------------------------------------------
Dog::Dog(std::string name) : Animal(name)
{
	Eyes = 2;
	Paws = 4;
}
//------------------------------------------------------------------------------------------------------------
Dog::~Dog()
{
}
//------------------------------------------------------------------------------------------------------------
void Dog::To_Walk()
{
	if (Is_Alive == false)
	{
		Is_Walking = false;
		return;
	}

	if (Is_Walking == false)
	{
		if (Is_Running == true)
			Is_Running = false;

		Is_Walking = true;
		return;
	}
	else
	{
		Is_Walking = false;
		return;
	}
}
//------------------------------------------------------------------------------------------------------------
void Dog::To_Run()
{
	if (Is_Alive == false)
	{
		Is_Running = false;
		return;
	}

	if (Is_Running == false && Time_Since_Last_Meal < 8)
	{
		if (Is_Walking == true)
			Is_Walking = false;

		Is_Running = true;
		return;
	}
	else
	{
		Is_Running = false;
		return;
	}
}
//------------------------------------------------------------------------------------------------------------
bool Dog::Get_Is_Running()
{
	if (Is_Alive == false)
	{
		Is_Running = false;
		return Is_Running;
	}

	if (Time_Since_Last_Meal > 8 || Meal_Per_Day <= 0)
	{
		Is_Running = false;
	}

	return Is_Running;
}
//------------------------------------------------------------------------------------------------------------

#include "Canary.h"

//------------------------------------------------------------------------------------------------------------
Canary::Canary(std::string name) : Animal(name)
{
	Eyes = 2;
	Paws = 2;
	Has_Wings = true;
}
//------------------------------------------------------------------------------------------------------------
Canary::~Canary()
{
}
//------------------------------------------------------------------------------------------------------------
void Canary::To_Walk()
{
	if (Is_Alive == false)
	{
		Is_Walking = false;
		return;
	}

	if (Is_Walking == false)
	{
		if (Is_Flying == true)
			Is_Flying = false;

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
void Canary::To_Sing()
{
	if (Is_Alive == false)
	{
		Is_Singing = false;
		return;
	}

	if (Is_Singing == false && Time_Since_Last_Meal < 8)
	{
		Is_Singing = true;
		return;
	}
	else
	{
		Is_Singing = false;
		return;
	}
}
//------------------------------------------------------------------------------------------------------------
void Canary::To_Fly()
{
	if (Is_Alive == false)
	{
		Is_Flying = false;
		return;
	}

	if (Is_Flying == false && Time_Since_Last_Meal < 8)
	{
		if (Is_Walking == true)
			Is_Walking = false;

		Is_Flying = true;
		return;
	}
	else
	{
		Is_Flying = false;
		return;
	}
}
//------------------------------------------------------------------------------------------------------------
bool Canary::Get_Is_Singing()
{
	if (Is_Alive == false)
	{
		Is_Singing = false;
		return Is_Singing;
	}

	if (Time_Since_Last_Meal > 8 || Meal_Per_Day <= 0)
	{
		Is_Singing = false;
	}

	return Is_Singing;
}
//------------------------------------------------------------------------------------------------------------
bool Canary::Get_Is_Flying()
{
	if (Is_Alive == false)
	{
		Is_Flying = false;
		return Is_Flying;
	}

	if (Time_Since_Last_Meal > 8 || Meal_Per_Day <= 0)
	{
		Is_Flying = false;
	}

	return Is_Flying;
}
//------------------------------------------------------------------------------------------------------------

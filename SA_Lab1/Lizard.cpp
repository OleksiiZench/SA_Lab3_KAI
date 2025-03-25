#include "Lizard.h"

//------------------------------------------------------------------------------------------------------------
Lizard::Lizard(std::string name) : Animal(name)
{
	Eyes = 2;
	Paws = 4;
}
//------------------------------------------------------------------------------------------------------------
Lizard::~Lizard()
{
}
//------------------------------------------------------------------------------------------------------------
void Lizard::To_Walk()
{
	if (Is_Alive == false)
	{
		Is_Walking = false;
		return;
	}

	if (Is_Walking == false)
	{
		if (Is_Crawling == true)
			Is_Crawling = false;

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
void Lizard::To_Crawl()
{
	if (Is_Alive == false)
	{
		Is_Crawling = false;
		return;
	}

	if (Is_Crawling == false && Time_Since_Last_Meal < 8)
	{
		if (Is_Walking == true)
			Is_Walking = false;

		Is_Crawling = true;
		return;
	}
	else
	{
		Is_Crawling = false;
		return;
	}
}
//------------------------------------------------------------------------------------------------------------
bool Lizard::Get_Is_Crawling()
{
	if (Is_Alive == false)
	{
		Is_Crawling = false;
		return Is_Crawling;
	}

	if (Time_Since_Last_Meal > 8 || Meal_Per_Day <= 0)
	{
		Is_Crawling = false;
	}

	return Is_Crawling;
}
//------------------------------------------------------------------------------------------------------------

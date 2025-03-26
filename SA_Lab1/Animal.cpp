#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
Animal::Animal(std::string name) : Name(name)
{
	On_Feed.Add_Listener([this]() {To_Eat(); });

	On_Clean.Add_Listener([this]() {To_Clean(); });

	On_Care.Add_Listener([this]() {To_Eat(); });
	On_Care.Add_Listener([this]() {To_Clean(); });
}
//------------------------------------------------------------------------------------------------------------
Animal::~Animal()
{
}
//------------------------------------------------------------------------------------------------------------
void Animal::To_Walk()
{
}
//------------------------------------------------------------------------------------------------------------
void Animal::Attach(IObserver *observer)
{
	observers.push_back(observer);
}
//------------------------------------------------------------------------------------------------------------
void Animal::Detach(IObserver *observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end() );
}
//------------------------------------------------------------------------------------------------------------
void Animal::Notify(const std::string &message)
{
	for (IObserver *observer : observers)
		observer->Update(message);
}
//------------------------------------------------------------------------------------------------------------
void Animal::To_Eat()
{
	if (Is_Alive != false)
	{
		if (Meal_Per_Day == 0)
		{
			Meal_Per_Day += 1;
			Time_Since_Last_Meal = 0;
			Notify(Name + " ate");
		}
		else if (Time_Since_Last_Meal >= 3)
		{
			Meal_Per_Day += 1;
			Time_Since_Last_Meal = 0;
			Notify(Name + " ate");
		}
	}
}
//------------------------------------------------------------------------------------------------------------
void Animal::To_Clean()
{
	if (Is_Alive != false)
	{
		Is_Clean = true;
		Notify(Name + " is clean");

	}
}
//------------------------------------------------------------------------------------------------------------
bool Animal::Get_Is_Alive()
{
	if (Meal_Per_Day > 5 || (Meal_Per_Day == 0 && Time_Since_Last_Meal == 24) )
		Is_Alive = false;

	return Is_Alive;
}
//------------------------------------------------------------------------------------------------------------
bool Animal::Get_Is_Happy()
{
	if (Is_Alive == false)
	{
		Is_Happy = false;
		return Is_Happy;
	}

	if (Meal_Per_Day > 0 && Is_Clean == true)
		Is_Happy = true;
	else
		Is_Happy = false;

	return Is_Happy;
}
//------------------------------------------------------------------------------------------------------------
bool Animal::Get_Is_Walking()
{
	if (Is_Alive == false)
	{
		Is_Walking = false;
		return Is_Walking;
	}

	return Is_Walking;
}
//------------------------------------------------------------------------------------------------------------
bool Animal::Get_Is_Clean()
{
	if (Is_Alive == false)
	{
		Is_Clean = false;
		return Is_Clean;
	}

	return Is_Clean;
}
//------------------------------------------------------------------------------------------------------------
int Animal::Get_Meal_Per_Day()
{
	if (Is_Alive == false)
	{
		Meal_Per_Day = 0;
		return Is_Clean;
	}

	return Meal_Per_Day;
}
//------------------------------------------------------------------------------------------------------------
int Animal::Get_Time_Since_Last_Meal()
{
	if (Is_Alive == false)
	{
		Time_Since_Last_Meal = 0;
		return Time_Since_Last_Meal;
	}

	return Time_Since_Last_Meal;
}
//------------------------------------------------------------------------------------------------------------
std::string Animal::Get_Name()
{
	return Name;
}
//------------------------------------------------------------------------------------------------------------

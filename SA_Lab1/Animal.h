#pragma once

#include <string>

#include "Event_Manager.h"

//------------------------------------------------------------------------------------------------------------
class Animal
{
public:
	Animal(std::string name);

	virtual ~Animal();

	virtual void To_Walk() = 0;

	void To_Eat();
	void To_Clean();
	bool Get_Is_Alive();
	bool Get_Is_Happy();
	bool Get_Is_Walking();
	bool Get_Is_Clean();
	int Get_Meal_Per_Day();
	int Get_Time_Since_Last_Meal();
	std::string Get_Name();

	int Meal_Per_Day = 1;  // Скільки прийомів їжі за день
	int Time_Since_Last_Meal = 0; // Час з останнього прийомі їжі
	bool Is_Clean = false;

	Event_Manager On_Feed;
	Event_Manager On_Clean;
	Event_Manager On_Care;

protected:
	bool Is_Alive = true;
	bool Is_Walking = false;
	int Eyes = 0;
	int Paws = 0;

private:
	bool Is_Happy = false;
	std::string Name = "";
};
//------------------------------------------------------------------------------------------------------------

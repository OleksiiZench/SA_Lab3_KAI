#pragma once

#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
class Dog : public Animal
{
public:
	Dog(std::string name);

	~Dog();

	virtual void To_Walk() override;

	void To_Run();
	bool Get_Is_Running();

private:
	bool Is_Running = false;
};
//------------------------------------------------------------------------------------------------------------

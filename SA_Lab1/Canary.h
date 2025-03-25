#pragma once

#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
class Canary : public Animal
{
public:
	Canary(std::string name);

	~Canary();

	virtual void To_Walk() override;

	void To_Sing();
	void To_Fly();

	bool Get_Is_Singing();
	bool Get_Is_Flying();

private:
	bool Has_Wings = true;
	bool Is_Singing = false;
	bool Is_Flying = false;
};
//------------------------------------------------------------------------------------------------------------

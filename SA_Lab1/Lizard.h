#pragma once

#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
class Lizard : public Animal
{
public:
	Lizard(std::string name);

	~Lizard();

	virtual void To_Walk() override;

	void To_Crawl();
	bool Get_Is_Crawling();

private:
	bool Is_Crawling = false;
};
//------------------------------------------------------------------------------------------------------------

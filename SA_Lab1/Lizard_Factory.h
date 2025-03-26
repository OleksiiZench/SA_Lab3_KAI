#pragma once

#include "Lizard.h"
#include "IAnimal_Factory.h"

//------------------------------------------------------------------------------------------------------------
class Lizard_Factory : public IAnimal_Factory
{
public:
	virtual Animal* Create_Animal(const std::string &name) override;
};
//------------------------------------------------------------------------------------------------------------

#pragma once

#include "Canary.h"
#include "IAnimal_Factory.h"

//------------------------------------------------------------------------------------------------------------
class Canary_Factory : public IAnimal_Factory
{
public:
	virtual Animal* Create_Animal(const std::string &name) override;
};
//------------------------------------------------------------------------------------------------------------

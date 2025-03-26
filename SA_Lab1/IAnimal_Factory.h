#pragma once

#include "Animal.h"

//------------------------------------------------------------------------------------------------------------
class IAnimal_Factory
{
public:
	virtual ~IAnimal_Factory() = default;

	virtual Animal* Create_Animal(const std::string &name) = 0;
};
//------------------------------------------------------------------------------------------------------------

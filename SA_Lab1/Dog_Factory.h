#pragma once

#include "Dog.h"
#include "IAnimal_Factory.h"

//------------------------------------------------------------------------------------------------------------
class Dog_Factory : public IAnimal_Factory
{
public:
	virtual Animal* Create_Animal(const std::string &name) override;
};
//------------------------------------------------------------------------------------------------------------

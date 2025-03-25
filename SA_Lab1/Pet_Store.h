#pragma once

#include "Animal_Location.h"

//------------------------------------------------------------------------------------------------------------
class Pet_Store : public Animal_Location
{
public:
	virtual std::string Get_Animal_Location() override;
};
//------------------------------------------------------------------------------------------------------------

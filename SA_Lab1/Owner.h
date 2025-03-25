#pragma once

#include "Animal_Location.h"

//------------------------------------------------------------------------------------------------------------
class Owner : public Animal_Location
{
public:
	virtual std::string Get_Animal_Location() override;
};
//------------------------------------------------------------------------------------------------------------

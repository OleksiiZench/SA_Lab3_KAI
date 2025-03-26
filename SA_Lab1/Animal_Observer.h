#pragma once

#include <iostream>
#include "IObserver.h"

//------------------------------------------------------------------------------------------------------------
class Animal_Observer : public IObserver
{
public:
	virtual void Update(const std::string &message) override;
};
//------------------------------------------------------------------------------------------------------------

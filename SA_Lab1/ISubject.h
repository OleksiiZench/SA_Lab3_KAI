#pragma once

#include <vector>
#include <string>

#include "IObserver.h"

//------------------------------------------------------------------------------------------------------------
class ISubject
{
public:
	virtual ~ISubject() = default;

	virtual void Attach(IObserver *observer) = 0;
	virtual void Detach(IObserver *observer) = 0;
	virtual void Notify(const std::string &message) = 0;
};
//------------------------------------------------------------------------------------------------------------

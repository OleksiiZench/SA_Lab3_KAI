#include "Canary_Factory.h"

//------------------------------------------------------------------------------------------------------------
Animal *Canary_Factory::Create_Animal(const std::string &name)
{
	return new Canary(name);
}
//------------------------------------------------------------------------------------------------------------

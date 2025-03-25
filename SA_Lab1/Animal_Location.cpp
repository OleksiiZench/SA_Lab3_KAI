#include "Animal_Location.h"

//------------------------------------------------------------------------------------------------------------
void Animal_Location::Add_Animal(Animal *animal)
{
	Animals.push_back(animal);
}
//------------------------------------------------------------------------------------------------------------
void Animal_Location::Release_Animal(Animal *animal)
{
	Animals.erase(std::remove(Animals.begin(), Animals.end(), animal), Animals.end() );
}
//------------------------------------------------------------------------------------------------------------
void Animal_Location::Feed_Animal(Animal *animal)
{
	animal->On_Feed.Trigger_Event();
}
//------------------------------------------------------------------------------------------------------------
void Animal_Location::Clean_Animal(Animal *animal)
{
	animal->On_Clean.Trigger_Event();
}
//------------------------------------------------------------------------------------------------------------
std::vector<Animal *> Animal_Location::Get_Animals()
{
	return Animals;
}
//------------------------------------------------------------------------------------------------------------

#include "DeathKnight.h"

DeathKnight::DeathKnight(const char* name, int x, int y)
:Monster(40,10,6,name,x,y),Goblin(name,x,y),Dragonkin(name,x,y)
{
}

double DeathKnight::attack(Hero& hero)
{
	return Goblin::attack(hero);
	
}

void DeathKnight::defend(double damage) 
{
	Dragonkin::defend(damage);
}
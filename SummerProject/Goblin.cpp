#include "Goblin.h"

Goblin::Goblin(const char* name) :Monster(10, 4, 5, name) 
{
}

void Goblin::attack(Hero& hero) 
{
	double damage = 3 + 0.1 * hero.getIntellect();
	hero.defend(damage);
}

void Goblin::defend(double damage) 
{
	setHp(getHp() - damage);
}
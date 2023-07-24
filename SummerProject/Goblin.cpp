#include "Goblin.h"

Goblin::Goblin(const char* name,int x,int y) :Monster(100, 4, 5, name,x,y) 
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
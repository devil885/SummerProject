#include "Goblin.h"

Goblin::Goblin(const char* name,int x,int y) :Monster(100, 4, 5, name,x,y) 
{
}

double Goblin::attack(Hero& hero)
{
	double damage = getStr() + 0.1 * hero.getIntellect();
	hero.defend(damage);
	return damage;
}

void Goblin::defend(double damage) 
{
	setHp(getHp() - damage);
}
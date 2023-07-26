#include "Dragonkin.h"

Dragonkin::Dragonkin(const char* name,int x,int y):Monster(30,9,5,name,x,y)
{
	this->immunityCd = 2;
}

double Dragonkin::attack(Hero& hero) 
{
	double damage = 8;
	hero.defend(damage);
	return damage;
}

void Dragonkin::defend(double damage) 
{
	setHp(getHp() - damage);
}
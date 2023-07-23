#include "Paladin.h"

Paladin::Paladin(const char* name):Hero(100,9,6,name)
{
	this->smiteCooldown = 2;
}

void Paladin::attack(Monster& enemy) 
{
	if (!isInBattle())
	{
		enterBattle();
	}

	double damage;
	if (!this->smiteCooldown)
	{
		damage = 1.5*(0.5 * getStr() + 0.5 * getIntellect());
		enemy.defend(damage);
		this->smiteCooldown = 2;
		return;
	}

	damage = 0.5 * getStr() + 0.5 * getIntellect();
	enemy.defend(damage);
	this->smiteCooldown--;
}

void Paladin::defend(double damage) 
{

}
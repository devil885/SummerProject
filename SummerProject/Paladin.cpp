#include "Paladin.h"

Paladin::Paladin(const char* name):Hero(100,9,6,name)
{
	this->smiteCooldown = 2;
}

double Paladin::attack(Monster& enemy)
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
		return damage;
	}

	damage = 0.5 * getStr() + 0.5 * getIntellect();
	enemy.defend(damage);
	this->smiteCooldown--;
	return damage;
}

void Paladin::defend(double damage) 
{
	setHp(getHp() - damage);
}

void Paladin::printSpecial() 
{
	if (this->smiteCooldown)
	{
		cout << " Smite cd: " << this->smiteCooldown << endl;
	}
	else
	{
		cout << " Smite Ready!" << endl;
	}
}
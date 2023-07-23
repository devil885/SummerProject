#include "Warrior.h"
#pragma warning(disable:4996)
Warrior::Warrior(const char* name):Hero(100,13,2,name)
{
	this->rage = 0;
	this->bonusDamage = 0;
}

void Warrior::setBonus() 
{
	this->bonusDamage = rage / 500;
	this->rage = 0;
}

void Warrior::attack(Monster &enemy) 
{
	if (!isInBattle())
	{
		enterBattle();
	}
	double damage = getStr() + 0.3 * getIntellect();
	increaseRage(2);
	enemy.defend(damage * (1 + bonusDamage));
}

void Warrior::defend(double damage) 
{
	setHp(getHp() - damage);
	increaseRage(3);
}

void Warrior::increaseRage(int extraRage)
{
	if (this->rage+extraRage>100)
	{
		this->rage = 100;
		return;
	}
	this->rage += extraRage;
}
#include "Mage.h"

Mage::Mage(const char* name):Hero(100,4,11,name)
{
	this->mana = 100;
}

void Mage::attack(Monster& enemy)
{
	double damage = getIntellect() + (this->mana / 100) * 3;
	enemy.defend(damage);
	this->mana -= 10;
}

void Mage::defend(double damage)
{
	setHp(getHp() - damage);
}

void Mage::refreshMana()
{
	this->mana = 100; 
}
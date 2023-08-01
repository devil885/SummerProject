#include "Mage.h"

Mage::Mage(const char* name):Hero(100,4,11,name)
{
	this->mana = 100;
}

double Mage::attack(Monster& enemy)
{
	if (!isInBattle())
	{
		enterBattle();
		refreshMana();
	}
	double damage = getIntellect() + (this->mana / 100) * 3;
	enemy.defend(damage);
	if (this->mana<10)
	{
		this->mana = 0;
	}
	else 
	{
		this->mana -= 10;
	}
	return damage;
}

void Mage::defend(double damage)
{
	setHp(getHp() - damage);
}

void Mage::printSpecial() 
{
	cout << " Mana: ";
	cout << this->mana << endl;
	
}

void Mage::refreshMana()
{
	this->mana = 100; 
}

void Mage::leaveBattle() 
{
	refreshMana();
	Hero::leaveBattle();
}
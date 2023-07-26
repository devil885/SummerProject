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
	this->mana -= 10;
	return damage;
}

void Mage::defend(double damage)
{
	setHp(getHp() - damage);
}

void Mage::printSpecial() 
{
	cout << " Mana: ";
	if (isInBattle())
	{
		cout<<this->mana << endl;
	}
	else
	{
		cout << 100<<endl;
	}
	
}

void Mage::refreshMana()
{
	this->mana = 100; 
}
#pragma once
#include "Hero.h"
#include <iostream>

using namespace std;

class Mage:public Hero
{
public:
	Mage(const char* name);
	double attack(Monster& enemy) override;
	void defend(double damage) override;
	void printSpecial() override;
	void refreshMana();
private:
	double mana;
};

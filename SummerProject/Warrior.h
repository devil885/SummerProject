#pragma once
#include "Hero.h"
#include <iostream>

using namespace std;
class Warrior:public Hero 
{
public:
	Warrior(const char* name);
	void setBonus();
	double attack(Monster& enemy) override;
	void defend(double damage) override;
	void printSpecial() override;
private:
	double rage;
	double bonusDamage;
	void increaseRage(int extraRage);
};
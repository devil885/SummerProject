#pragma once
#include "Hero.h"

class Warrior:public Hero 
{
public:
	Warrior(char* name);
	void setBonus();
	void attack(Monster& enemy) override;
	void defend(double damage) override;
private:
	double rage;
	double bonusDamage;
	void increaseRage(int extraRage);
};
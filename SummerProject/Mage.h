#pragma once
#include "Hero.h"
class Mage:public Hero
{
public:
	Mage(const char* name);
	void attack(Monster& enemy) override;
	void defend(double damage) override;
	void refreshMana();
private:
	int mana;
};

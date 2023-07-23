#pragma once
#include "Hero.h"
class Paladin :public Hero
{
public:
	Paladin(const char* name);
	void attack(Monster& enemy)override;
	void defend(double damage)override;

private:
	int smiteCooldown;
};


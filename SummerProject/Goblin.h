#pragma once
#include "Monster.h"

class Goblin: virtual public Monster
{
public:
	Goblin(const char* name, int x, int y);
	double attack(Hero& hero)override;
	void defend(double damage)override;
};
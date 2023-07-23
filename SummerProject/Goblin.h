#pragma once
#include "Monster.h"

class Goblin:public Monster
{
public:
	Goblin(const char* name);
	void attack(Hero& hero)override;
	void defend(double damage)override;
private:

};
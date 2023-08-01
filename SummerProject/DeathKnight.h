#pragma once
#include "Goblin.h"
#include "Dragonkin.h"
class DeathKnight:public Goblin,public Dragonkin
{
public:
	DeathKnight(const char* name,int x,int y);
	double attack(Hero& hero) override;
	void defend(double damage) override;
};

#pragma once
#include "Monster.h"
class Dragonkin :public Monster
{
public:
	Dragonkin(const char* name,int x,int y);
	double attack(Hero& hero) override;
	void defend(double damage)override;

private:
	int immunityCd;
};


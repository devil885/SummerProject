#pragma once
#include "Hero.h"
#include <iostream>

using namespace std;

class Paladin :public Hero
{
public:
	Paladin(const char* name);
	double attack(Monster& enemy)override;
	void defend(double damage)override;
	void printSpecial() override;
private:
	int smiteCooldown;
};


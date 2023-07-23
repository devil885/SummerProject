#pragma once
#include "Hero.h"
class Hero;
class Monster
{
public:
	Monster(int hp, int str, int intellect, const char* name);
	virtual ~Monster();
	Monster(const Monster& other);
	Monster& operator=(const Monster& other);
	virtual void attack(Hero& enemy)=0;
	virtual void defend(double damage)=0;
private:
	int hp;
	int str;
	int intellect;
	char* name;
};

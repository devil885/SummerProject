#pragma once
#include "Monster.h"

class Hero
{
public:
	Hero(int hp, int str, int intellect, char* name);
	virtual ~Hero();
	Hero(const Hero& other);
	Hero& operator=(const Hero& other);
	void levelUp();
	virtual void attack(Monster& enemy) = 0;
	virtual void defend(double damage) = 0;

protected:
	int getIntellect() const;
	int getStr() const;
	int getHp() const;
	void setHp(int value);
private:
	int hp;
	int str;
	int intellect;
	int level;
	int xp;
	int maxHp;
	int baseStr;
	int baseInt;
	char* name;
};


#pragma once
#include "Monster.h"
class Monster;
class Hero
{
public:
	Hero(int hp, int str, int intellect,const char* name);
	virtual ~Hero();
	Hero(const Hero& other);
	Hero& operator=(const Hero& other);
	void levelUp();
	void increaseXp(int amount);
	virtual void attack(Monster& enemy) = 0;
	virtual void defend(double damage) = 0;

protected:
	int getIntellect() const;
	int getStr() const;
	double getHp() const;
	void setHp(double value);
private:
	double hp;
	int str;
	int intellect;
	int level;
	int xp;
	int maxHp;
	int baseStr;
	int baseInt;
	char* name;
};


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

	virtual double attack(Monster& enemy) = 0;
	virtual void defend(double damage) = 0;
	virtual void printSpecial() = 0;
	
	void enterBattle();
	virtual void leaveBattle();
	int getIntellect() const;
	double getHp() const;
	int getStr() const;
	char* getName() const;
	int getLevel() const;
	void increaseXp(int amount);
protected:
	void setHp(double value);
	bool isInBattle() const;
	
private:
	double hp;
	double maxHp;
	int str;
	int intellect;
	int level;
	int xp;
	int baseStr;
	int baseInt;
	char* name;
	bool inBattle;
	void levelUp();
};


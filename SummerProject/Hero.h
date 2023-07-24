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
	void enterBattle();
	void leaveBattle();
	int getIntellect() const;
	double getHp() const;
	int getStr() const;
protected:
	void setHp(double value);
	bool isInBattle() const;
	
private:
	double hp;
	int str;
	int intellect;
	int level;
	int xp;
	double maxHp;
	int baseStr;
	int baseInt;
	char* name;
	bool inBattle;
};


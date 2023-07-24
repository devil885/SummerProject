#pragma once
#include "Hero.h"
class Hero;
class Monster
{
public:
	Monster(int hp, int str, int intellect, const char* name,int x,int y);//deathknight 10str 6int goblin 4str 5int
	//dragonkin 9str 5int
	virtual ~Monster();
	Monster(const Monster& other);
	Monster& operator=(const Monster& other);
	virtual void attack(Hero& hero)=0;
	virtual void defend(double damage)=0;
	double getHp() const;
	int getX() const;
	int getY() const;
protected:
	void setHp(double amount);
private:
	double hp;
	int str;
	int intellect;
	char* name;
	int x;
	int y;
};

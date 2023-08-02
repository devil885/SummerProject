#include "Hero.h"
#include <cstring>
#include <cmath>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;
Hero::Hero(int hp, int str, int intellect, const char* name)
{
	this->hp = hp;
	this->str = str;
	this->intellect = intellect;
	this->level = 0;
	this->xp = 0;
	this->maxHp = hp;
	this->baseInt = intellect;
	this->baseStr = str;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->inBattle = false;
}

Hero::~Hero() 
{
	delete[] this->name;
}

Hero::Hero(const Hero& other) 
{
	this->hp = other.hp;
	this->str = other.str;
	this->intellect = other.intellect;
	this->level = other.level;
	this->xp = other.xp;
	this->maxHp = other.maxHp;
	this->baseInt = other.baseInt;
	this->baseStr = other.baseStr;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->inBattle = other.inBattle;
}

Hero& Hero::operator=(const Hero& other) 
{
	if (this!= &other)
	{
		delete[] this->name;
		this->hp = other.hp;
		this->str = other.str;
		this->intellect = other.intellect;
		this->xp = other.xp;
		this->level = other.level;
		this->maxHp = other.maxHp;
		this->baseInt = other.baseInt;
		this->baseStr = other.baseStr;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->inBattle = other.inBattle;
	}
	
	return *this;
}

void Hero::levelUp() 
{
	this->maxHp *= 1.1;
	this->hp = this->maxHp;
	this->str += this->baseStr / 3;
	this->intellect += this->baseInt / 3;
	this->level++;
	cout << "You leveled up Pog!" <<endl;
}

void Hero::increaseXp(int amount) 
{
	if (this->xp+amount>=pow(2,level))
	{
		this->xp = this->xp + amount - pow(2, level);
		levelUp();
		return;
	}
	this->xp += amount;

}

int Hero::getIntellect() const { return this->intellect; }
int Hero::getStr() const { return this->str; }
double Hero::getHp() const { return this->hp; }
char* Hero::getName() const { return this->name; }
int Hero::getLevel() const { return this->level; }
bool Hero::isInBattle() const { return this->inBattle; }

void Hero::setHp(double value) { this->hp = value; }
void Hero::enterBattle() { this->inBattle = true; }
void Hero::leaveBattle() { this->inBattle = false; }
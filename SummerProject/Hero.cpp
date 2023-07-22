#include "Hero.h"
#include <cstring>
#pragma warning(disable:4996)

Hero::Hero(int hp, int str, int intellect, char* name)
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
}

int Hero::getIntellect() const { return intellect; }
int Hero::getStr() const { return str; }
int Hero::getHp() const { return hp; }
void Hero::setHp(int value) { this->hp = value; }
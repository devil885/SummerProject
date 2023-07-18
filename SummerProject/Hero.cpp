#include "Hero.h"
#include <cstring>
#pragma warning(disable:4996)

Hero::Hero(int hp, char* name, int str, int intellect) 
{
	this->hp = hp;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->str = str;
	this->intellect = intellect;
	this->level = 0;
	this->monstersKilled = 0;
	this->baseInt = intellect;
	this->baseStr = str;
	
}

Hero::~Hero() 
{
	delete[] this->name;
}

Hero::Hero(const Hero& other) 
{
	this->hp = other.hp;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->str = other.str;
	this->intellect = other.intellect;
	this->level = other.level;
	this->monstersKilled = other.monstersKilled;
	this->baseInt = other.baseInt;
	this->baseStr = other.baseStr;
}

const Hero& Hero::operator=(const Hero& other) 
{
	if (this!= &other)
	{
		delete[] this->name;
		this->hp = other.hp;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->str = other.str;
		this->intellect = other.intellect;
		this->monstersKilled = other.monstersKilled;
		this->level = other.level;
		this->baseInt = other.baseInt;
		this->baseStr = other.baseStr;
	}
	return *this;
}

void Hero::levelUp() 
{
	this->hp *= 1.1;
	this->str += this->baseStr / 3;
	this->intellect += this->baseInt / 3;
	this->level++;
}
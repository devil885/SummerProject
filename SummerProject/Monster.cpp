#include "Monster.h"
#include <cstring>
#pragma warning(disable:4996)

Monster::Monster(int hp, int str, int intellect, const char* name)
{
	this->hp=hp;
	this->str = str;
	this->intellect = intellect;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}



Monster::~Monster() 
{
	delete[] name;
}

Monster::Monster(const Monster& other)
{
	this->hp = other.hp;
	this->str = other.str;
	this->intellect = other.intellect;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

Monster& Monster::operator=(const Monster& other) 
{
	if (this != &other) 
	{
		delete[] name;
		this->hp = other.hp;
		this->str = other.str;
		this->intellect = other.intellect;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	return *this;
}
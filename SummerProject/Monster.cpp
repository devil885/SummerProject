#include "Monster.h"
#include <cstring>
#pragma warning(disable:4996)

Monster::Monster(int hp, int str, int intellect, const char* name, int x, int y)
{
	this->hp=hp;
	this->str = str;
	this->intellect = intellect;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->x = x;
	this->y = y;
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
	this->x = other.x;
	this->y = other.y;
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
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

double Monster::getHp() const{ return this->hp; }
void Monster::setHp(double amount) { this->hp = amount; }
int Monster::getX() const { return this->x; }
int Monster::getY() const { return this->y; }
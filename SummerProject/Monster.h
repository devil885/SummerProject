#pragma once
class Monster
{
public:
	Monster(int hp, int str, int intellect, char* name);
	virtual ~Monster();
	Monster(const Monster& other);
	Monster& operator=(const Monster& other);
	virtual void attack()=0;
	virtual void defend()=0;
private:
	int hp;
	int str;
	int intellect;
	char* name;
};

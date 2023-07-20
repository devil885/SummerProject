#pragma once
class Hero
{
public:
	Hero(int hp, int str, int intellect, char* name);
	virtual ~Hero();
	Hero(const Hero& other);
	Hero& operator=(const Hero& other);
	void levelUp();
	virtual void attack() = 0;
	virtual void defend() = 0;

private:
	int hp;
	int str;
	int intellect;
	int level;
	int xp;
	int baseStr;
	int baseInt;
	char* name;
};


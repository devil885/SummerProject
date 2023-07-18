#pragma once
class Hero
{
public:
	Hero(int hp,char* name,int str,int intellect);
	virtual ~Hero();
	Hero(const Hero& other);
	const Hero& operator=(const Hero& other);
	void levelUp();
	virtual void attack() = 0;
	virtual void defend() = 0;

private:
	int hp;
	char* name;
	int str;
	int intellect;
	int level;
	int monstersKilled;
	int baseStr;
	int baseInt;
};


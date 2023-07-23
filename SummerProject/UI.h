#pragma once
#include"Warrior.h"
#include "Goblin.h"

class UI
{
public:
	UI(const UI& other) = delete;
	UI& operator= (const UI & other) = delete;
	static UI* getInstance() 
	{
		if (instancePtr == nullptr)
		{
			instancePtr = new UI();
		}
		return instancePtr;
	};
	~UI();
	void gameStart();

private:
	int map[21][21]{};
	Monster** monsters;
	Hero* player;
	static UI* instancePtr;
	void generateMap();
	Hero* getHero();
	UI();
};

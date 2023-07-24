#pragma once
#include"Warrior.h"
#include "Goblin.h"
#include "BasedVector.h"
#include <stdlib.h>
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
	Monster* generateMonster(int x, int y);

private:
	int map[21][21]{};
	BasedVector<Monster*> monsters;
	Hero* player;
	static UI* instancePtr;
	int monsterCount;
	int mapSize;
	int playerX;
	int playerY;
	bool runGame;
	UI();
	void generateMap();
	Hero* getHero();
	void printMap();
	void printTile(int num);
	void step();
	void readInput();
	void move(int x, int y);
	Monster* findMonster(int x, int y);
	void battle(Monster* enemy,int x,int y);
};

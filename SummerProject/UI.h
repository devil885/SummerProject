#pragma once
#include"Warrior.h"
#include "Mage.h"
#include "Paladin.h"

#include "Goblin.h"
#include "Dragonkin.h"
#include"DeathKnight.h"

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
	const char* playerClass;
	int monsterCount;
	int livingMonsters;
	int mapSize;
	int playerX;
	int playerY;
	bool runGame; 

	UI();
	void generateMap();
	Hero* getHero();
	void printMap();
	void printTile(int num);
	void step(char input);
	char readInput();
	void move(int x, int y);
	Monster* findMonster(int x, int y);
	void battle(Monster* enemy, char* enemyName,int x,int y);
	void printPlayerStats();
};

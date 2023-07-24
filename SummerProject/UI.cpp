#include "UI.h"
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

Hero* UI::getHero() 
{
	cout << "Pick a class: Warrior (w)"<<endl;
	char hero;
	char* name=new char[1025];
	cin >> hero;
	cout << "Enter name:"<<endl;
	cin >> name;

	switch (hero)
	{
	case 'w':
	{Hero* pc = new Warrior(name);
	delete[] name;
	return pc; }
	default:
		return nullptr;
	}
}

void UI::generateMap() 
{
	for (int i = 0; i < 21; i++)
	{
		this->map[i][8] = -1;
		this->map[i][12] = -1;
	}
	this->map[0][10]=69;
	this->playerX = 0;
	this->playerY = 10;
	this->map[4][10] = 1;
	this->mapSize = 21;
}

/*
UI* UI::getInstance() 
{
	if (UI::instancePtr == nullptr)
	{
		UI::instancePtr = new UI();
	}
	return UI::instancePtr;
}
*/



UI::UI() : map()
{
	this->player = getHero();
	this->monsterCount = 0;
	generateMap();
	this->runGame = true;
}

UI::~UI() 
{
	delete player;
	for (int i = 0; i < this->monsterCount; i++)
	{
		delete monsters[i];
	}
}

Monster* UI::generateMonster(int x,int y) 
{
	Monster* enemy = nullptr;
	switch (map[x][y])
	{
	case 1:
	{ enemy = new Goblin("Goblin",x,y);
	this->monsters.push(enemy);
	this->monsterCount++;
	break; }
	default:
		break;
	}
	return enemy;

}

Monster* UI::findMonster(int x, int y) 
{
	for (int i = 0; i < monsterCount; i++)
	{
		
		if (x== monsters[i]->getX() && y== monsters[i]->getY())
		{
			return monsters[i];
		}
	}
	return nullptr;
}

void UI::printTile(int num) 
{
	switch (num)
	{
	case -1:
		cout << 'x';//wall
		break;
	case 1://not previously generated goblin
		cout << 'G';//goblin
		break;
	case 100://already generated goblin
		cout << 'G';//goblin
		break;
	case 2:
		cout <<(char)235;//dragonkin
		break;
	case 3:
		cout << (char)146;//deathkinght
		break;
	case 69:
		cout << 'U';//player
		break;
	default:
		cout << (char)176;//field
		break;
	}
}

void UI::printMap() 
{
	for (int i = 20; i >=0; i--)
	{
		for (int j = 0; j <20; j++)
		{
			printTile(this->map[i][j]);
		}
		cout << endl;
	}
}

void UI::battle(Monster* enemy, int x, int y)
{
	player->attack(*enemy);
	if (enemy->getHp() > 0)
	{
		enemy->attack(*player);
	}
	else
	{
		player->increaseXp(1);
		map[x][y] = (char)176;
		swap(map[x][y], map[playerX][playerY]);
		playerX = x;
		playerY = y;
	}
}

void UI::move(int x, int y) 
{
	Monster* enemy = nullptr;
	switch (this->map[x][y])
	{
	case -1:
		cout << "You can't go there!"<<endl;
		break;
	case 1:
		cout << "You attack the goblin" << endl;
		enemy = generateMonster(x, y);
		map[x][y] = 100;//the goblin is now counted as a generated goblin
		battle(enemy, x, y);
		break;
	case 100:
		cout << "You attack the goblin" << endl;
		battle(findMonster(x, y),x,y);
		break;
	default:
		swap(map[x][y], map[playerX][playerY]);
		playerX = x;
		playerY = y;
		break;
	}
}

void UI::readInput() 
{
	char input;
	cin >> input;
	switch (input)
	{
	case 'w':
		move(playerX+1,playerY);
		break;
	case 's':
		move(playerX - 1, playerY);
		break;
	case 'a':
		move(playerX, playerY-1);
		break;
	case 'd':
		move(playerX, playerY+1);
		break;
	case 'q':
		this->runGame = false;
		cout << "Quitting game!"<<endl<<"Thank you for playing <3";
	default:
		break;
	}
}
/*
void UI::step() 
{
	char input;
	cin >> input;

}
*/
void UI::gameStart() 
{
	//getHero();
	//generateMap();
	while (this->runGame)
	{
		system("cls");
		printMap();
		readInput();

	}
}

UI* UI::instancePtr = nullptr;
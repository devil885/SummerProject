#include "UI.h"
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

Hero* UI::getHero() 
{
	cout << "Pick a class:" << endl;
	cout<<" Warrior (w)"<<endl;
	cout<<" Mage (m)"<<endl;
	cout<<" Paladin (p)"<<endl;
	char hero;
	char* name=new char[1025];
	//cin >> hero;
	do
	{
		cin >> hero;
		if (hero != 'w' && hero != 'm' && hero != 'p')
		{
			cout << "Incorrect command!"<<endl;
		}
	} while (hero!='w' && hero!='m' && hero!='p');
	cout << "Enter name:"<<endl;
	cin >> name;

	Hero* pc = nullptr;
	switch (hero)
	{
	case 'w':
	pc = new Warrior(name);
	playerClass = "Warrior";
	break;
	//return pc; 
	case 'm':
		pc = new Mage(name);
		playerClass = "Mage";
		break;
	case 'p':
		pc = new Paladin(name);
		playerClass = "Paladin";
		break;
	default:
		cout << "Invalid command";
		break;
	}
	delete[] name;
	return pc;
}

void UI::generateMap() 
{
	for (int i = 0; i < 21; i++)
	{
		this->map[i][8] = -1;//walls
		this->map[i][12] = -1;
	}

	this->map[0][10]=69;
	this->playerX = 0;
	this->playerY = 10;
	for (int i = 2; i < 21; i+=2)
	{
		this->map[i][10] = 1;//goblins
		this->map[i][11] = 2;//dragonkin
	}

	this->mapSize = 21;
}

UI::UI() : map()
{
	this->monsterCount = 0;
	this->livingMonsters = 0;
	generateMap();
	this->runGame = true;
	this->playerClass = "";
	this->player = getHero();
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
		enemy = new Goblin("Goblin",x,y);
		this->monsters.push(enemy);
		this->monsterCount++;
		this->livingMonsters++;
		break; 
	case 2:
		enemy = new Dragonkin("Dragonkin", x, y);
		this->monsters.push(enemy);
		this->monsterCount++;
		this->livingMonsters++;
		break;
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
	case 0:
		cout << (char)176;//field
		break;
	case -1:
		cout << 'x';//wall
		break;
	case 1://not previously generated goblin
		cout << 'G';
		break;
	case 100://already generated goblin
		cout << 'G';
		break;
	case 2://not previously generated dragonkin
		cout <<'D';//dragonkin
		break;
	case 200://already generated dragonkin
		cout<< 'D';
		break;
	case 3:
		cout << (char)146;//deathkinght
		break;
	case 69:
		cout << 'U';//player
		break;
	default:
		cout << '?';//unexpected value
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

void UI::battle(Monster* enemy,char* enemyName, int x, int y)
{
	double damage;
	double enemyDmg ;
	damage = player->attack(*enemy);
	cout << "You dealt " << damage << " damage to the " << enemyName << endl;
	if (enemy->getHp() > 0)
	{
		enemyDmg = enemy->attack(*player);
		cout << "The " << enemyName << " hit you for " << enemyDmg << " damage!" << endl;
		if (player->getHp() <= 0)
		{
			cout << "You died!" << endl;
			cout << "Game over!";
			this->runGame = false;
		}
	}
	else
	{
		map[x][y] = 0;
		swap(map[x][y], map[playerX][playerY]);
		playerX = x;
		playerY = y;
		livingMonsters--;
		if (livingMonsters==0)
		{
			player->leaveBattle();
		}
		cout << "You killed the " << enemyName << "!!" << endl;
		player->increaseXp(1);
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
		battle(enemy,enemy->getName(), x, y);
		break;
	case 100:
		cout << "You attack the goblin" << endl;
		enemy = findMonster(x, y);
		battle(enemy, enemy->getName(), x,y);
		break;
	case 2:
		cout << "You attack the dragonkin" << endl;
		enemy = generateMonster(x, y);
		map[x][y] = 200;//the dragonkin is now counted as a generated dragonkin
		battle(enemy, enemy->getName(), x, y);
		break;
	case 200:
		cout << "You attack the dragonkin" << endl;
		enemy = findMonster(x, y);
		battle(enemy, enemy->getName(), x, y);
		break;
	case 0:
		swap(map[x][y], map[playerX][playerY]);
		playerX = x;
		playerY = y;
		break;
	default:
		cout << "You can't exit the map!!" << endl;
		break;
	}
}

void UI::step(char input)
{
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
		break;
	default:
		cout << "Invalid command!" << endl;
		break;
	}
}

char UI::readInput() 
{
	char input;
	cin >> input;
	return input;
}

void UI::printPlayerStats() 
{
	cout << "Name: " << player->getName() << " Class: " << playerClass;
	player->printSpecial();
	cout << "HP: " << player->getHp() << " Str: " << player->getStr() << " Int: " << player->getIntellect()<<endl;
	//cout << "X: " << playerX << " Y: " << playerY << endl;
}

void UI::gameStart() 
{
	while (this->runGame)
	{
		printMap();
		printPlayerStats();
		char input = readInput();
		system("cls");
		step(input);
	}
}

UI* UI::instancePtr = nullptr;
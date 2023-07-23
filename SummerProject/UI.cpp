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
		map[i][8] = -1;
		map[i][12] = -1;
	}
	map[0][10]=69;
	map[4][10] = 1;
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
	generateMap();

}
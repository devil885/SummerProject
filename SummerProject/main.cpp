#include <iostream>
#include <conio.h>
#include "UI.h"
using namespace std;

int main() 
{
	UI* game= UI::getInstance();
	game->gameStart();
	return 0;
}
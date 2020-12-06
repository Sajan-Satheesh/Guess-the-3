#pragma once
#include <iostream>

using namespace std;

class Title_Screen
{
public:
	
	Title_Screen();
	~Title_Screen();

	char newgame = 'n';
	char selectlevel = 'l';
	char quitgame = 'q';
	int pause = 0;
	char continuegame = 'c';
	char mainmenu = 'm';
	int levelname = 1;

	void Main_Heading();
	void Main_Options();
	void Select_Level();
	int Pause_Options();
	void Credit_Options();
	void gameplay(int levelnum);
};


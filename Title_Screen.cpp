#pragma once
#include <iostream>
#include <stdlib.h>
#include "Title_Screen.h"
#include "Global_Input_Variable.h"
using namespace std;

Title_Screen::Title_Screen() {}

Title_Screen::~Title_Screen() {}

void Title_Screen::Main_Heading() {
	cout << "\n\n\n\n\n\n\n          _____________________________      " << endl;
	cout << "         |                             |      " << endl;
	cout << "         |    GUESS  _ THE _  THREE    |      " << endl;
	cout << "         |                             |      " << endl;
	cout << "         |      *** the  game ***      |      " << endl;
	cout << "         |_____________________________|   \n\n" << endl;
}

void Title_Screen::Select_Level() {
	cout << "\nTo play\nLevel 1, Press 1\nLevel 2, Press 2\nLevel 3, Press 3\nLevel 4, Press 4\nLevel 5, Press 5\n" << endl;
	cout << "enter the level you would like to play:" << endl;
	cin >> levelinput;
	if (levelinput > 0 && levelinput < 6)
	{
		gameplay(levelinput);
	}
	else
	{
		cout << "\nSelect a valid option\n\n" << endl;
		Select_Level();
	}
}

void Title_Screen::Main_Options()
{
	cout << "\n\nNew game - " << newgame << "   Select Level - " << selectlevel << "   Quit Game - " << quitgame << endl;
	cin >> input;
	if (input == newgame)
	{
		gameplay(1);
	}
	else if (input == selectlevel)
	{
		Select_Level();
	}
	else if (input == quitgame)
	{
		cout << "\nThanks for playing!!\nSee you soon!" << endl;
	}
	else
	{
		cout << "\nSelect a valid option\n\n" << endl;
		Main_Options();
	}
}

int Title_Screen::Pause_Options()
{
	Main_Heading();
	cout << "\n\nRestart level - " << continuegame << "   Quit game - " << quitgame <<endl;
	cin >> input;
	if (input==continuegame)
	{
		gameplay(currlevel);
	}
	else if (input==quitgame)
	{
		cout << "\nThanks for playing!!\nSee you soon!" << endl; 
		return 0;
	}
	else
	{
		cout << "\nSelect a valid option\n\n" << endl;
		Pause_Options();
	}
}

void Title_Screen::Credit_Options()
{
	cout << "                       _____________________________       " << endl;
	cout << "                      |                             |      " << endl;
	cout << "                      |    GUESS  _ THE _  THREE    |      " << endl;
	cout << "                      |                             |      " << endl;
	cout << "                      |      *** the  game ***      |      " << endl;
	cout << "                      |_____________________________|     \n" << endl;
	cout << "                            - a game by Sajan              " << endl;
	cout << "\n\nMain menu - " << mainmenu << "   Quit game - " << quitgame << endl;
	cin >> input;
	if (input == mainmenu)
	{
		Main_Heading();
		Main_Options();
	}
	else if (input == quitgame)
	{
		cout << "\nThanks for playing!!\nSee you soon!" << endl;
	}
	else
	{
		cout << "\nSelect a valid option\n\n" << endl;
		Credit_Options();
	}
}

void Title_Screen::gameplay(int levelnum) {

	while (levelnum<=finallevel && input!=quitgame) {
		cout << "\n\n\nWelcome to the level " << levelnum << endl;
		int difficulty = 1;
		RAND_MAX;
		int A = rand() % levelnum + difficulty;
		int B = rand() % levelnum + difficulty;
		int C = rand() % levelnum + difficulty;

		int Product = A * B * C;
		int Sum = A + B + C;

		int GuessSum;
		int GuessProduct;
		int GuessA;
		int GuessB{};
		int GuessC{};

		cout << "Press 0 to Pause game\n" << endl;
		cout << "Product of the numbers is : "<<Product << "\nSum of the numbers is : " << Sum << endl;
		cout << "\nEnter your first guess : " << endl;
		cin >> GuessA;
		if (GuessA == pause)
		{
			Pause_Options();
		}
		else
		{
			cout << "Enter your second guess : " << endl;
			cin >> GuessB;
			if (GuessB == pause)
			{
				Pause_Options();
			}
			else
			{
				cout << "Enter your Third guess : " << endl;
				cin >> GuessC;
			}
		}
		
		
		GuessProduct = GuessA * GuessB * GuessC;
		GuessSum = GuessA + GuessB + GuessC;

		if (GuessProduct == Product && GuessSum == Sum && levelnum == 5)
		{
			cout << "\n\n\n\n\n\n\n\n                      YOU ARE A GENIUS! LEVEL PASSED!" << endl;
			cout << "                      C O N G R A T U L A T I O N S !\n" << endl;
			Credit_Options();
			levelnum++;
			currlevel = levelnum;
		}
        else if (GuessProduct == Product && GuessSum == Sum)
		{
			cout << "\n\n\n\n\n\n\n\n                      YOU ARE A GENIUS! LEVEL PASSED!" << endl;
			cout << "                      C O N G R A T U L A T I O N S !\n\n\n\n\n\n\n\n" << endl;
			levelnum++;
			difficulty++;
			currlevel = levelnum;
		}
		else if(input != quitgame)
		{
			cout << "\n\n\n\n\n\n\n\n                      WRONG GUESS! level failed," << endl;
			cout << "                      T  R  Y - A  G  A  I  N  !\n\n\n\n\n\n\n\n" << endl;
			currlevel = levelnum;
			gameplay(levelnum);
		}
	}
}

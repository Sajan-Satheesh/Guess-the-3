#pragma once
#include <iostream>
#include <stdlib.h>
#include "Title_Screen.h"
#include "Gameplay.h"

using namespace std;

int main() {
	Title_Screen Newgame;
	Newgame.Main_Heading();
	Newgame.Main_Options();
	Newgame.~Title_Screen();
}
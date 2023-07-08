#include <iostream>
#include "Game_Pronichev.h"




int main()
{
	int kol, k = 0;
	std::cin >> kol;
	Game_Pronichev Igra(kol);
	Igra.phase1();
	

	Igra.save_game("save.txt");
	Igra.load("save.txt");
}
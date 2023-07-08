#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Squar.h"
#include "Circle_in_square.h"



int main()
{
	int ch;
	double x, y, rad, st;
	while (true)
	{
		std::cin >> ch;
		if (ch==1)
		{
			Squar alf(2, 2, 2);
			Squar ar(3, 3, 3);
			std::cout << '\n' << '\n' << '\n' << '\n';
			Circle cir(1, 5, 2);
			Circle c(2, 3, 3);
			std::cout << '\n' << '\n' << '\n' << '\n';
			Circle_in_square CIR(3, 2, 1, 5);
			std::cout << '\n' << '\n' << '\n' << '\n';
		}
		else if (ch==2)
		{
			std::cin >> x >> y >> rad >> st;
			Circle_in_square CIR(x, y, rad, st);
			CIR.cq();
			CIR.SS();
		}
	}
	
	return 0;
}
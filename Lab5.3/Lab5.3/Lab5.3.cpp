#include <iostream>
#include "matrix.h"


int main()
{
	matrix matr1,matr2,matr3;
	matr1.mat_null(3); matr2.mat_null(3); matr3.mat_null(3);
	int s,chose=0,k;
	while (true)
	{
		std::cout << "1 input matrix first" << '\n' << "2 output matrix first" << '\n' << "3 sum matrix first and second" << '\n' << "4 minus matrix first and second" << '\n' << "5 mult matrix -1" << '\n' << "6 muult matrix for number" << '\n'<<"7 mult matrix for matrix"<<'\n';
		std::cin >> chose;
		if (chose == 1)
		{
			system("cls");
			std::cout << "Input size matrix:" << '\n';
			std::cin >> s;
			matr1.input(s);
		}
		else if (chose == 2)
		{
			system("cls");
			matr1.output();
		}
		else if (chose == 3)
		{
			system("cls");
			std::cout << "Input size matrix:" << '\n';
			std::cin >> s;
			matr2.input(s);
			matr1 + matr2;
		}
		else if (chose == 4)
		{
			system("cls");
			std::cout << "Input size matrix:" << '\n';
			std::cin >> s;
			matr2.input(s);
			matr1 -= matr2;
		}
		else if (chose == 5)
		{
			system("cls");
			-matr1;
		}
		else if (chose == 6)
		{
			system("cls");
			std::cout << "Input size number:" << '\n';
			std::cin >> k;
			matr1 *= k;
		}
		else if (chose == 7)
		{
			system("cls");
			std::cout << "Input size matrix:" << '\n';
			std::cin >> s;
			matr2.input(s);
			matr1 *= matr2;

		}
		else if (chose == 8)
		{
			return 0;
		}
	}
	
}
#include <iostream>
#include"Matrix.h"



int main()
{
	int size_coln, size_rows, chose, s;
	matrix matr1, matr2, matr3;
	double num;
	int ch;

	while (true)
	{
		std::cout << "1 input matrix" << '\n' << "2 output matrix" << '\n' << "3 get element matrix" << '\n' << "4 get sum diagonal" << '\n' << "5 get quantity of columns" << '\n' << "6 get quantity of rows" << '\n' << "7 sum matrix" << '\n' << "8 mult matrix by number" << '\n' << "9 mult matrix by matrix" << '\n' << "10 seach matrix detarmination" << '\n';
		std::cin >> chose;
		if (chose == 1)
		{
			system("cls");
			std::cout << "Input size rows and columns" << '\n';
			std::cin >> size_rows >> size_coln;
			matr1.input(size_rows, size_coln);
		}
		else if (chose == 2)
		{
			system("cls");
			matr1.output();
		}
		else if (chose == 3)
		{
			system("cls");
			std::cout << "Whats element u need?" << '\n';
			std::cin >> size_rows >> size_coln;
			size_rows -= 1; size_coln -= 1;
			std::cout << matr1.get_elem(size_rows, size_coln) << '\n';
		}
		else if (chose == 4)
		{
			system("cls");
			std::cout << matr1.trace() << '\n';
		}
		else if (chose == 5)
		{
			system("cls");
			std::cout << matr1.get_coln() << '\n';
		}
		else if (chose == 6)
		{
			system("cls");
			std::cout << matr1.get_rows() << '\n';
		}
		else if (chose == 7)
		{
			system("cls");
			std::cout << "select matrix(1) or array(2)";
			std::cin >> ch;
			if (ch == 1)
			{
				std::cout << "Input second matrix";
				std::cin >> size_rows >> size_coln;
				matr2.input(size_rows, size_coln);
				matr1.sum(matr2);
			}
			else
			{
				std::cout << "Input second matrix";
				std::cin >> size_rows >> size_coln;
				double* arr = new double[size_rows * size_coln];
				for (int i = 0; i < size_coln * size_rows; i++) std::cin >> arr[i];
				matr1.sum(arr);
				delete[] arr;
			}
		}
		else if (chose == 8)
		{
			system("cls");
			std::cout << "Input mult number" << '\n';
			std::cin >> num;
			matr1.mult_number(num);
		}
		else if (chose == 9)
		{
			system("cls");
			std::cout << "select matrix(1) or array(2)";
			std::cin >> ch;
			if (ch == 1)
			{
				system("cls");
				std::cout << "Input second matrix for mult:" << '\n';
				std::cin >> size_rows >> size_coln;
				matr3.input(size_rows, size_coln);
				matr1.mult_matrix(matr3);
				matr1.output();
			}
			else
			{
				system("cls");
				std::cout << "Input second matrix for mult:" << '\n';
				std::cin >> size_rows >> size_coln;
				double* arr = new double[size_rows * size_coln];
				for (int i = 0; i < size_coln * size_rows; i++) std::cin >> arr[i];
				matr1.mult_matrix(arr, size_rows, size_coln);
				matr1.output();
				delete[] arr;
			}
			
		}
		else if (chose == 10)
		{
			system("cls");
			std::cout << "Input squr matrix" << '\n' << "Input size matrix:" << '\n';
			std::cin >> s;
			matr1.input(s);

			std::cout << "deta: " << matr1.det(s) << '\n';

		}
	}
}
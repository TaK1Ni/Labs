#include <iostream>
#include <cfloat>
int main()
{
	unsigned int alfa;
	unsigned short beta;
	alfa = 0;
	beta = 0;
	alfa = alfa - 1;
	beta = beta - 1;
	int a, c = 0, t = 0, count = 0;
	int chos, zad5, zadb5, d, k, a1, b1, a4, b4;
	bool danet;
	double c1, zadc5, x, bx, ax;
	char slovo;
	std::cin >> chos;
	if (chos == 1)
	{
		std::cout << "Pronichev Nikita Vladimirovich, 221-351";
		system("pause");
	}
	if (chos == 2)
	{
		std::cout << "min int = " << int(0b10000000000000000000000000000000) << " max int = " << (-1) * int(0b10000000000000000000000000000000) - 1 << "size of int = " << sizeof(int) << '\n';
		std::cout << "min unsigned int = 0 " << "max unsigned int = " << alfa << " size of unsigned int = " << sizeof(unsigned int) << '\n';
		std::cout << "min short = " << SHRT_MIN << " max short = " << SHRT_MAX << " size of short = " << sizeof(short) << '\n';
		std::cout << "min unsigned short = 0 " << " max unsigned short = " << beta << " size of unsigned short = " << sizeof(unsigned short) << '\n';
		std::cout << "min long = " << LONG_MIN << " max long = " << LONG_MAX << " size of long = " << sizeof(long) << '\n';
		std::cout << "min long long = " << LLONG_MIN << " max long long = " << LLONG_MAX << " size of long long = " << sizeof(long long) << '\n';
		std::cout << "min double = " << -1 * DBL_MAX << " max double = " << DBL_MAX << " size of double = " << sizeof(double) << '\n';
		std::cout << "min char = " << CHAR_MIN << " max char = " << CHAR_MAX << " size of long = " << sizeof(char) << '\n';
		std::cout << "min bool = " << bool(0) << " max bool = " << bool(1) << " size of bool = " << sizeof(char);
		system("pause");
	}
	if (chos == 3)
	{
		std::cin >> a;
		k = a;
		while (a > 0)
		{
			c = c + (pow(10, t)) * (a % 2);
			a = a / 2;
			t++;
		}
		d = c;
		while (d > 0)
		{
			d = d / 10;
			count++;
		}
		for (int i = 0; i < 16 - count; i++)
		{
			std::cout << '0';
		}
		std::cout << c << '\n';
		a = k;
		std::cout << std::hex << a << '\n';
		a1 = k;
		std::cout << "bool " << a1 << '\n';
		c1 = k;
		std::cout << "double " << c1 << '\n';
		b1 = k;
		std::cout << "char " << b1;
		system("pause");
	}
	if (chos == 4)
	{
		std::cout << "Input cof a*x=b:\n";
		std::cin >> a4 >> b4;

		std::cout << a4 << " * " << "x = " << b4 << '\n';
		std::cout << "x = " << b4 << "/" << a4 << '\n';
		x = double(b4) / double(a4);
		std::cout << "x = " << x << '\n';
		system("pause");
	}
	if (chos == 5)
	{
		int at, bt;
		double c7;
		std::cin >> at >> bt;
		c7 = double(at + bt) / 2;
		std::cout << c7;
		system("pause");
	}
	return 0;
}

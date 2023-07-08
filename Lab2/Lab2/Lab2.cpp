long double facktorial(int b)
{
	long double d = 1;
	for (int i = 1; i <= b; i++)
	{
		d = d * i;
	}
	return d;
}



int main()
{
	system("cls");
	int a, b, c = 0;
	double x, sm = 0, count = 0;
	double binom;
	char stop[1024];
	std::cout << "Select actions:\n";
	std::cout << "1-Numerical triangle\n";
	std::cout << "2-Binomial coefficients\n";
	std::cout << "3-Arithmetic mean\n";
	std::cout << "4-Close\n";
	std::cout << "\n";

	while (true)
	{

		b = 0;
		std::cin >> a;
		if (a == 1)
		{
			system("cls");
			std::cout << "1-Numerical triangle\n";
			std::cout << "Input number:";
			std::cin >> b;
			std::cout << "\n";
			for (int i = 0; i < b + 1; i++)
			{
				for (int j = 0; j < i + 1; j++)
					std::cout << j;
				std::cout << '\n';
			}
			system("pause");
			return 0;
		}
		else if (a == 2)
		{

			/*
			C_n^k = n!/(k! (n-k)!) = (1*2*3*..*n)/(1*2*..*k * 1*2*..*(n-k-1)*(n-k))

			C_n^(k+1) = n!/((k+1)! (n-(k+1))!) = (1*2*3*..*n)/(1*2*..*k*(k+1) * 1*2*..*(n-(k+1))) = C_n^k*(n-k)/(k+1)

			C_n^0 = 1

			k=0,1,...(n or (n-1))
			*/
			system("cls");
			std::cout << "2-Binomial coefficients\n";
			std::cout << "Input number:";
			std::cin >> b;
			std::cout << "\n";
			for (int k = 0; k < b + 1; k++)
			{
				std::cout << facktorial(b) / ((facktorial(k)) * facktorial(b - k)) << ' ';
			}
			system("pause");
			return 0;
		}
		else if (a == 3)
		{
			system("cls");
			std::cout << "3-Arithmetic mean\n";
			std::cout << "\n";
			while (true)
			{
				std::cout << "If you want stop input '-':\n";
				std::cout << "Input numbers:\n";
				std::cin >> stop;
				if (*stop != '-')
				{
					b = atoi(stop);
					sm = sm + b;
					count++;
					system("cls");
					for (int i = 0; i < 256; i++)
					{
						stop[i] = '\0';
					}
				}
				else if (count == 0)
				{
					system("cls");
					std::cout << "Nothing" << '\n';
					system("pause");
					break;
				}
				else
				{
					system("cls");
					x = sm / count;
					std::cout << "Arithmetic mean = " << x << '\n';
					system("pause");
					break;
				}

			}
			return 0;


		}
		else if (a == 4)
		{
			system("cls");
			break;
		}
		else
		{
			continue;
		}
	}
}


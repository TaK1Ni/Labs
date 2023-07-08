#include <iostream>

int* input(int* arr, int* k)
{
	std::cin >> *k;
	delete[] arr;
	int* masiv = new int[*k];
	for (int i = 0; i < *k; i++)
	{
		std::cin >> masiv[i];
	}
	return masiv;
}

void output(int* arr, int* k)
{
	for (int i = 0; i < *k; i++)
	{
		std::cout << arr[i]<<" ";
	}
}

int* sort(int* arr, int* k)
{
	int num,cont,a,chet,sum,dat;
	int* bufs = new int[*k];
	int* mass = new int[*k];
	int* fin = new int[*k];
	for (int i = 0; i < *k; i++)
	{
		num = arr[i];
		cont = 0; 
		sum = 0;
		while (num > 0) 
		{
			num /= 10; cont++; 
		}
		int* buf1 = new int[cont*2];
		num = arr[i];
		chet = cont;
		while (num > 0)
		{
			a = num % 10;
			buf1[cont] = a;
			num /= 10;
			cont--;
		}
		for (int j = 0; j < chet; j++)
		{
			if ((j+1) % 2==0)
			{
				sum += buf1[j+1];
			}
		}
		bufs[i] = sum;
		mass[i] = bufs[i];
	}
	for (int i = 0; i < *k - 1; i++)
	{
		for (int j = 0; j < *k - 1; j++)
		{
			if (bufs[j] > bufs[j + 1])
			{
				dat = bufs[j];
				bufs[j] = bufs[j + 1];
				bufs[j + 1] = dat;
			}

		}
	}
	for (int i = 0; i < *k; i++)
	{
		for (int j = 0; j < *k; j++)
		{
			if (bufs[i] == mass[j])
			{
				fin[i] = arr[j];
			}
		}
	}
	return fin;
}

int* sort2(int* arr, int* k)
{
	int dat;
	
	for (int i = 0; i < *k - 1; i++)
	{
		for (int j = 0; j < *k - 1; j++)
		{
			if (arr[j]%10 > arr[j + 1]%10)
			{
				dat = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = dat;
			}
		}
	}
	return arr;
}


int main()
{
	int a, n=1;
	int* k;
	k = &n;
	std::cout << "vedi razmer dla raboti s massivom: " << '\n';
	int *arr = new int[n];
	arr = input(arr, k);
	while (true)
	{
		std::cout << '\n';
		std::cout << "1 - input massiv" << '\n';
		std::cout << "2 - output massiv" << '\n';
		std::cout << "3 - sort first" << '\n';
		std::cout << "4 - sort second" << '\n';
		std::cout << "5 - exit"<<'\n';
		std::cin >> a;
		if (a == 1)
		{
			system("cls");
			std::cout <<"input length: "<<'\n';
			arr=input(arr, k);
		}
		else if (a == 2)
		{
			output(arr, k);
		}
		else if (a == 3)
		{
			arr=sort(arr,k);
		}
		else if (a == 4)
		{
			arr=sort2(arr,k);
		}
		else if (a == 5)
		{
			break;
		}
	}
	return 0;
}

#include <iostream>


void sortirov1(int* a)
{
	int buf;
	for (int i = 0; i < 999; i++)
	{
		for (int j = 0; j < 999; j++)
		{
			if (a[j] > a[j + 1])
			{
				buf = a[j];
				a[j] = a[j + 1];
				a[j + 1] = buf;
			}

		}
	}
	//return a;
}

char* sort2(char* arr)
{
	char fin[1000];
	int pos[26],k = 0;;
	char alf [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for (int i = 0; i < 26; i++)
	{
		pos[i] = 0;
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[i]==alf[j])
			{
				pos[j]++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < pos[i]; j++)
		{
			arr[k] = alf[i];
			k++;
		}
	}
	return arr;
}


void sort3(int* gamma, int fs, int end, int mid)
{
	int i, j, k, c[5];
	i = fs;
	k = fs;
	j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (gamma[i] < gamma[j]) 
		{
			c[k] = gamma[i];
			k++;
			i++;
		}
		else
		{
			c[k] = gamma[j];
			k++;
			j++;
		}
	}
	while (i <= mid) 
	{
		c[k] = gamma[i];
		k++;
		i++;
	}
	while (j <= end) 
	{
		c[k] = gamma[j];
		k++;
		j++;
	}
	for (int i = fs; i < k; i++) 
	{
		gamma[i] = c[i];
	}
}

void recursort(int* gamma, int fs, int end)
{
	int mid;
	if (fs < end)
	{
		//��������� ������ ���������� � ������������ ����������, ��������� ���������� ��������
		mid = (fs + end) / 2;
		recursort(gamma, fs, mid);
		recursort(gamma, mid + 1, end);
		sort3(gamma, fs, end, mid);
	}
}

int main()
{
	int a[1000], b;
	char arr[1000];
	int kol;
	int gamma[5];
	std::cout << "Chose 1 or 2 or 3:"<<'\n';
	std::cin >> b;
	if (b==1)
	{
		for (int i = 0; i < 1000; i++)
		{
			std::cin >> a[i];
		}
		sortirov1(a);
		for (int i = 0; i < 1000; i++)
		{
			std::cout << a[i] << " ";
		}
	}
	else if (b==2)
	{
		for (int i = 0; i < 5; i++)
		{
			std::cin >> arr[i];
		}
		sort2(arr);
		for (int i = 0; i < 5; i++)
		{
			std::cout << arr[i];
		}
	}
	else if (b==3)
	{
		for (int i = 0; i < 5; i++)
		{
			std::cin >> gamma[i];
		}
		recursort(gamma, 0, 4);
		for (int i = 0; i < 5; i++)
		{
			std::cout << gamma[i];
		}
	}
	else
	{
		return 0;
	}
}
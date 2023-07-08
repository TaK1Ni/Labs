#include <iostream>
#include <stdio.h>
#include <cstring>


void input_first(char* text)
{
	char arr[256];
	std::cin >> arr;
	for (int i = 0; i < 256; i++)
	{
		text[i] = arr[i];
	}
	
}

void gtln(char* text)
{
	char arr[256];
	std::cin.getline(arr, 256, ';');
	for (int i = 0; i < 256; i++)
	{
		text[i] = arr[i];
	}
}

void scan(char* text)
{
	char arr[256];
	scanf_s("%s", &arr);
	for (int i = 0; i < 256; i++)
	{
		text[i] = arr[i];
	}
}

bool palidrom(char* text)
{
	
	for (int i = 0,j=strlen(text)-1; i < j; i++, j--)
	{
		while (text[i]==' ')
		{
			i++;
		}
		while(text[j]==' ')
		{
			j--;
		}
		if (text[i]!=text[j])
		{
			return false;
		}
	}
	return true;
}

int poisk(char* text)
{
	char strpart[255];
	int a,c=0;
	std::cin >> strpart;
	a = strlen(strpart);
	for (int i = 0; i < 256-a; i++)
	{
		c = 0;
		if (strpart[0]==text[i])
		{
			for (int j = 0; j < a; j++)
			{
				if (strpart[j]!=text[i+j])
				{
					break;
				}
				c++;
			}
		}
		if (c==a)
		{
			std::cout << i<<" ";
		}
	}
	return 0;
}

void chiphr(char* text)
{
	char asic;
	int key;
	std::cin >> key;
	for (int i = 0; text[i] != '\0'; ++i) {
		asic = text[i];
		if (asic >= 'a' && asic <= 'z') {
			asic = asic + key;
			if (asic > 'z') {
				asic = asic - 'z' + 'a' - 1;
			}
			text[i] = asic;
		}
	}
	std::cout << text;

}

void opr(char* text)
{
	int flag = 1,k=0;
	char a=34,b=39,c=171,d=187;
	char buf[256];
	for (int i = 0; i < 256; i++)
	{
		buf[i] = '\0';
	}
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == a || text[i] == b || text[i] == c|| text[i] == d)
		{
			flag *= -1;
			continue;
		}
		if (flag==-1)
		{
			buf[k] = text[i];
			k++;
		}
		if (flag==1)
		{
			if (buf!=NULL)
			{
				std::cout << buf<<" ";
			}
			for (int i = 0; i < 256; i++)
			{
				buf[i] = '\0';
			}
			k = 0;
		}
	}
	for (int i = 0; buf[i] != '\0'; i++)
	{
		std::cout << buf[i];
	}
}





int main()
{
	char text[256];
	std::cin.getline(text, 256,'\n');
	int a;
	std::cout << "Choose:" << '\n';
	std::cin >> a;
	if (a==1)
	{
		input_first(text);
	}
	else if (a==2)
	{
		gtln(text);
	}
	else if (a == 3)
	{
		scan(text);
	}
	else if (a==4)
	{
		if (palidrom(text))
		{
			std::cout << "Yes";
		}
		else
		{
			std::cout << "No";
		}
	}
	else if (a==5)
	{
		poisk(text); 
	}
	else if (a==6)
	{
		chiphr(text);
	}
	else if (a==7)
	{
		opr(text);
	}
}

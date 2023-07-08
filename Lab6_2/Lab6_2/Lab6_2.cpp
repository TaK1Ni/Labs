#include <iostream>
#include <deque>

bool palidrom(char* arr)
{
	std::deque <char> dq;
	for (int i = 0; arr[i]!='\0'; i++)
	{
		dq.push_back(arr[i]);
	}
	if (strlen(arr)<=1)
	{
		return false;
	}
	if (strlen(arr) % 2 == 0)
	{
		for (int i = 0; i < strlen(arr)/2; i++)
		{
			if (dq.back() == dq.front())
			{
				dq.pop_front();
				dq.pop_back();
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else if (strlen(arr) % 2 == 1)
	{
		for (int i = 0; i < (strlen(arr) - 1) / 2; i++)
		{
			if (dq.back() == dq.front())
			{
				dq.pop_front();
				dq.pop_back();
			}
			else
			{
				return false;
			}
		}
		return true;
	}
}


struct cordin
{
	double x;
	double y;
};


double rotate(cordin A, cordin B, cordin C)
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

void sortirov(cordin* cord, std::deque<int>& P)
{
	int buf;
	for (int i = 2, j = i; i < P.size(); i++)
	{
		while ((j > 1) && (rotate(cord[P[0]], cord[P[j - 1]], cord[P[j]]) < 0))
		{
			buf = P[j];
			P[j] = P[j - 1];
			P[j - 1] = buf;
			j--;
		}
	}
}

void grek(cordin* cord,int n)
{
	int mn = 0;
	std::deque<int> P, S;

	for (int i = 1; i < n; i++)
	{
		if (cord[mn].x> cord[i].x)
		{
			mn = i;
		}
	}

	P.push_back(mn);

	for (int i = 0; i < n; i++)
	{
		if (i != mn)
		{
			P.push_back(i);
		}
	}

	sortirov(cord, P);
	S.push_back(P[0]);
	S.push_back(P[1]);

	for (int i = 2; i < P.size(); i++) 
	{
		while (rotate(cord[S[S.size() - 2]], cord[S[S.size() - 1]], cord[P[i]]) < 0)
		{
			S.pop_back();
		}
		S.push_back(P[i]);
	}

	for (auto x : S) 
	{
		std::cout << cord[x].x << "; " << cord[x].y << '\n';
	}
}


int main()
{
	char arr[1024];
	int ch,n;
	cordin* cord;
	double x, y;

	while (true)
	{
		std::cin >> ch;

		if (ch==1)
		{
			std::cin.getline(arr, 1024, ';');
			if (palidrom(arr))
			{
				std::cout << "YES";
			}
			else
			{
				std::cout << "NO";
			}
		}
		else if (ch==2)
		{
			std::cout << "Input the quantity dot: ";
			std::cin >> n;

			cord = new cordin[n];

			for (int i = 0; i < n; i++)
			{
				std::cin >> x >> y;
				cord[i].x = x;
				cord[i].y = y;
			}
			grek(cord, n);
		}
		else if (ch==3)
		{
			break;
		}
	}
		
}
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

int	main()
{
	std::list <std::pair<int, std::string>> Sp;
	std::vector <int> vr;
	int gr;
	std::string sn;
	while (true)
	{
		std::cout << "Input Groub and Surname:" << '\n';
		std::cin >> gr;
		if (gr==0)
		{
			break;
		}
		std::cin >> sn;
		Sp.push_back(std::pair<int, std::string>(gr, sn));
		vr.push_back(gr);
	}

	std::cout << "Input Groub:" << '\n';
	
	for (int i = 0; i < vr.size(); i++)
	{
		gr = vr.front();
		for (auto i : Sp)
		{
			if (gr == i.first)
			{
				std::cout << i.first << " " << i.second << '\n';
			}

		}
		for (int i = 0; i < vr.size(); i++)
		{
			vr.erase(remove(vr.begin(), vr.end(), gr),vr.end());//воспользовался лайф хаком  идиома erase-remove прикольная штука 
		}
	}
}

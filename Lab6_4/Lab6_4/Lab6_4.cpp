#include <iostream>
#include <set>
#include <string>
#include <vector>

int main()
{
	std::set <std::string> NM;
	std::vector<std::pair<std::string,int>> st;
	int SC, flag;
	std::string str;
	while (true)
	{
		flag = 0;
		
		std::cout << "Input Name and Score:"<<'\n';
		std::cin >> str >> SC;
		
		if (SC==-1) break;

		flag = NM.size();
		NM.insert(str);
		
		if (NM.size() > flag) st.emplace_back(std::pair<std::string, int>(str, SC));
	}

	for (auto i : st)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
}
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct Person
{
	string Surname;
	string Name;
	int Age;
};


template <typename T>
int razdelen(vector<T>& object, int l, int r, int ch = 0)
{
	int index = l + (r - l) / 2;
	int left = l, right = r;
	auto value = object[index];
	while (left <= right)
	{
		while (value > object[left])
		{
			left++;
		}
		while (value < object[right])
		{
			right--;
		}
		if (left <= right)
		{
			auto temp = object[left];
			object[left] = object[right];
			object[right] = temp;
			left++;
			right--;
		}

	}
	return left;
}

template<typename T>
void Quicksort(vector<T>& object, int l, int r)
{
	if (l < r)
	{
		int index = razdelen(object, l, r);
		Quicksort(object, l, index - 1);
		Quicksort(object, index, r);
	}
}


template <typename T1>
void inputQ(vector<T1>& object)
{
	T1 a;
	std::cin >> a;
	while (a == -1 or a == '-')	//ctrl+z   to stop input
	{
		object.push_back(a);
	}
	Quicksort(object, 0, (object.size() - 1))
	for (auto i : object)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}


void input(vector <Person>& vec_pers)
{
	Person chel;
	string name, surname;
	int age;
	while (true)
	{
		std::cin >> age;
		if (age == -1)
		{
			break;
		}
		std::cin >> surname >> name;
		chel.Age = age;
		chel.Name = name;
		chel.Surname = surname;
		vec_pers.push_back(chel);
		std::cout << "New" << '\n';
	}

}

int main()
{
	int choise, par;

	vector <Person> vector_pers, buf_vec_pers;
	string Surname, Name;
	int Age;

	Person da;

	vector <int> Ages;
	vector <string> Names, Surnames;

	vector <double> dobl;
	vector <int> integer;
	vector <char> ch;

	while (true)
	{
		std::cout << "0 - Exit" << '\n' << "1 - Sorting numbers with a dot " << '\n' << "2 - Sorting numbers without a dot" << '\n' << "3 - Sorting letters" << '\n' << "4 - Input Surname,Name,Age" << '\n' << "5 - Sorting struct of Age" << '\n' << "6 - Sorting struct of Name" << '\n' << "7 - Sorting struct of Surname" << '\n';
		std::cin >> choise;
		if (choise == 1)
		{
			inputQ(dobl);
		}
		else if (choise == 2)
		{
			inputQ(integer);
		}
		else if (choise == 3)
		{
			inputQ(ch);
		}
		else if (choise == 4)
		{
			while (true)
			{
				std::cin >> Name >> Surname >> Age;
				if (Age == -1)
				{
					break;
				}
				da.Name = Name;
				da.Surname = Surname;
				da.Age = Age;
				vector_pers.push_back(da);
			}
		}
		if (choise == 5)
		{
			buf_vec_pers = vector_pers;
			for (int i = 0; i < vector_pers.size(); i++) Ages.push_back(vector_pers[i].Age);
			Quicksort(Ages, 0, (Ages.size() - 1));
			for (int i = 0; i < Ages.size(); i++) 
			{
				for (int j = 0; j < buf_vec_pers.size(); j++) 
				{
					if (buf_vec_pers[j].Age == Ages[i]) 
					{
						std::cout << buf_vec_pers[j].Name << " " << buf_vec_pers[j].Surname << " " << vector_pers[j].Age << std::endl;
						buf_vec_pers[j].Age = -1;
					}
				}
			}
		}
		if (choise == 6) {
			buf_vec_pers = vector_pers;
			for (int i = 0; i < vector_pers.size(); i++) Names.push_back(vector_pers[i].Name);
			Quicksort(Names, 0, (Names.size() - 1));
			for (int i = 0; i < Names.size(); i++)
			{
				for (int j = 0; j < buf_vec_pers.size(); j++)
				{
					if (buf_vec_pers[j].Name == Names[i])
					{
						std::cout << buf_vec_pers[j].Name << " " << buf_vec_pers[j].Surname << " " << vector_pers[j].Age << std::endl;
						buf_vec_pers[j].Name = -1;
					}
				}
			}
		}
		if (choise == 7)
		{
			buf_vec_pers = vector_pers;
			for (int i = 0; i < vector_pers.size(); i++) Surnames.push_back(vector_pers[i].Surname);
			Quicksort(Surnames, 0, (Surnames.size() - 1));
			for (int i = 0; i < Surnames.size(); i++)
			{
				for (int j = 0; j < buf_vec_pers.size(); j++)
				{
					if (buf_vec_pers[j].Surname == Surnames[i])
					{
						std::cout << buf_vec_pers[j].Name << " " << buf_vec_pers[j].Surname << " " << vector_pers[j].Age << std::endl;
						buf_vec_pers[j].Surname = -1;
					}
				}
			}
		}
		else if (choise == 0)
		{
			break;
		}
	}
}
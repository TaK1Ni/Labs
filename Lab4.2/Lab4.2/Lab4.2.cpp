#include <iostream>
#include <string>
#include <fstream> 


std::string file_format(const std::string file_path_full)
{
	int num;
	std::string arr;
	num = file_path_full.rfind('.');
	arr.assign(file_path_full, num, -1);

	return arr;
}

std::string file_name(const std::string file_path_full)
{
	int num;
	char a = 92;
	std::string arr;
	num = file_path_full.rfind(a);
	arr.assign(file_path_full, num+1, -1);

	return arr;
}

std::string file_path(const std::string file_path_full)
{
	int num;
	char a = 92;
	std::string arr;
	num = file_path_full.rfind(a);
	arr.assign(file_path_full,0, num);

	return arr;
}

std::string file_disk(const std::string file_path_full)
{
	int num;
	std::string arr;
	num = file_path_full.find(':');
	arr.assign(file_path_full, 0, num);
	return arr;
}
bool file_rename(std::string * file_path_full)
{
	int num1,num2;
	std::string arr, renm;
	arr = *file_path_full;
	num1 = arr.rfind('\\');
	num2 = arr.rfind('.');
	std::cin >> renm;
	arr.replace(num1+1, num2-num1-1, renm);
	file_path_full = &arr;
	std::cout << arr;
	return true;
}

// C:\Users\NiKiTa\source\repos\Lab4.2\Lab4.2\Lab4.2.cpp

void file_copy(const std::string file_path_full)
{
	std::string arr1, arr2, arrc;
	std::fstream file_path_full_copy, fil;
	int num, num1, num2;
	char buf[10000];
	
	num = file_path_full.rfind('.');
	num1 = file_path_full.rfind('\\');
	num2 = file_path_full.rfind('.');
	
	arr1.assign(file_path_full, num1 + 1, num2 - num1 - 1);
	arr2.assign(file_path_full, num, -1);
	
	arrc = arr1;
	
	arrc.append("_copy");
	
	file_path_full_copy.open(arrc + arr2);
	fil.open(arr1 + arr2);
	
	while (!fil.eof())
	{
		fil.getline(buf, sizeof(buf));
		file_path_full_copy << buf << '\n';
	}
	
	file_path_full_copy.close();
	fil.close();

}

int main()
{
	int a = 0;
	std::string file_path_full;
	while (true)
	{
		std::cout <<'\n' << "1. Input" << '\n' << "2. Take type name" << '\n' << "3. Take name" << '\n' << "4. Take position" << '\n' << "5. Take name disk" << '\n' << "6. Take full position on disk and rename" << '\n' << "7. Make copy" << '\n';
		std::cout << "Choose function:";
		std::cin >> a;
		if (a==1)
		{
			std::cin >> file_path_full;
			std::cout << '\n' << file_path_full;
		}
		else if (a ==2)
		{
			std::cout << file_format(file_path_full);
		}
		else if (a == 3)
		{
			std::cout << file_name(file_path_full);
		}
		else if (a == 4 )
		{
			std::cout <<file_path(file_path_full);
		}
		else if (a == 5)
		{
			std::cout <<file_disk(file_path_full);
		}
		else if (a == 6)
		{
			std::cout << file_rename(&file_path_full);
		}
		else if (a==7)
		{
			file_copy(file_path_full);
		}
		else if (a == 8)
		{
			break;
		}
	}







}
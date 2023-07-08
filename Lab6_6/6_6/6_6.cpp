#include <iostream>
#include <map>
#include <string>
#include <sstream>

using std::string;
using std::map;
using std::istringstream;


int main()
{
    string txin;
    string line;
    map <string, double> text;
    int sceht = 0;

    std::getline(std::cin, txin);
    istringstream iss(txin);
   
    while (std::getline(iss, line, ' '))
    {
        sceht++;
        if (text.find(line.c_str()) == text.end())
        {
            text.insert(std::pair<string, double>(line.c_str(), 1));
        }
        else
        {
            text[line.c_str()]++;
        }
        //text[txin]++;// добавить поиск от нуля 
    }
    for (auto row : text) 
    {
        std::cout << row.first << ' ' << (row.second / sceht * 100) << '%' << std::endl;
    }
}
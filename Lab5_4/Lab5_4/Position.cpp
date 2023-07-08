#include "Position.h"


Position::Position()
{
	this->x = 0;
	this->y = 0;
	std::cout << "Position()" << '\n';
}
Position::Position(double name_x, double name_y)
{
	this->x = name_x;
	this->y = name_y;
	std::cout << "Position(double name_x, double name_y)" << '\n';
}
Position::~Position()
{
	std::cout << "~Position()" << '\n';
}
void Position::out()
{	
	std::cout << x << ' ' << y;
}
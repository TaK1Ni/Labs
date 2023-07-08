#include "Circle_in_square.h"

Circle_in_square::Circle_in_square()
{
	this->exists = true;
	std::cout << "Circle_in_square()" << '\n';
}

Circle_in_square::Circle_in_square(double name_x, double name_y, double rad, double st):Circle(name_x, name_y,rad), Squar(name_x, name_y,st)
{
	this->x = name_x;
	this->y = name_y;
	this->radius = rad;
	this->storona = st;
	this->exists = true;
	std::cout << "Circle_in_square(double name_x, double name_y, double rad, double st)" << '\n';
}

Circle_in_square::~Circle_in_square()
{
	std::cout << "~Circle_in_square()" << '\n';
}


void Circle_in_square::cq()
{
	std::cout << x << ' ' << y << ' ' << radius << ' ' << storona << ' ' << exists << '\n';
	std::cout << "area of circle " << 3.14 * radius << '\n';
	std::cout << "area of square " << storona * storona << '\n';
	std::cout << "delta area " << (3.14 * radius) - (storona * storona) << '\n';
	std::cout << x << ' ' << y << ' ' << radius << ' ' << storona << ' ' << exists << '\n';
}

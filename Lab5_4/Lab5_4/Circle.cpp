#include "Circle.h"

Circle::Circle()
{
	this->radius = 5;
	std::cout << "Circle()" << '\n';
}

Circle::Circle(double name_x, double name_y, double rad) :Position(name_x, name_y)
{
	this->x = name_x;
	this->y = name_y;
	this->radius = rad;
	std::cout << "Circle(double name_x, double name_y, double rad)" << '\n';
}

Circle::~Circle()
{
	std::cout << "~Circle()" << '\n';
}

void Circle::out()
{
	std::cout << x << ' ' << y << ' ' << radius;
}

void Circle::SC()
{
	std::cout << 3.14 * radius<<'cm3';
}
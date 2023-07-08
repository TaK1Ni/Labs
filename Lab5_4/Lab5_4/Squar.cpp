#include "Squar.h"


Squar::Squar()
{
	this->storona = 5;
	std::cout << "Squar()"<<'\n';
}

Squar::Squar(double name_x, double name_y, double st) :Position(name_x, name_y)
{
	this->storona = st;
	this->x = name_x;
	this->y = name_y;
	std::cout << "Squar(double name_x, double name_y, double st)" << '\n';
}

Squar::~Squar()
{
	std::cout << "~Squar()" << '\n';
}

void Squar::out()
{
	std::cout << x << y;
}

void Squar::SS()
{
	std::cout << storona * storona;
}
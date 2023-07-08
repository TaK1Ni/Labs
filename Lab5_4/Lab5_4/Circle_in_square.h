#pragma once
#include "Circle.h"
#include "Squar.h"

class Circle_in_square: public Circle, public Squar
{
public:
	bool exists;
public:
	Circle_in_square();
	Circle_in_square(double name_x, double name_y, double rad, double st);

	~Circle_in_square();
	void cq();



};


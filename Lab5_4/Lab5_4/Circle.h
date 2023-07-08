#pragma once
#include "Position.h"

class Circle :virtual public Position
{
public:
	double radius;
public:
	Circle();
	Circle(double name_x, double name_y, double rad);
	~Circle();
	void out();
	void SC();
};


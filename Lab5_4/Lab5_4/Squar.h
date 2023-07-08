#pragma once
#include "Position.h"

class Squar :virtual public Position
{
public:
	double storona;
public:
	Squar();
	Squar(double name_x, double name_y, double st);
	~Squar();
	void out();
	void SS();
};


#include <iostream>
#include "matrix.h"

matrix::matrix()
{
	this->s = 0;
	elem = nullptr;
}
void matrix::mat_null(int size)
{
	this->s = size;
	if (elem != nullptr) delete[] elem;
	elem = new double[size * size];
	for (int i = 0; i < s * s; i++) elem[i] = 0;
}

matrix::~matrix()
{
	if (elem != nullptr) delete[] elem;
}


void matrix::input(int size)
{
	int k = 0;
	this->s = size;
	if (elem != nullptr) delete[] elem;
	elem = new double[this->s * this->s];
	for (int i = 1; i < s * s; i++) elem[i] = 0;
	std::cin >> elem[0];
	for (int i = 1; i < s; i++)
	{
		for (int j = 1; j < s; j++)
		{
			if (i==j)
			{
				std::cin >> elem[(i - 1) * s + j];
				std::cin >> elem[i * s + j - 1];
				std::cin >> elem[i * s + j];
				
				
			}
		}
	}
	

}
void matrix::output()
{
	int k = 0;
	for (int i = 0; i < s*s; i++)
	{
		std::cout << elem[i] << " ";
		k++;
		if (k==s)
		{
			std::cout << '\n';
			k = 0;
		}
		
	}
}
void matrix::operator+=(matrix mat2)
{
	for (int i = 0; i < s*s; i++)
		this->elem[i] += mat2.elem[i];
}

void matrix::operator-=(matrix mat2)
{
	for (int i = 0; i < s * s; i++)
		this->elem[i] = this->elem[i] - mat2.elem[i];
}
void matrix::operator-() const
{
	for (int i = 0; i < s*s; i++)
		this->elem[i] = this->elem[i] * (-1);
}



void matrix::rewrite(int s_row, int s_coln, double* mas)
{
	delete[] elem;
	elem = new double[s_row * s_coln];
	this->s = s_row;

	for (int i = 0; i < s_row * s_coln; i++)
	{
		this->elem[i] = mas[i];
	}
}


double matrix::get_elem(int i, int j) const
{
	return elem[i * s + j];
}

void matrix::operator*=(double k) const
{

	int t = 0;
	double* buf = new double[this->s * s* s];

	for (int i = 0; i < this->s * k; i++) buf[i] = 0;

	system("cls");
	for (int i = 0; i < s * s; i++)
	{
		buf[i] = this->elem[i] * k;
	}
	system("cls");
	for (int i = 0; i < this->s *s ; i++)
	{
		std::cout << buf[i] << ' ';
		t++;
		if (t == this->s)
		{
			std::cout << '\n';
			t = 0;
		}
	}
	delete[] buf;
}
void matrix::operator*=(matrix mat2) const
{
	int k = 0;
	double* buf = new double[this->s * mat2.s];

	for (int i = 0; i < this->s * mat2.s; i++) buf[i] = 0;

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < mat2.s; j++)
		{
			for (int k = 0; k < mat2.s; k++)
			{
				buf[i * mat2.s + j] += this->get_elem(i, k) * mat2.elem[k * mat2.s + j];
			}
		}
	}
	system("cls");
	for (int i = 0; i < this->s * mat2.s; i++)
	{
		std::cout << buf[i]<<' ';
		k++;
		if (k== this->s)
		{
			std::cout << '\n';
			k = 0;
		}
	}
	delete[] buf;
}
matrix& operator+(const matrix& lhs, const matrix& rhs) 
{
	matrix res;
	res.mat_null(lhs.s);
	res += lhs;
	res += rhs;
	res.output();
	return res;
}
matrix& operator-(const matrix& lhs, const matrix& rhs)
{
	matrix res;
	res.mat_null(lhs.s);
	res += lhs;
	res -= rhs;
	return res;
}

void matrix::operator>>(int mas)
{
	int k = 0;
	this->s = mas;
	if (elem != nullptr) delete[] elem;
	elem = new double[this->s * this->s];
	for (int i = 1; i < s * s; i++) elem[i] = 0;
	std::cin >> elem[0];
	for (int i = 1; i < s; i++)
	{
		for (int j = 1; j < s; j++)
		{
			if (i == j)
			{
				std::cin >> elem[(i - 1) * s + j];
				std::cin >> elem[i * s + j - 1];
				std::cin >> elem[i * s + j];


			}
		}
	}
}

matrix& operator*(const matrix& lhs, const matrix& rhs)
{
	matrix res;
	res.mat_null(lhs.s);
	lhs*=rhs;
	res = lhs;
	return res;
}
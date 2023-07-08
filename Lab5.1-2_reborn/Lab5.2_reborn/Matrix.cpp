#include "Matrix.h"
#include <iostream>

matrix::matrix()
{
	elem = nullptr;
	this->rows = 0;
	this->coln = 0;
}

matrix::matrix(int s)
{
	rows = s; coln = s;
	elem = new double[rows * coln];

	for (int i = 0; i < rows * coln; i++) elem[i] = 0;
}



void matrix::input(int size_col, int size_row)
{
	this->rows = size_row;
	this->coln = size_col;

	if (elem != nullptr) delete[] elem;

	elem = new double[rows * coln];

	for (int i = 0; i < rows * coln; i++)
	{
		std::cin >> elem[i];
	}
}


void matrix::input(int size)
{
	this->rows = size;
	this->coln = size;

	if (elem != nullptr) delete[] elem;

	elem = new double[rows * coln];

	for (int i = 0; i < rows * coln; i++)
	{
		std::cin >> elem[i];
	}
}


void matrix::output() const
{
	int j = 0;

	for (int i = 0; i < rows * coln; i++)
	{
		std::cout << elem[i] << " ";
		j++;
		if (j == coln)
		{
			j = 0;
			std::cout << '\n';
		}
	}
}

double matrix::trace() 
{
	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		if (get_elem(i, i) != get_elem(i, rows - i - 1))
		{
			sum += get_elem(i, i);
			sum += get_elem(i, rows - i - 1);
		}
		else if (get_elem(i, i) == get_elem(i, rows - i - 1))
		{
			sum += get_elem(i, i);
		}

	}

	return sum;
}


void matrix::sum(const matrix& matr2)
{
	for (int i = 0; i < matr2.rows * matr2.coln; i++)
	{
		this->elem[i] = this->elem[i] + matr2.elem[i];
	}

}

void matrix::sum(const double* arr)
{
	for (int i = 0; i < rows * coln; i++)
	{
		this->elem[i] = this->elem[i] + arr[i];
	}
}


void matrix::mult_number(double num)
{
	for (int i = 0; i < rows * coln; i++)
	{
		this->elem[i] = this->elem[i] * num;
	}
}

void matrix::rewrite(int s_row, int s_coln, double* mas)
{
	delete[] elem;
	elem = new double[s_row * s_coln];
	this->rows = s_row;
	this->coln = s_coln;

	for (int i = 0; i < s_row * s_coln; i++)
	{
		this->elem[i] = mas[i];
	}
}

void matrix::mult_matrix(const double* arr, int size_rows, int size_coln)
{
	double* buf = new double[this->rows * size_coln];

	for (int i = 0; i < this->rows * size_coln; i++) buf[i] = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < size_coln; j++)
		{
			for (int k = 0; k < size_rows; k++)
			{
				buf[i * size_coln + j] += this->get_elem(i, k) * arr[k * size_coln + j];
			}
		}
	}

	rewrite(this->rows, size_coln, buf);
	delete[] buf;
}


void matrix::mult_matrix(const matrix& matr3)
{
	double* buf = new double[this->rows * matr3.coln];

	for (int i = 0; i < this->rows * matr3.coln; i++) buf[i] = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < matr3.coln; j++)
		{
			for (int k = 0; k < matr3.rows; k++)
			{
				buf[i * matr3.coln + j] += this->get_elem(i, k) * matr3.elem[k * matr3.coln + j];
			}
		}
	}

	rewrite(this->rows, matr3.coln, buf);
	delete[] buf;
}

void matrix::mina(matrix& matr, int id)
{
	int s = this->rows;
	for (int i = 1, k_i = 0; i < s; i++)
	{
		for (int j = 0, k_j = 0; j < s; j++)
		{
			if (j != id)
			{
				matr.elem[k_i * matr.rows + k_j] = this->elem[i * s + j];

				k_j++;
			}
		}
		k_i++;
	}
}

double matrix::det(int& a)
{
	int razm = a;
	double det = 0;
	int s = this->rows;
	int kof = 1;

	if (s == 1)
	{
		det = elem[0];
	}
	else if (s == 2)
	{
		det = elem[0] * elem[3] - elem[1] * elem[2];
	}
	else
	{
		for (int i = 0; i < s; i++)
		{
			int rec = s - 1;
			matrix submat(rec);
			razm++;
			mina(submat, i);
			det = det + kof * this->elem[i] * submat.det(razm);
			kof = -kof;
		}
	}
	return det;
}
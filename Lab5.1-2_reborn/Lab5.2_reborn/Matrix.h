#pragma once
class matrix
{
private:
	int rows, coln;
	double* elem;
	void mina(matrix& matr, int id);
public:


	matrix();
	~matrix() { if (elem != nullptr) delete[] elem; }
	matrix(int size);

	void input(int size_col, int size_row);
	void input(int size);

	void output() const;
	double trace();

	int get_rows() const { return coln; }
	int get_coln() const { return rows; }
	double get_elem(int i, int j){ return elem[i * coln + j]; }
	
	void sum(const matrix& mart2);
	void sum(const double* arr);
	
	void mult_number(double num);

	void mult_matrix(const matrix& mart3);
	void mult_matrix(const double* arr,int size_rows, int size_coln);

	void rewrite(int s_row, int s_coln, double* mas);
	
	double det(int& a);

};
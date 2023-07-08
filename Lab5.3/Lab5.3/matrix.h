#include <iostream>

class matrix
{
private:
	int s;
	double* elem;

public:
	matrix();
	~matrix();
	void input(int size);
	void output();
	
	void mat_null(int size);
	void rewrite(int s_row, int s_coln, double* mas);
	double get_elem(int i, int j) const;
	int get_size() { return s; }
	void operator>>(int mas);

	void operator+=(matrix mat2);
	void operator-=(matrix mat2);
	void operator-() const;
	void operator*=(double k) const;
	void operator*=(matrix mat2) const;

	friend matrix& operator+ (const matrix& lhs, const matrix& rhs);
	friend matrix& operator- (const matrix& lhs, const matrix& rhs);
	friend matrix& operator* (const matrix& lhs, const matrix& rhs);
};


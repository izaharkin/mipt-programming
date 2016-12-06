#ifndef _MATRIX_H_

#define _MATRIX_H_

#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

#define eps 1e-9

using namespace std;

struct size
{
	int m;
	int n;
	size() : n(0), m(0) {}
	size(int _m, int _n) : m(_m), n(_n) { assert(m > 0 && n > 0); }
	size(const size& _sz) : size(_sz.m, _sz.n) {}
	bool operator == (const size& _sz)
	{
		return (m == _sz.m && n == _sz.n);
	}
	friend istream& operator >> (istream& in, size& sz)
	{
		in >> sz.m >> sz.n;
		assert(sz.m > 0 && sz.n > 0);
		return in;
	}
};

template <class T>
class Vector
{
private:
	vector <T> vec;
public:
	Vector() : vec(0) {}

	Vector(const vector<T>& v) : 
	{
		copy(v.begin(), v.end(), vec.begin());
	}

	T& operator [] (const int idx)
	{ 
		return vec[idx]; 
	}

	const T& operator [] (const int idx) const
	{
		return vec[idx];
	}

	void resize(const int new_sz)
	{
		vec.resize(new_sz);
	}
};

template <class T>
class Matrix
{
private:
	size sz;
	vector < Vector<T> > mat;
public:
	Matrix() : sz(), mat() {}

	Matrix(const size& _sz) : sz(_sz) 
	{
		mat.resize(sz.m);
		for (int i = 0; i < sz.m; ++i)
			mat[i].resize(sz.n);
	}

	Matrix(int _m, int _n) : sz(_m, _n) 
	{
		mat.resize(sz.m);
		for (int i = 0; i < sz.m; ++i)
			mat[i].resize(sz.n);
	}

	Matrix(int _m, int _n, T x) : sz(_m, _n)
	{
		mat.resize(sz.m);
		for (int i = 0; i < sz.m; ++i)
			mat[i].resize(sz.n);
		for (int i = 0; i < sz.m; ++i)
			for (int j = 0; j < sz.n; ++j)
				mat[i][j] = x;
	}

	Matrix(const vector< Vector<T> >& m) : mat(m) {}

	Matrix(const Matrix<T>& b) : sz(b.sz) 
	{
		mat.resize(sz.m);
		for (int i = 0; i < sz.m; ++i)
			mat[i].resize(sz.n);

		for (int i = 0; i < sz.m; ++i)
			for (int j = 0; j < sz.n; ++j)
				mat[i][j] = b.mat[i][j];
	}

	size getSize() const;
	size_t getRaws() const;
	size_t getColumns() const;

	void swapRaws(const int, const int);
	void swapColumns(const int, const int);
	Matrix<T> concateMatrix(const Matrix<T>&) const;
	Matrix<T> eraseColumns(const int, const int) const;

	void checkSquare() const;
	T track() const;
	Matrix<T> transp() const;

	Matrix<T> gauss() const;
	Matrix<T> diagonal() const;
	T detTriang() const;
	T det() const;

	Matrix<T> invertMatrix() const;

	Vector<T>& operator [] (const int idx)
	{
		return mat[idx];
	}
	
	const Vector<T>& operator [] (const int idx) const
	{
		return mat[idx];
	}

	friend istream& operator >> <> (istream& in, Matrix <T>& matrix);        // input
	friend ostream& operator << <> (ostream& out, const Matrix <T>& matrix); // output
	void operator += (const Matrix<T>&);            // *this += M
	Matrix<T> operator + (const Matrix<T>&) const;  // *this + M
	void operator -= (const Matrix<T>&);            // *this += M
	Matrix<T> operator - (const Matrix<T>&) const;  // *this + M
	void operator *= (T);                           // *this *= Num
	Matrix<T> operator * (T) const;                 // *this * Num
	Matrix<T> operator * (const Matrix<T>&) const;  // *this * M
	/*
	friend void operator / (const Matrix<T>&, const Matrix<T>&);
	*/
};

template <class T>
Matrix<T> eMat(size_t m)
{
	Matrix<T> E(m, m);

	for (size_t i = 0; i < m; ++i)
		E[i][i] = 1;

	return E;
}

template <class T>
size Matrix <T>::getSize() const
{
	return sz;
}

template <class T>
size_t Matrix <T>::getRaws() const
{
	return sz.m;
}

template <class T>
size_t Matrix <T>::getColumns() const
{
	return sz.n;
}

template <class T>
void Matrix<T>::checkSquare() const
{
	assert(sz.m == sz.n);
}

template <class T>
T Matrix<T>::track() const
{
	checkSquare();
	T tr = 0;

	for (size_t i = 0; i < getRaws(); ++i)
		tr += (*this)[i][i];

	return tr;
}

template <class T>
istream& operator >> (istream& in, Matrix <T>& matrix)
{
	in >> matrix.sz;
	int _m = matrix.sz.m;
	int _n = matrix.sz.n;

	matrix.mat.resize(_m);
	for (int i = 0; i < _m; ++i)
		matrix[i].resize(_n);

	for (int i = 0; i < _m; ++i)
		for (int j = 0; j < _n; ++j)
			in >> matrix.mat[i][j];

	return in;
}

template <class T>
ostream& operator << (ostream& out, const Matrix <T>& matrix)
{
	int _m = matrix.sz.m;
	int _n = matrix.sz.n;

	for (int i = 0; i < _m; ++i)
	{
		for (int j = 0; j < _n; ++j)
			out << matrix.mat[i][j] << ' ';
		out << '\n';
	}

	return out;
}

template <class T>
void Matrix<T>::operator += (const Matrix<T>& b)
{
	assert(getSize() == b.getSize());

	for (size_t i = 0; i < getRaws(); ++i)
		for (size_t j = 0; j < getColumns(); ++j)
			mat[i][j] += b.mat[i][j];
}

template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& b) const
{
	assert(getSize() == b.getSize());

	Matrix c = *this;
	c += b;

	return c;
}

template <class T>
void Matrix<T>::operator -= (const Matrix<T>& b)
{
	assert(getSize() == b.getSize());

	for (size_t i = 0; i < getRaws(); ++i)
		for (size_t j = 0; j < getColumns(); ++j)
			mat[i][j] -= b.mat[i][j];
}

template <class T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& b) const
{
	assert(getSize() == b.getSize());

	Matrix c = *this;
	c -= b;

	return c;
}

template <class T>
void Matrix<T>::operator *= (T k)
{
	for (size_t i = 0; i < getRaws(); ++i)
		for (size_t j = 0; j < getColumns(); ++j)
			mat[i][j] *= k;
}

template <class T>
Matrix<T> Matrix<T>::operator * (T b) const
{
	Matrix c = *this;

	c *= b;

	return c;
}

template <class T>
Matrix<T> Matrix<T>::operator * (const Matrix<T>& b) const
{
	assert(getColumns() == b.getRaws());

	Matrix<T> c(getRaws(), b.getColumns());

	for (size_t i = 0; i < getRaws(); ++i)
		for (size_t j = 0; j < b.getColumns(); ++j)
			for (size_t k = 0; k < getColumns(); ++k)
				c[i][j] += (*this)[i][k] * b[k][j];

	return c;
}

template <class T>
Matrix<T> Matrix<T>::transp() const
{
	Matrix<T> c(getColumns(), getRaws());

	for (size_t i = 0; i < getColumns(); ++i)
		for (size_t j = 0; j < getRaws(); ++j)
			c[i][j] = (*this)[j][i];

	return c;
}

template <class T>
void Matrix<T>::swapRaws(const int i, const int j)
{
	assert(!(i < 0 || j < 0 || i >= sz.m || j >= sz.m));

	for (int k = 0; k < sz.n; ++k)
		swap((*this)[i][k], (*this)[j][k]);
}

template <class T>
void Matrix<T>::swapColumns(const int i, const int j)
{
	assert(!(i < 0 || j < 0 || i >= sz.n || j >= sz.n));

	for (int k = 0; k < sz.m; ++k)
		swap((*this)[k][i], (*this)[k][j]);
}

template <class T>
Matrix<T> Matrix<T>::concateMatrix(const Matrix<T>& b) const
{
	assert(getRaws() == b.getRaws());
	
	Matrix<T> c(getRaws(), getColumns() + b.getColumns());
	
	for (int i = 0; i < sz.m; ++i)
	{
		for (int j = 0; j < sz.n; ++j)
			c[i][j] = (*this)[i][j];
		for (int j = 0; j < b.getColumns(); ++j)
			c[i][sz.n + j] = b[i][j];
	}
	
	return c;
}

// удаление столбцов с index1 по index2
template <class T>
Matrix<T> Matrix<T>::eraseColumns(const int index1, const int index2) const
{
	Matrix<T> c = Matrix<T>(getRaws(), getColumns() - (index2 - index1 + 1));
	
	for (int i = 0; i < getRaws(); ++i)
		for (int j = 0; j < index1; ++j)
			c[i][j] = (*this)[i][j];
	
	for (int i = 0; i < getRaws(); ++i)
		for (int j = index2 + 1; j < getColumns(); ++j)
			c[i][j + index1 - index2 - 1] = (*this)[i][j];
	
	return c;
}

// приведение матрицы к треугольному виду, метод Гаусса  с главным элементом
template <class T>
Matrix<T> Matrix<T>:: gauss() const
{
	int i, j, k;
	int countSwaps = 1;
	Matrix<T> c(*this);

	for (i = 0; i < sz.m; ++i)
	{
		// находим строку с максимальным первым элементом
		int iMax = i;
		for (j = i + 1; j < sz.m; ++j)
			if (abs(c[j][i]) > abs(c[iMax][i]))
				iMax = j;
		if (abs(c[iMax][i]) < eps)
			continue;
		for (k = 0; k < sz.n; ++k)
			swap(c[i][k], c[iMax][k]); // использовать swapRaws()
		countSwaps = -countSwaps * (i != iMax ? 1 : -1);

		//  вычитаем текущую строку из всех остальных
		for (j = i + 1; j < sz.m; ++j)
		{
			double q = -c[j][i] / (1.0 * c[i][i]);
			for (k = sz.n - 1; k >= i; --k)
				c[j][k] += q * c[i][k];
		}
	}
	// умножаем матрицу на -1, если мы сделали  нечётное количество перестановок строк
	// в итоге определитель результирующей матрицы  будет равен определителю начальной матрицы
	return (c * countSwaps);
}

template <class T>
Matrix<T> Matrix<T>::diagonal() const
{
	Matrix<T> c = gauss();

	for (int i = 1; i < c.getRaws(); ++i)
		for (int j = 0; j < i; ++j)
		{
			if ( fabs((double)c[i][i]) < eps )
				return Matrix<T>();
			double q = -c[j][i] / (1.0 * c[i][i]);
			for (int k = c.getColumns() - 1; k >= i; --k)
				c[j][k] += q * c[i][k];
		}

	return c;
}

// обратная матрица, метод Жордана-Гаусса
template <class T>
Matrix<T> Matrix<T>::invertMatrix() const
{
	Matrix<T> E(eMat<T>(getRaws()));
	
	Matrix<T> c = this->concateMatrix(E);

	c = diagonal();
	if (c.getRaws() == 0)
		return Matrix(getRaws(), getRaws(), 0);

	for (int i = 0; i < getRaws(); ++i)
		for (int k = getRaws() + getRaws() - 1; k >= 0; --k)
			c[i][k] /= c[i][i] + .0;

	return c.eraseColumns(0, getRaws() - 1);
}

// triangle matrix determinant
template <class T>
T Matrix<T>::detTriang() const
{
	assert(sz.m == sz.n);

	T x = 1;
	for (int i = 0; i < sz.m; ++i)
		x *= (*this)[i][i];

	return x;
}

// determinant
template <class T>
T Matrix<T>::det() const
{
	Matrix<T> temp = gauss();
	return temp.detTriang();
}

#endif /* _MATRIX_H_ */
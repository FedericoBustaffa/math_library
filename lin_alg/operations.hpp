#ifndef MAT_OPERATIONS_H
#define MAT_OPERATIONS_H

#include <chrono>

#include "matrix.hpp"

template <typename T>
matrix<T> matrix<T>::operator+(T scalar) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] + scalar;
	}

	return res;
}

template <typename T>
matrix<T> operator+(T scalar, const matrix<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	matrix<T> r(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) + scalar;
	}

	return r;
}

template <typename T>
matrix<T> matrix<T>::operator-(T scalar) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] - scalar;
	}

	return res;
}

template <typename T>
matrix<T> operator-(T scalar, const matrix<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	matrix<T> r(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) - scalar;
	}

	return r;
}

template <typename T>
matrix<T> matrix<T>::operator*(T scalar) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] * scalar;
	}

	return res;
}

template <typename T>
matrix<T> operator*(T scalar, const matrix<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	matrix<T> r(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) * scalar;
	}

	return r;
}

template <typename T>
matrix<T> matrix<T>::operator/(T scalar) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] / scalar;
	}

	return res;
}

template <typename T>
matrix<T> operator/(T scalar, const matrix<T> &m)
{
	size_t rows = m.get_rows();
	size_t cols = m.get_cols();
	matrix<T> r(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			r(i, j) = m(i, j) / scalar;
	}

	return r;
}

// somma elemento per elemento
template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> &other) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] + other(i, j);
	}

	return res;
}

// differenza elemento per elemento
template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> &other) const
{
	matrix<T> res(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			res(i, j) = m_matrix[i][j] - other(i, j);
	}

	return res;
}

// prodotto riga per colonna
template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> &other) const
{
	size_t cols = other.get_cols();
	matrix<T> prod(m_rows, cols);

	auto start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			for (size_t k = 0; k < m_cols; k++)
				prod(i, j) += m_matrix[i][k] * other(k, j);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "row x col time: " << duration.count() << " s" << std::endl;

	return prod;
}

template <typename T>
matrix<T> matrix<T>::transpose() const
{
	matrix<T> t(m_cols, m_rows);
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			t(j, i) = m_matrix[i][j];
	}

	return t;
}

#endif
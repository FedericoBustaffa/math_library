#ifndef MAT_UTILITY_H
#define MAT_UTILITY_H

#include "core.hpp"

template <typename T>
matrix<T>::matrix(size_t rows, size_t cols)
	: m_rows(rows), m_cols(cols)
{
	m_matrix = new T *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		m_matrix[i] = new T[cols];
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = 0;
	}
}

template <typename T>
matrix<T>::matrix(const matrix<T> &other)
	: m_rows(other.get_rows()), m_cols(other.get_cols())
{
	m_matrix = new T *[m_rows];
	for (size_t i = 0; i < m_rows; i++)
	{
		m_matrix[i] = new T[m_cols];
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = other(i, j);
	}
}

template <typename T>
void matrix<T>::operator=(const matrix<T> &other)
{
	m_rows = other.get_rows();
	m_cols = other.get_cols();
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = other(i, j);
	}
}

template <typename T>
size_t matrix<T>::get_rows() const
{
	return m_rows;
}

template <typename T>
size_t matrix<T>::get_cols() const
{
	return m_cols;
}

template <typename T>
size_t matrix<T>::size() const
{
	return m_rows * m_cols;
}

template <typename T>
std::pair<size_t, size_t> matrix<T>::shape() const
{
	return std::pair<size_t, size_t>(m_rows, m_cols);
}

template <typename T>
T &matrix<T>::operator()(size_t i, size_t j)
{
	return m_matrix[i][j];
}

template <typename T>
const T &matrix<T>::operator()(size_t i, size_t j) const
{
	return m_matrix[i][j];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &m)
{
	for (size_t i = 0; i < m.get_rows(); i++)
	{
		for (size_t j = 0; j < m.get_cols(); j++)
		{
			os.width(10);
			os << std::left << m(i, j) << " " << std::flush;
		}
		std::cout << std::endl;
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, const std::pair<size_t, size_t> &shape)
{
	os << "(" << shape.first << ", " << shape.second << ")";
	return os;
}

template <typename T>
matrix<T> matrix<T>::zeros(size_t rows, size_t cols)
{
	matrix<T> m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = 0;
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::ones(size_t rows, size_t cols)
{
	matrix<T> m(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = 1;
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::identity(size_t rows)
{
	matrix<T> id = zeros(rows, rows);
	for (size_t i = 0; i < rows; i++)
		id(i, i) = 1;

	return id;
}

template <typename T>
matrix<T> matrix<T>::real_rand(size_t rows, size_t cols, T min, T max)
{
	matrix<T> m(rows, cols);
	std::default_random_engine engine;
	engine.seed(time(nullptr));
	std::uniform_real_distribution<T> dist(min, max);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = dist(engine);
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::int_rand(size_t rows, size_t cols, T min, T max)
{
	matrix<T> m(rows, cols);
	std::default_random_engine engine;
	engine.seed(time(nullptr));
	std::uniform_int_distribution<T> dist(min, max);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			m(i, j) = dist(engine);
	}

	return m;
}

template <typename T>
matrix<T>::~matrix()
{
	for (size_t i = 0; i < m_rows; i++)
		delete[] m_matrix[i];

	delete[] m_matrix;
}

#endif

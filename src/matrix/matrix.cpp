#include "matrix/matrix.hpp"

#include <iostream>
#include <utility>

namespace linalg
{

matrix::matrix(size_t rows, size_t cols) : m_Rows(rows), m_Cols(cols)
{
	m_Matrix = new double[rows * cols];
	for (size_t i = 0; i < rows * cols; ++i)
		m_Matrix[i] = 0;
}

matrix::matrix(size_t dim) : matrix(dim, dim) {}

matrix::matrix(const matrix& other) : m_Rows(other.rows()), m_Cols(other.cols())
{
	m_Matrix = new double[m_Rows * m_Cols];
	for (size_t i = 0; i < m_Rows * m_Cols; ++i)
		m_Matrix[i] = other.m_Matrix[i];
}

std::pair<size_t, size_t> matrix::shape() const
{
	return std::pair<size_t, size_t>(m_Rows, m_Cols);
}

matrix matrix::operator+(double scalar) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] + scalar;
	}

	return m;
}

matrix matrix::operator-(double scalar) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] - scalar;
	}

	return m;
}

matrix matrix::operator*(double scalar) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] * scalar;
	}

	return m;
}

matrix matrix::operator/(double scalar) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] / scalar;
	}

	return m;
}

matrix matrix::operator+(const matrix& other) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] + other(i, j);
	}

	return m;
}

matrix matrix::operator-(const matrix& other) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] - other(i, j);
	}

	return m;
}

matrix matrix::operator*(const matrix& other) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] * other(i, j);
	}

	return m;
}

matrix matrix::operator/(const matrix& other) const
{
	matrix m(m_Rows, m_Cols);
	for (size_t i = 0; i < m_Rows; ++i)
	{
		for (size_t j = 0; j < m_Cols; ++j)
			m(i, j) = m_Matrix[i * m_Cols + j] / other(i, j);
	}

	return m;
}

matrix::~matrix() { delete[] m_Matrix; }

} // namespace linalg

std::ostream& operator<<(std::ostream& os, linalg::matrix m)
{
	// os << "[";
	for (size_t i = 0; i < m.rows(); ++i)
	{
		for (size_t j = 0; j < m.cols(); ++j)
		{
			os << std::left << m(i, j);
			if (j < m.cols() - 1)
				os << " " << std::flush;
		}

		if (i < m.rows() - 1)
			os << std::endl;
	}
	// os << "]";

	return os;
}

std::ostream& operator<<(std::ostream& os, std::pair<size_t, size_t> shape)
{
	os << "(" << shape.first << ", " << shape.second << ")";
	return os;
}
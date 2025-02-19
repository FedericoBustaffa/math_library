#include "matrix/matrix.hpp"

#include <iostream>

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

void matrix::operator=(const matrix& other)
{
	m_Rows = other.rows();
	m_Cols = other.cols();
	for (size_t i = 0; i < m_Rows * m_Cols; ++i)
		m_Matrix[i] = other.m_Matrix[i];
}

matrix::~matrix() { delete[] m_Matrix; }

} // namespace linalg

std::ostream& operator<<(std::ostream& os, linalg::matrix m)
{
	for (size_t i = 0; i < m.rows(); ++i)
	{
		for (size_t j = 0; j < m.cols(); ++j)
			os << std::left << m(i, j) << " " << std::flush;
		os << std::endl;
	}

	return os;
}

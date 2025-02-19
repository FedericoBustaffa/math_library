#include "vector/vector.hpp"

#include <cstring>

namespace linalg
{

vector::vector(const size_t dim)
{
	m_Buffer = new double[dim];
	std::memset(m_Buffer, 0, dim * sizeof(double));
	m_Dim = dim;
}

vector::vector(const vector& other)
{
	m_Buffer = new double[other.dim()];
	std::memcpy(m_Buffer, other.m_Buffer, other.m_Dim * sizeof(double));
	m_Dim = other.m_Dim;
}

vector vector::operator+(double scalar) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] += scalar;

	return v;
}

vector vector::operator-(double scalar) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] -= scalar;

	return v;
}

vector vector::operator*(double scalar) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] *= scalar;

	return v;
}

vector vector::operator/(double scalar) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] /= scalar;

	return v;
}

vector vector::operator+(const vector& other) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] = m_Buffer[i] + other.m_Buffer[i];

	return v;
}

vector vector::operator-(const vector& other) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] = m_Buffer[i] - other.m_Buffer[i];

	return v;
}

vector vector::operator*(const vector& other) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] = m_Buffer[i] * other.m_Buffer[i];

	return v;
}

vector vector::operator/(const vector& other) const
{
	vector v(m_Dim);
	for (size_t i = 0; i < m_Dim; ++i)
		v[i] = m_Buffer[i] / other.m_Buffer[i];

	return v;
}

vector::~vector() { delete[] m_Buffer; }

} // namespace linalg

std::ostream& operator<<(std::ostream& os, linalg::vector v)
{
	os << "[ ";
	for (size_t i = 0; i < v.dim(); ++i)
	{
		if (i < v.dim() - 1)
			os << v[i] << ", ";
		else
			os << v[i];
	}

	os << " ]";

	return os;
}

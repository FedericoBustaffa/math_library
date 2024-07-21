#include "vector.hpp"

#include <cassert>

namespace lin_alg
{

std::random_device vector::s_RandomDevice;
std::mt19937 vector::s_RandomEngine(vector::s_RandomDevice());
std::uniform_real_distribution<double> vector::s_Distribution;

vector::vector(size_t size) : m_Size(size)
{
	m_Vector = new double[size];
	std::memset(m_Vector, 0, size * sizeof(double));
}

vector::vector(const vector& other) : m_Size(other.m_Size)
{
	m_Vector = new double[m_Size];
	std::memcpy(m_Vector, other.m_Vector, m_Size * sizeof(double));
}

double* vector::copy() const
{
	double* data = new double[m_Size];
	std::memcpy(data, m_Vector, m_Size * sizeof(double));

	return data;
}

vector vector::operator+(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] += scalar;

	return v;
}

vector vector::operator-(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] -= scalar;

	return v;
}

vector vector::operator*(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] *= scalar;

	return v;
}

vector vector::operator/(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] /= scalar;

	return v;
}

vector vector::operator+(const vector& other) const
{
	assert(m_Size == other.m_Size);
	vector v(m_Size);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] = m_Vector[i] + other.m_Vector[i];

	return v;
}

vector vector::operator-(const vector& other) const
{
	assert(m_Size == other.m_Size);
	vector v(m_Size);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] = m_Vector[i] - other.m_Vector[i];

	return v;
}

vector vector::operator*(const vector& other) const
{
	assert(m_Size == other.m_Size);
	vector v(m_Size);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] = m_Vector[i] * other.m_Vector[i];

	return v;
}

vector vector::operator/(const vector& other) const
{
	assert(m_Size == other.m_Size);
	vector v(m_Size);
	for (size_t i = 0; i < m_Size; ++i)
		v[i] = m_Vector[i] / other.m_Vector[i];

	return v;
}

vector vector::random(size_t size, double min, double max)
{
	assert(min < max);
	vector v(size);
	for (size_t i = 0; i < size; i++)
		v[i] = std::uniform_real_distribution<double>(min, max)(s_RandomEngine);

	return v;
}

vector::~vector() { delete[] m_Vector; }

} // namespace lin_alg
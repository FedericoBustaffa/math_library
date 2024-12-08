#include "vector.hpp"

#include <cassert>

namespace linalg
{

template <size_t ndim>
vector<ndim>::vector()
{
	m_Vector = new double[ndim];
	std::memset(m_Vector, 0, ndim * sizeof(double));
}

template <size_t ndim>
vector<ndim>::vector(const vector<ndim>& other)
{
	m_Vector = new double[ndim];
	std::memcpy(m_Vector, other.m_Vector, ndim * sizeof(double));
}

template <size_t ndim>
double* vector<ndim>::copy() const
{
	double* data = new double[ndim];
	std::memcpy(data, m_Vector, ndim * sizeof(double));

	return data;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator+(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < ndim; ++i)
		v[i] += scalar;

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator-(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < ndim; ++i)
		v[i] -= scalar;

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator*(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < ndim; ++i)
		v[i] *= scalar;

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator/(double scalar) const
{
	vector v(*this);
	for (size_t i = 0; i < ndim; ++i)
		v[i] /= scalar;

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator+(const vector<ndim>& other) const
{
	vector<ndim> v;
	for (size_t i = 0; i < ndim; ++i)
		v[i] = m_Vector[i] + other.m_Vector[i];

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator-(const vector<ndim>& other) const
{
	vector<ndim> v;
	for (size_t i = 0; i < ndim; ++i)
		v[i] = m_Vector[i] - other.m_Vector[i];

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator*(const vector<ndim>& other) const
{
	vector<ndim> v;
	for (size_t i = 0; i < ndim; ++i)
		v[i] = m_Vector[i] * other.m_Vector[i];

	return v;
}

template <size_t ndim>
vector<ndim> vector<ndim>::operator/(const vector<ndim>& other) const
{
	vector<ndim> v;
	for (size_t i = 0; i < ndim; ++i)
		v[i] = m_Vector[i] / other.m_Vector[i];

	return v;
}

template <size_t ndim>
vector<ndim>::~vector()
{
	delete[] m_Vector;
}

} // namespace linalg
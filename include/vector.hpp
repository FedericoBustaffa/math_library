#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <cstring>
#include <random>

namespace linalg
{

template <size_t ndim>
class vector
{
public:
	vector();
	vector(const vector& other);

	inline size_t size() const { return ndim; }
	double* copy() const;
	inline const double* data() const { return m_Vector; }

	inline double& operator[](size_t i) const { return m_Vector[i]; }

	vector operator+(double scalar) const;
	vector operator-(double scalar) const;
	vector operator*(double scalar) const;
	vector operator/(double scalar) const;

	vector operator+(const vector& other) const;
	vector operator-(const vector& other) const;
	vector operator*(const vector& other) const;
	vector operator/(const vector& other) const;

	~vector();

private:
	double* m_Vector;
};

} // namespace linalg

template <size_t ndim>
inline std::ostream& operator<<(std::ostream& os, linalg::vector<ndim>& v)
{
	os << "[ ";
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i < v.size() - 1)
			os << v[i] << ", ";
		else
			os << v[i];
	}

	os << " ]";

	return os;
}

#endif
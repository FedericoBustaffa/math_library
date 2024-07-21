#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <cstring>
#include <random>

namespace lin_alg
{

class vector
{
public:
	vector(size_t size);
	vector(const vector& other);

	inline size_t size() const { return m_Size; }
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

public:
	static vector random(size_t size, double min, double max);

private:
	static std::random_device s_RandomDevice;
	static std::mt19937 s_RandomEngine;
	static std::uniform_real_distribution<double> s_Distribution;

private:
	size_t m_Size;
	double* m_Vector;
};

} // namespace lin_alg

inline std::ostream& operator<<(std::ostream& os, lin_alg::vector& v)
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
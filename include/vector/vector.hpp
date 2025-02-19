#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace linalg
{

class vector
{
public:
	vector(size_t dim);
	vector(const vector& other);

	inline size_t dim() const { return m_Dim; }
	inline size_t size() const { return m_Dim * sizeof(double); }
	inline vector copy() const { return vector(*this); };
	inline const double* data() const { return m_Buffer; }

	inline double& operator[](size_t i) const { return m_Buffer[i]; }

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
	double* m_Buffer;
	size_t m_Dim;
};

double dot(const vector& v1, const vector& v2);

vector cross(const vector& v1, const vector& v2);

double norm2(const vector& v);

} // namespace linalg

std::ostream& operator<<(std::ostream& os, linalg::vector v);

#endif

#ifndef OPERATIONS
#define OPERATIONS

#include "linalg.hpp"

#include <cmath>

namespace linalg
{

double dot(const vector& v1, const vector& v2)
{
	double res = 0;
	for (size_t i = 0; i < v1.dim(); ++i)
		res += v1[i] * v2[i];

	return res;
}

double norm2(const vector& v) { return std::sqrt(dot(v, v)); }

} // namespace linalg

#endif
#ifndef OPERATIONS
#define OPERATIONS

#include "vector.hpp"

namespace lin_alg
{

double dot(const vector& v1, const vector& v2)
{
	double res = 0;

	for (size_t i = 0; i < v1.size(); ++i)
		res += v1[i] * v2[i];

	return res;
}

vector cross(const vector& v1, const vector& v2) { return vector(1); }

} // namespace lin_alg

#endif
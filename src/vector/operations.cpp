#ifndef OPERATIONS
#define OPERATIONS

#include "linalg.hpp"

#include <cmath>
#include <cassert>

namespace linalg
{

double dot(const vector& v1, const vector& v2)
{
	double res = 0;
	for (size_t i = 0; i < v1.dim(); ++i)
		res += v1[i] * v2[i];

	return res;
}

vector cross(const vector& v1, const vector& v2)
{
	assert((v1.dim() == 3) && (v2.dim() == 3));
	vector res(3);

	res[0] = v1[1] * v2[2] - v1[2] * v2[1];
	res[1] = v1[2] * v2[0] - v1[0] * v2[2];
	res[2] = v1[0] * v2[1] - v1[1] * v2[0];

	return res;
}

double norm2(const vector& v) { return std::sqrt(dot(v, v)); }

} // namespace linalg

#endif
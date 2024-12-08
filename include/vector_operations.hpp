#ifndef OPERATIONS
#define OPERATIONS

#include "vector.hpp"

namespace linalg
{

template <size_t ndim>
double dot(const vector<ndim>& v1, const vector<ndim>& v2)
{
	double res = 0;

	for (size_t i = 0; i < v1.size(); ++i)
		res += v1[i] * v2[i];

	return res;
}

} // namespace linalg

#endif
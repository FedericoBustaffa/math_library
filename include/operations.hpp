#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include "matrix.hpp"
#include "vector.hpp"

namespace linalg
{

// vector
double dot(const vector& v1, const vector& v2);
vector cross(const vector& v1, const vector& v2);
double norm2(const vector& v);

// matrix
matrix transpose(const matrix& m);
matrix dot(const matrix& a, const matrix& b);

} // namespace linalg

#endif

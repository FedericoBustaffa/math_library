#ifndef VECTOR_OPERATIONS_HPP
#define VECTOR_OPERATIONS_HPP

#include "vector.hpp"

namespace linalg
{

double dot(const vector& v1, const vector& v2);

vector cross(const vector& v1, const vector& v2);

double norm2(const vector& v);

} // namespace linalg

#endif
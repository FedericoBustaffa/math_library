#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include "matrix.hpp"

namespace linalg
{

matrix transpose(const matrix& m);

matrix dot(const matrix& a, const matrix& b);

} // namespace linalg

#endif
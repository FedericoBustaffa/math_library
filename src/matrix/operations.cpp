#include "matrix/matrix.hpp"

#include <cassert>

namespace linalg
{

matrix transpose(const matrix& m)
{
	matrix t(m);
	for (size_t i = 0; i < m.rows(); ++i)
	{
		for (size_t j = 0; j < m.cols(); ++j)
			t(j, i) = m(i, j);
	}

	return t;
}

matrix dot(const matrix& a, const matrix& b)
{

	assert(a.cols() == b.rows());
	matrix res(a.rows(), b.cols());
	for (size_t i = 0; i < a.cols(); ++i)
	{
		for (size_t k = 0; k < b.cols(); ++k)
		{
			for (size_t j = 0; j < b.rows(); ++j)
				res(i, j) += a(i, k) * b(k, j);
		}
	}

	return res;
}

} // namespace linalg
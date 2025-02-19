#include "matrix/matrix.hpp"

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

} // namespace linalg
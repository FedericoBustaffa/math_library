#include <iostream>

#include "linalg.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	la::matrix m(5);
	for (size_t i = 0; i < m.rows(); ++i)
	{
		for (size_t j = 0; j < m.cols(); ++j)
			m(i, j) = i * m.cols() + j;
	}
	std::cout << m << std::endl;
	std::cout << std::endl;
	std::cout << la::transpose(m) << std::endl;

	return 0;
}

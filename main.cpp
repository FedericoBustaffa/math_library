#include <iostream>

#include "include/linalg.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	la::matrix m(3, 3);
	std::cout << m << std::endl;

	la::vector v(9);
	std::cout << v << std::endl;

	return 0;
}

#include <iostream>

#include "vector.hpp"
#include "vector_operations.hpp"

namespace la = lin_alg;

int main(int argc, const char** argv)
{
	la::vector v1 = la::vector::random(5, 0, 1);
	la::vector v2 = la::vector::random(5, 0, 1);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;

	std::cout << la::dot(v1, v2) << std::endl;

	return 0;
}

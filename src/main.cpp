#include <iostream>

#include "linalg.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	la::vector v1(3);
	v1[0] = 1;
	v1[1] = 1;
	v1[2] = 1;

	la::vector v2(3);
	v2[0] = 0;
	v2[1] = 1;

	std::cout << "dimensions: " << v1.dim() << std::endl;
	std::cout << "bytes: " << v1.size() << std::endl;

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	std::cout << "dot product: " << la::dot(v1, v2) << std::endl;
	std::cout << "norm2 of v1: " << la::norm2(v1) << std::endl;
	std::cout << "norm2 of v2: " << la::norm2(v2) << std::endl;
	std::cout << "norm2 of v1 - v2: " << la::norm2(v1 - v2) << std::endl;

	std::cout << "cross product: " << la::cross(v1, v2) << std::endl;

	return 0;
}

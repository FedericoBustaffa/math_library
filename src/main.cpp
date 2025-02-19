#include <iostream>

#include "linalg.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	la::vector v1(3);
	la::vector v2(3);

	for (size_t i = 0; i < v2.dim(); ++i)
	{
		v1[i] = 0.5;
		v2[i] = 1;
	}

	std::cout << "dimensions: " << v1.dim() << std::endl;
	std::cout << "bytes: " << v1.size() << std::endl;

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	std::cout << "dot product: " << la::dot(v1, v2) << std::endl;
	std::cout << "norm2 of v1: " << la::norm2(v1) << std::endl;
	std::cout << "norm2 of v2: " << la::norm2(v2) << std::endl;
	std::cout << "norm2 of v1 - v2: " << la::norm2(v1 - v2) << std::endl;

	return 0;
}

#include <iostream>

#include "vector_impl.hpp"
#include "vector_operations.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	la::vector<3> v1;
	la::vector<3> v2;

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;

	std::cout << la::dot(v1, v2) << std::endl;

	return 0;
}

#include <iostream>

#include "vector.hpp"

namespace la = lin_alg;

int main(int argc, const char** argv)
{
	la::vector v1(10);
	for (size_t i = 0; i < v1.size(); ++i)
		v1[i] = 10;

	std::cout << "V1: " << v1 << std::endl;

	auto v2 = v1 + 2;
	auto v3 = v1 - 2;
	auto v4 = v1 * 2;
	auto v5 = v1 / 2;

	std::cout << "V2: " << v2 << std::endl;
	std::cout << "V3: " << v3 << std::endl;
	std::cout << "V4: " << v4 << std::endl;
	std::cout << "V5: " << v5 << std::endl;

	auto v6 = v1 + v2;
	auto v7 = v1 - v3;
	auto v8 = v1 * v4;
	auto v9 = v1 / v5;

	std::cout << "V6: " << v6 << std::endl;
	std::cout << "V7: " << v7 << std::endl;
	std::cout << "V8: " << v8 << std::endl;
	std::cout << "V9: " << v9 << std::endl;

	return 0;
}

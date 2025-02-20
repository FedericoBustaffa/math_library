#include <iostream>
#include <chrono>

#include "linalg.hpp"
#include "matrix.hpp"
#include "vector.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <dim>" << std::endl;
		return 1;
	}

	size_t dim = (size_t)std::atoi(argv[1]);
	la::matrix a(dim);
	la::matrix b(dim);
	for (size_t i = 0; i < a.rows(); ++i)
	{
		for (size_t j = 0; j < a.cols(); ++j)
		{
			a(i, j) = i * a.cols() + j;
			b(i, j) = i * a.cols() + j * 2;
		}
	}

	auto start = std::chrono::high_resolution_clock::now();
	la::matrix p = la::dot(a, b);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> d = end - start;
	std::cout << d.count() << std::endl;

	la::vector v1(3);
	v1[0] = 1;
	la::vector v2(3);
	v2[1] = 1;

	la::vector v3 = la::cross(v1, v2);
	std::cout << v3 << std::endl;

	return 0;
}

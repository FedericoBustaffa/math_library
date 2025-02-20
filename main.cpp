#include <iostream>
#include <chrono>

#include "linalg.hpp"

namespace la = linalg;

int main(int argc, const char** argv)
{
	size_t dim = (size_t)std::atoi(argv[1]);
	la::matrix a(dim);
	la::matrix b(dim);
	for (size_t i = 0; i < a.rows(); ++i)
	{
		for (size_t j = 0; j < a.cols(); ++j)
		{
			a(i, j) = i * a.cols() + j / 10;
			b(i, j) = i * a.cols() + j * 2;
		}
	}

	auto start = std::chrono::high_resolution_clock::now();
	la::matrix p = la::dot(a, b);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> d = end - start;
	std::cout << d.count() << std::endl;

	return 0;
}

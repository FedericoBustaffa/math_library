#include <iostream>
#include <chrono>
#include <vector>

#include "matrix.hpp"

template <typename T>
void display(const matrix<T> &m)
{
	for (size_t i = 0; i < m.get_rows(); i++)
	{

		for (size_t j = 0; j < m.get_cols(); j++)
		{
			std::cout << m(i, j) << " " << std::flush;
		}
		std::cout << std::endl;
	}
}

int main()
{
	size_t dim;
	std::cout << "dimensione: " << std::flush;
	std::cin >> dim;

	matrix<int> a = matrix<int>::int_rand(dim, dim, 0, 4);
	matrix<int> b = matrix<int>::int_rand(dim, dim, 0, 4);
	matrix<int> c = matrix<int>::zeros(dim, dim);
	c = a * b;

	// display(a);
	// std::cout << std::endl;
	// display(b);
	// std::cout << std::endl;
	// display(c);

	c = matrix<int>::zeros(dim, dim);
	c = a.dot_product(b);
	// display(c);

	return 0;
}

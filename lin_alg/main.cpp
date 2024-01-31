#include "lin_alg.hpp"

int main(int argc, const char **argv)
{
	const size_t dim = 1000;
	matrix<int> a = matrix<int>::int_rand(dim, dim, 0, 5);
	matrix<int> b = matrix<int>::int_rand(dim, dim, 0, 5);
	matrix<int> c = a * b;

	return 0;
}

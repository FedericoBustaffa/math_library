#include "lin_alg.hpp"

int main(int argc, const char **argv)
{
	const size_t dim = 1024;
	matrix<int> a = matrix<int>::rand_int(dim, dim, 0, 5);
	matrix<int> b = matrix<int>::rand_int(dim, dim, 0, 5);
	matrix<int> c = a * b;

	return 0;
}

#include <iostream>

#include "lin_alg.hpp"

#define dim 2048

int main(int argc, const char **argv)
{
    matrix<int> a = matrix<int>::rand_int(dim, dim, 0, 5);
    matrix<int> b = matrix<int>::rand_int(dim, dim, 0, 5);

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;

    matrix<int> c = a * b;
    // std::cout << c << std::endl;

    c = a.prod(b);
    // std::cout << c << std::endl;

    return 0;
}

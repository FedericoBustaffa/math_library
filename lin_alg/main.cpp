#include <cmath>
#include <iostream>
#include <string>

#include "lin_alg.hpp"

#define dim 3000

using elem_type = uint32_t;

int main(int argc, const char **argv)
{
    matrix<int> a = matrix<int>::rand_int(dim, dim, 0, 5);
    matrix<int> b = matrix<int>::rand_int(dim, dim, 0, 5);

    // std::cout << "A\n"
    //           << a << std::endl;

    // std::cout << "B\n"
    //           << b << std::endl;

    matrix<int> c = a * b;
    // std::cout << "C\n"
    //           << c << std::endl;

    c = prod(a, b);
    // std::cout << "C\n"
    //           << c << std::endl;

    return 0;
}

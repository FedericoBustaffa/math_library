#include <cmath>
#include <iostream>
#include <string>

#include "lin_alg.hpp"

#define dim 4

using elem_type = uint32_t;

int main(int argc, const char **argv)
{
    matrix<int> a = matrix<int>::rand_int(dim, 0, 5);
    std::cout << a << std::endl;

    matrix<int> b = matrix<int>::rand_int(dim, 0, 10);
    std::cout << b << std::endl;

    return 0;
}

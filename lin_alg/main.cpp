#include <cmath>
#include <iostream>
#include <string>

#include "lin_alg.hpp"

#define dim 4096

using elem_type = uint32_t;

int main(int argc, const char **argv)
{
    matrix<int> a = matrix<int>::rand_int(dim, dim, 0, 5);
    matrix<int> b = matrix<int>::rand_int(dim, dim, 0, 5);
    matrix<int> c = a * b;

    return 0;
}

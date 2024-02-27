#include <iostream>
#include <string>
#include <random>

#include "lin_alg.hpp"

#define dim 4

using elem_type = uint32_t;

int main(int argc, const char **argv)
{
    std::default_random_engine engine(time(nullptr));

    matrix<int> a = matrix<int>::rand(engine, dim, 0, 5);
    std::cout << a << std::endl;

    matrix<double> b = matrix<double>::rand(engine, dim, 0, 10);
    std::cout << b << std::endl;

    return 0;
}

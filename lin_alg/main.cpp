#include <iostream>
#include <random>
#include <string>

#include "lin_alg.hpp"

#define dim 4096

using elem_type = uint32_t;

int main(int argc, const char** argv) {
    std::default_random_engine engine(time(nullptr));

    matrix<int> a = matrix<int>::rand(engine, dim, 0, 5);
    matrix<int> b = matrix<int>::rand(engine, dim, 0, 10);
    matrix<int> c = a * b;

    return 0;
}

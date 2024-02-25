#include <cmath>
#include <iostream>
#include <string>

#include "lin_alg.hpp"

using elem_type = uint32_t;

int main(int argc, const char **argv)
{

    matrix<int> a = matrix<int>::rand_int(2, 2, 0, 5);
    std::cout << "A\n"
              << a << std::endl;

    // test operatori scalari
    std::cout << a + 2 << std::endl;
    std::cout << 2 + a << std::endl;

    std::cout << a - 2 << std::endl;
    std::cout << 2 - a << std::endl;

    std::cout << a * 2 << std::endl;
    std::cout << 2 * a << std::endl;

    std::cout << a / 2 << std::endl;
    std::cout << 2 / a << std::endl;

    matrix<int> b = matrix<int>::rand_int(2, 2, 0, 5);
    matrix<int> c = a * b;

    return 0;
}

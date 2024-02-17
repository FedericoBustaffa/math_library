#include <cmath>
#include <iostream>
#include <string>

#include "./lin_alg.hpp"

using elem_type = uint32_t;

int main(int argc, const char** argv) {
    unsigned Ntrials = 5;
    size_t* dims = new size_t[6];
    for (unsigned i = 0; i < Ntrials; ++i) {
        dims[i] = std::pow(2, i + 7);
    }

    for (unsigned i = 0; i < Ntrials; ++i) {
        std::cout << std::endl
                  << "With dim=" + std::to_string(dims[i]) + "x" +
                         std::to_string(dims[i])
                  << std::endl;

        matrix<elem_type> a =
            matrix<elem_type>::rand_int(dims[i], dims[i], 0, 5);
        matrix<elem_type> b =
            matrix<elem_type>::rand_int(dims[i], dims[i], 0, 5);

        // std::cout << a << std::endl;
        // std::cout << b << std::endl;

        matrix<elem_type> c(dims[i], dims[i]);

        c = a.prod(b);
        // std::cout << c << std::endl;

        c = a.yetanotherprod(b);
        // std::cout << c << std::endl;

        c = a.otherprod(b);
        // std::cout << c << std::endl;

        c = a * b;
        // std::cout << c << std::endl;
    }

    return 0;
}

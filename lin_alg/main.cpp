#include "lin_alg.hpp"

#define dim 1024

int main(int argc, const char **argv)
{
    matrix<double> a = matrix<double>::rand_real(dim, dim, 0, 5);
    matrix<double> b = matrix<double>::rand_real(dim, dim, 0, 5);
    matrix<double> c(dim, dim);
    c = a * b;

    return 0;
}

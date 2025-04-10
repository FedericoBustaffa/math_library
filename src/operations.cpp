#include "matrix.hpp"
#include "vector.hpp"

#include <cassert>
#include <cmath>

namespace linalg
{

// ---------- VECTOR OPERATIONS ----------

double dot(const vector& v1, const vector& v2)
{
    double res = 0;
    for (size_t i = 0; i < v1.dim(); ++i)
        res += v1[i] * v2[i];

    return res;
}

vector cross(const vector& v1, const vector& v2)
{
    assert((v1.dim() == 3) && (v2.dim() == 3));
    vector res(3);

    res[0] = v1[1] * v2[2] - v1[2] * v2[1];
    res[1] = v1[2] * v2[0] - v1[0] * v2[2];
    res[2] = v1[0] * v2[1] - v1[1] * v2[0];

    return res;
}

double norm2(const vector& v) { return std::sqrt(dot(v, v)); }

// ---------- MATRIX OPERATIONS ----------

matrix transpose(const matrix& m)
{
    matrix t(m);
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
            t(j, i) = m(i, j);
    }

    return t;
}

matrix dot(const matrix& a, const matrix& b)
{

    assert(a.cols() == b.rows());
    matrix res(a.rows(), b.cols());
    for (size_t i = 0; i < a.cols(); ++i)
    {
        for (size_t k = 0; k < b.cols(); ++k)
        {
            for (size_t j = 0; j < b.rows(); ++j)
                res(i, j) += a(i, k) * b(k, j);
        }
    }

    return res;
}

} // namespace linalg

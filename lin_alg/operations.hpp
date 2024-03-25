#ifndef MAT_OPERATIONS_H
#define MAT_OPERATIONS_H

#include <chrono>
#include <iostream>

#include "matrix.hpp"

template <typename T>
matrix<T> operator+(const matrix<T> &m, T scalar)
{
    matrix<T> res(m.rows(), m.cols());
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
            res(i, j) = m(i, j) + scalar;
    }

    return res;
}

template <typename T>
matrix<T> operator+(T scalar, const matrix<T> &m)
{
    size_t rows = m.rows();
    size_t cols = m.cols();
    matrix<T> r(rows, cols);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            r(i, j) = m(i, j) + scalar;
    }

    return r;
}

template <typename T>
matrix<T> operator-(const matrix<T> &m, T scalar)
{
    matrix<T> res(m.rows(), m.cols());
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
            res(i, j) = m(i, j) - scalar;
    }

    return res;
}

template <typename T>
matrix<T> operator-(T scalar, const matrix<T> &m)
{
    size_t rows = m.rows();
    size_t cols = m.cols();
    matrix<T> r(rows, cols);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            r(i, j) = m(i, j) - scalar;
    }

    return r;
}

template <typename T>
matrix<T> operator*(const matrix<T> &m, T scalar)
{
    matrix<T> res(m.rows(), m.cols());
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
            res(i, j) = m(i, j) * scalar;
    }

    return res;
}

template <typename T>
matrix<T> operator*(T scalar, const matrix<T> &m)
{
    size_t rows = m.rows();
    size_t cols = m.cols();
    matrix<T> r(rows, cols);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            r(i, j) = m(i, j) * scalar;
    }

    return r;
}

template <typename T>
matrix<T> operator/(const matrix<T> &m, T scalar)
{
    matrix<T> res(m.rows(), m.cols());
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
            res(i, j) = m(i, j) / scalar;
    }

    return res;
}

template <typename T>
matrix<T> operator/(T scalar, const matrix<T> &m)
{
    size_t rows = m.rows();
    size_t cols = m.cols();
    matrix<T> r(rows, cols);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            r(i, j) = m(i, j) / scalar;
    }

    return r;
}

// somma elemento per elemento
template <typename T>
matrix<T> operator+(const matrix<T> &a, const matrix<T> &b)
{
    matrix<T> res(a.rows(), a.cols());
    for (size_t i = 0; i < a.rows(); ++i)
    {
        for (size_t j = 0; j < a.cols(); ++j)
            res(i, j) = a(i, j) + b(i, j);
    }

    return res;
}

// differenza elemento per elemento
template <typename T>
matrix<T> operator-(const matrix<T> &a, const matrix<T> &b)
{
    matrix<T> res(a.rows(), a.cols());
    for (size_t i = 0; i < a.rows(); ++i)
    {
        for (size_t j = 0; j < a.cols(); ++j)
            res(i, j) = a(i, j) - b(i, j);
    }

    return res;
}

template <typename T>
matrix<T> operator*(const matrix<T> &a, const matrix<T> &b)
{
    size_t cols = b.cols();
    matrix<T> prod(a.rows(), cols);

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < a.rows(); ++i)
    {
        for (size_t k = 0; k < a.cols(); ++k)
        {
            for (size_t j = 0; j < cols; ++j)
                prod(i, j) += a(i, k) * b(k, j);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "row x elem x col time: " << duration.count() << " s" << std::endl;

    return prod;
}

template <typename T>
matrix<T> prod(const matrix<T> &a, const matrix<T> &b)
{
    size_t cols = b.cols();
    matrix<T> prod(a.rows(), cols);

    auto another = b.transpose();
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < a.rows(); ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            for (size_t k = 0; k < a.cols(); ++k)
                prod(i, j) += a(i, k) * another(j, k);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "row x col x elem (with transpose) time: " << duration.count() << " s"
              << std::endl;

    return prod;
}

template <typename T>
matrix<T> matrix<T>::transpose() const
{
    matrix<T> t(m_cols, m_rows);
    for (size_t i = 0; i < m_rows; ++i)
    {
        for (size_t j = 0; j < m_cols; ++j)
            t.m_matrix[j][i] = m_matrix[i][j];
    }

    return t;
}

#endif

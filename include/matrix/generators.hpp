#ifndef GENERATORS_HPP
#define GENERATORS_HPP

#include "matrix.hpp"

namespace lin_alg
{

template <typename T>
matrix<T> matrix<T>::zeros(size_t rows, size_t cols)
{
	matrix<T> m(rows, cols);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
			m(i, j) = 0;
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::ones(size_t rows, size_t cols)
{
	matrix<T> m(rows, cols);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
			m(i, j) = 1;
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::identity(size_t rows)
{
	matrix<T> id = zeros(rows, rows);
	for (size_t i = 0; i < rows; ++i)
		id(i, i) = 1;

	return id;
}

template <typename T>
matrix<T> matrix<T>::rand(std::default_random_engine& engine, size_t rows, size_t cols, T min,
						  T max)
{
	matrix<T> m(rows, cols);

	if constexpr (std::is_integral<T>::value)
	{
		std::uniform_int_distribution<T> dist(min, max);
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
				m(i, j) = dist(engine);
		}
	}
	else
	{
		std::uniform_real_distribution<T> dist(min, max);
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
				m(i, j) = dist(engine);
		}
	}

	return m;
}

template <typename T>
matrix<T> matrix<T>::rand(std::default_random_engine& engine, size_t dim, T min, T max)
{
	return matrix<T>::rand(engine, dim, dim, min, max);
}

} // namespace lin_alg

#endif
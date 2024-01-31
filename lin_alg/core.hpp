#ifndef MAT_CORE_H
#define MAT_CORE_H

#include <iostream>
#include <random>
#include <ctime>
#include <tuple>

template <typename T>
class matrix
{
public:
	matrix(size_t rows, size_t cols);
	matrix(const matrix<T> &other);
	void operator=(const matrix<T> &other);

	// utility
	size_t get_rows() const;
	size_t get_cols() const;
	size_t size() const;
	std::pair<size_t, size_t> shape() const;

	// accesso elementi
	T &operator()(size_t i, size_t j);
	const T &operator()(size_t i, size_t j) const;

	// generazione matrici
	static matrix zeros(size_t rows, size_t cols);
	static matrix ones(size_t rows, size_t cols);
	static matrix identity(size_t rows);
	static matrix real_rand(size_t rows, size_t cols, T min, T max);
	static matrix int_rand(size_t rows, size_t cols, T min, T max);

	// operazioni scalari
	matrix operator+(T scalar) const;
	matrix operator-(T scalar) const;
	matrix operator*(T scalar) const;
	matrix operator/(T scalar) const;

	// operazioni tra matrici
	matrix operator+(const matrix &other) const;
	matrix operator-(const matrix &other) const;

	// prodotto riga per colonna
	matrix<T> operator*(const matrix<T> &other) const;

	// prodotto colonna per riga
	matrix<T> dot_product(const matrix<T> &other) const;

	// trasposizione
	matrix<T>
	transpose() const;

	~matrix();

private:
	size_t m_rows;
	size_t m_cols;
	T **m_matrix;
};

#endif

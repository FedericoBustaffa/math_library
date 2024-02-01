#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <tuple>

template <typename T>
class matrix
{
public:
	matrix(size_t rows, size_t cols);
	matrix(const matrix &other);
	void operator=(const matrix &other);

	// utility
	inline size_t rows() const { return m_rows; };
	inline size_t cols() const { return m_cols; };
	inline size_t size() const { return m_rows * m_cols; };
	inline std::pair<size_t, size_t> shape() const { return std::pair<size_t, size_t>(m_rows, m_cols); };

	// accesso elementi
	T &operator()(size_t i, size_t j) { return m_matrix[i][j]; };
	const T &operator()(size_t i, size_t j) const { return m_matrix[i][j]; };

	// generazione matrici
	static matrix zeros(size_t rows, size_t cols);
	static matrix ones(size_t rows, size_t cols);
	static matrix identity(size_t rows);
	static matrix rand_real(size_t rows, size_t cols, T min, T max);
	static matrix rand_int(size_t rows, size_t cols, T min, T max);

	// operazioni scalari
	matrix operator+(T scalar) const;
	matrix operator-(T scalar) const;
	matrix operator*(T scalar) const;
	matrix operator/(T scalar) const;

	// operazioni tra matrici
	matrix operator+(const matrix &other) const;
	matrix operator-(const matrix &other) const;

	// prodotto riga per colonna
	matrix operator*(const matrix &other) const;

	// trasposizione
	matrix transpose() const;

	~matrix();

private:
	size_t m_rows;
	size_t m_cols;
	T **m_matrix;
};

template <typename T>
matrix<T>::matrix(size_t rows, size_t cols)
	: m_rows(rows), m_cols(cols)
{
	m_matrix = new T *[rows];
	for (size_t i = 0; i < rows; i++)
	{
		m_matrix[i] = new T[cols];
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = 0;
	}
}

template <typename T>
matrix<T>::matrix(const matrix<T> &other)
	: m_rows(other.rows()), m_cols(other.cols())
{
	m_matrix = new T *[m_rows];
	for (size_t i = 0; i < m_rows; i++)
	{
		m_matrix[i] = new T[m_cols];
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = other(i, j);
	}
}

template <typename T>
void matrix<T>::operator=(const matrix<T> &other)
{
	m_rows = other.rows();
	m_cols = other.cols();
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
			m_matrix[i][j] = other(i, j);
	}
}

#endif

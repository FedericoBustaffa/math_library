#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>

namespace linalg
{

class matrix
{
public:
	matrix(size_t rows, size_t cols);
	matrix(size_t dim);
	matrix(const matrix& other);
	matrix(matrix&& other) noexcept;

	// utility
	inline size_t rows() const { return m_Rows; }
	inline size_t cols() const { return m_Cols; }
	inline size_t dim() const { return m_Rows * m_Cols; }
	std::pair<size_t, size_t> shape() const;

	// access elements
	double& operator()(size_t i, size_t j) { return m_Matrix[i * m_Cols + j]; }
	const double& operator()(size_t i, size_t j) const { return m_Matrix[i * m_Cols + j]; }

	matrix operator+(double scalar) const;
	matrix operator-(double scalar) const;
	matrix operator*(double scalar) const;
	matrix operator/(double scalar) const;

	matrix operator+(const matrix& other) const;
	matrix operator-(const matrix& other) const;
	matrix operator*(const matrix& other) const;
	matrix operator/(const matrix& other) const;

	~matrix();

private:
	size_t m_Rows;
	size_t m_Cols;
	double* m_Matrix;
};

} // namespace linalg

std::ostream& operator<<(std::ostream& os, const linalg::matrix& m);

std::ostream& operator<<(std::ostream& os, const std::pair<size_t, size_t>& shape);

#endif

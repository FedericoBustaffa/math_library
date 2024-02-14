#ifndef MATRICES_HPP
#define MATRICES_HPP

#include <random>

#include "./matrix.hpp"

template <typename T> matrix<T> matrix<T>::zeros(size_t rows, size_t cols) {
  matrix<T> m(rows, cols);
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j)
      m(i, j) = 0;
  }

  return m;
}

template <typename T> matrix<T> matrix<T>::ones(size_t rows, size_t cols) {
  matrix<T> m(rows, cols);
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j)
      m(i, j) = 1;
  }

  return m;
}

template <typename T> matrix<T> matrix<T>::identity(size_t rows) {
  matrix<T> id = zeros(rows, rows);
  for (size_t i = 0; i < rows; ++i)
    id(i, i) = 1;

  return id;
}

template <typename T>
matrix<T> matrix<T>::rand_real(size_t rows, size_t cols, T min, T max) {
  matrix<T> m(rows, cols);
  std::default_random_engine engine;
  engine.seed(time(nullptr));
  std::uniform_real_distribution<T> dist(min, max);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j)
      m(i, j) = dist(engine);
  }

  return m;
}

template <typename T>
matrix<T> matrix<T>::rand_int(size_t rows, size_t cols, T min, T max) {
  matrix<T> m(rows, cols);
  std::default_random_engine engine;
  engine.seed(time(nullptr));
  std::uniform_int_distribution<T> dist(min, max);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j)
      m(i, j) = dist(engine);
  }

  return m;
}

template <typename T> matrix<T>::~matrix() {
  for (size_t i = 0; i < m_rows; ++i)
    delete[] m_matrix[i];

  delete[] m_matrix;
}

#endif

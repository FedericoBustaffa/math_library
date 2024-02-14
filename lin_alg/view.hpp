#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <utility>

#include "./matrix.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &m) {
  for (size_t i = 0; i < m.rows(); ++i) {
    for (size_t j = 0; j < m.cols(); ++j) {
      os.width(10);
      os << std::left << m(i, j) << " " << std::flush;
    }
    std::cout << std::endl;
  }

  return os;
}

inline std::ostream &operator<<(std::ostream &os,
                                const std::pair<size_t, size_t> &shape) {
  os << "(" << shape.first << ", " << shape.second << ")";
  return os;
}

#endif


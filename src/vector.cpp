#include "vector.hpp"

namespace linalg
{

vector::vector(const size_t dim) : m_Dim(dim)
{
    m_Buffer = new double[dim];
    std::fill(m_Buffer, m_Buffer + m_Dim, 0);
}

vector::vector(const vector& other) : m_Dim(other.m_Dim)
{
    m_Buffer = new double[other.m_Dim];
    std::copy(other.m_Buffer, other.m_Buffer + other.m_Dim, m_Buffer);
}

vector::vector(vector&& other) noexcept
    : m_Dim(other.m_Dim), m_Buffer(other.m_Buffer)
{
    other.m_Dim = 0;
    other.m_Buffer = nullptr;
}

vector vector::operator+(double scalar) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] += scalar;

    return v;
}

vector vector::operator-(double scalar) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] -= scalar;

    return v;
}

vector vector::operator*(double scalar) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] *= scalar;

    return v;
}

vector vector::operator/(double scalar) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] /= scalar;

    return v;
}

vector vector::operator+(const vector& other) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] = m_Buffer[i] + other.m_Buffer[i];

    return v;
}

vector vector::operator-(const vector& other) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] = m_Buffer[i] - other.m_Buffer[i];

    return v;
}

vector vector::operator*(const vector& other) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] = m_Buffer[i] * other.m_Buffer[i];

    return v;
}

vector vector::operator/(const vector& other) const
{
    vector v(m_Dim);
    for (size_t i = 0; i < m_Dim; ++i)
        v[i] = m_Buffer[i] / other.m_Buffer[i];

    return v;
}

vector::~vector() { delete[] m_Buffer; }

} // namespace linalg

std::ostream& operator<<(std::ostream& os, const linalg::vector& v)
{
    os << "[ ";
    for (size_t i = 0; i < v.dim(); ++i)
    {
        if (i < v.dim() - 1)
            os << v[i] << ", ";
        else
            os << v[i];
    }

    os << " ]";

    return os;
}

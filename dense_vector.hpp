#ifndef DENSE_VECTOR_HPP
#define DENSE_VECTOR_HPP
#include "abstract_vector.hpp"
// for std::size_t
#include <cstddef>
template<typename T>
class DenseVector : public AbstractVector<T>
{
public:

    // constructor
    DenseVector() = default;

    DenseVector(std::size_t length);

    // copy constructor
    DenseVector(const DenseVector<T>& rhs);

    // copy assignment
    DenseVector& operator=(const DenseVector<T>& rhs);

    // move constructor
    DenseVector(DenseVector<T>&& rhs);

    // copy move assignment
    DenseVector<T>& operator=(DenseVector<T>&& rhs);

    // destructor
    ~DenseVector();

    // return the number of items in the list
    std::size_t length() const noexcept;

    const T& operator()(std::size_t index) const;

    T& operator()(std::size_t index);

private:
    std::size_t m_size = 0;
    T* m_data = nullptr;
};
#include "dense_vector.tpp"
#endif

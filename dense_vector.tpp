#include "dense_vector.hpp"

#include <algorithm>
#include <stdexcept>
//constuctor
template<typename T>
DenseVector<T>::DenseVector(std::size_t length) {
    m_size = length;//initialize m_size
    m_data = new T[m_size]; //new allocate
    //set the m_data to be default value
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = T();
    }
}

//destructor
template <typename T>
DenseVector<T>::~DenseVector() {
    delete[] m_data;

}

//copy constructor
template <typename T>
DenseVector<T>::DenseVector(const DenseVector<T>& rhs) {
    m_size = rhs.m_size;
    m_data = new T[m_size];

    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = rhs.m_data[i];
    }
}

//move constructor
template <typename T>
DenseVector<T>::DenseVector(DenseVector<T>&& rhs) {
    std::swap(m_size, rhs.m_size);
    std::swap(m_data, rhs.m_data);
}

//assignment 
template <typename T>
DenseVector<T>& DenseVector<T>::operator=(const DenseVector<T>& rhs) {
    if (m_size < rhs.m_size) {//new allocate space
        delete[]m_data;
            //m_size 
        m_size = rhs.m_size;
        m_data = new T[m_size];
    }
    for (std::size_t i = 0; i < rhs.m_size; ++i) {
        m_data[i] = rhs.m_data[i];
    }
    m_size = rhs.m_size;
    return *this;
}

//move assignment operator
template <typename T>
DenseVector<T>& DenseVector<T>::operator=(DenseVector<T>&& rhs) {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    std::swap(m_size, rhs.m_size);
    std::swap(m_data, rhs.m_data);
    return *this;
}


template <typename T>
std::size_t DenseVector<T>::length() const noexcept {
    return m_size;
}

template <typename T>
const T& DenseVector<T>::operator()(std::size_t index) const {
    if (index == 0 || index >= m_size + 1) {
        throw std::invalid_argument("invalid position in vector");
    }
    return m_data[index - 1]; //return a copy
}

template <typename T>
T& DenseVector<T>::operator()(std::size_t index) {
    if (index == 0 || index >= m_size + 1) {
        throw std::invalid_argument("invalid position in vector");
    }
    return m_data[index-1];
}

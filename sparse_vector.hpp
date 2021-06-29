#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP
#include "abstract_vector.hpp"
// for std::size_t
#include <cstddef>
template<typename T>
class SparseVector : public AbstractVector<T>
{
public:
    // default constructor
    SparseVector();

    SparseVector(std::size_t length);
    // copy constructor
    SparseVector(const SparseVector<T>& x);

    // move constructor
    SparseVector(SparseVector<T>&& x);

    // destructor
    ~SparseVector();

    // assignment
    SparseVector& operator=(const SparseVector<T>& x);

    // move assignment
    SparseVector& operator=(SparseVector<T>&& x);

    std::size_t length() const noexcept;

    const T& operator()(std::size_t index) const;

    T& operator()(std::size_t index);
    

private:
   template<typename U>
   struct Node {
       std::size_t position;
       U data;
       Node<U> * next = nullptr;
       Node<U> * prev = nullptr;
   };
   typedef Node<T>* NodePtr;
   Node<T> guard;
   T default_value = T();

   std::size_t size = 0;
   void clear();
};
#include "sparse_vector.tpp"
#endif

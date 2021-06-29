# Dense-Vector-Sparse-Vector-implemenation-
This project using dynamic arrays and linked lists to implement two versions of mathematical vectors.

Part I Dense Vector
Implement a templated concrete class DenseVector in the files dense_vector.hpp/dense_vector.tpp, conforming to the AbstractVector interface. It should have a constructor that sets the length of the vector. This class should use a dynamically allocated array to hold the values, and have value and move semantics.

Part II Sparse Vector
Implement a templated concrete class SparseVector in the files sparse_vector.hpp/sparse_vector.tpp, conforming to the AbstractVector interface. It should have a constructor that sets the length of the vector. This class should use a doubly linked list, sorted by index, to hold any non-default vector values, and have value and move semantics. Thus the number of linked-list nodes allocated should be limited to the number of non-zero entries (to the extent feasible).

Part III Basic Linear Algebra Operations
To test the various combinations of Dense/Sparse Vector implement the following generic operations in the files linalg.hpp/linalg.tpp.

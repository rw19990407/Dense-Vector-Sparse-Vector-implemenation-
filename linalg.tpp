#include "linalg.hpp"
#include <algorithm>
#include <stdexcept>
#include <cmath>
// compute the dot (inner) product of two vectors x . y
// throws std::invalid_argument of length(x) != length(y)
template<typename T>
T dot(const AbstractVector<T>& x, const AbstractVector<T>& y) {
	std::size_t x_length = x.length();
	std::size_t y_length = y.length();
	T dot_product = 0;
	if (x_length != y_length) {
		throw std::invalid_argument("vectors'length not equal");
	}
	
	else {
		
		for (std::size_t i = 1; i <= x_length; i++) {
			dot_product = dot_product + x(i) * y(i);
		}
		return dot_product;
	}
}

// compute the 1-norm (max absolute element) of a vector
template<typename T>
T norm1(const AbstractVector<T>& x) {
	T Norm = 0;
	std::size_t x_length = x.length();
	for (std::size_t i = 1; i <= x_length; i++) {
		if (x(i) > 0) {
			Norm = Norm + x(i);
		}
		else if  (x(i) < 0) {
			Norm = Norm - x(i);
		}
	}
	return Norm;
}

// compute the 2-norm (square root of the sum of elements squared) of a vector
template<typename T>
double norm2(const AbstractVector<T>& x) {
	double norm_2 = 0;
	std::size_t x_length = x.length();
	for (std::size_t i = 1; i <= x_length; i++) {
		norm_2 += x(i) * x(i);
	}
	norm_2 = sqrt(norm_2);
	return norm_2;
}


#include "catch.hpp"

#include "linalg.hpp"

TEST_CASE("dot product", "[linalg]") {

    DenseVector<float>v1(2);
    v1(1) = 1;
    v1(2) = 2;
    DenseVector<float>v2(2);
    v2(1) = 1;
    v2(2) = 2;
    dot(v1, v2);
    REQUIRE(dot(v1, v2) == 5);
    DenseVector<float>v3(3);

    SparseVector<float>v4(3);
    v4(1) = 1;
    v4(2) = 2;
    SparseVector<float>v5(3);
    v5(1) = 1;
    v5(2) = 2;
   // dot(v5, v4);

   // REQUIRE(dot(v5, v4) == 5); 
    SparseVector<float>v6(10);
    REQUIRE_THROWS_AS(dot(v5, v6), std::invalid_argument);
}
TEST_CASE("norm", "[linalg]") {

    DenseVector<float>v1(3);
    v1(1) = -1;
    v1(2) = 2;
    v1(3) = 3;
    norm1(v1);
    REQUIRE(norm1(v1) == 6);
    norm2(v1);
    REQUIRE(norm2(v1) == sqrt(14));

    SparseVector<float>v2(3);
    v2(1) = 1;
    v2(2) = 2;
    v2(3) = 3;
    norm1(v2);
    REQUIRE(norm1(v2) == 6);
    norm2(v2);
    REQUIRE(norm2(v2) == sqrt(14));
}



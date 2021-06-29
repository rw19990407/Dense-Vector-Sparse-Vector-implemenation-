#include "catch.hpp"

#include "sparse_vector.hpp"

TEST_CASE("Test basic operations", "[SparseVector]") {

    SparseVector<int> vector(100);
    vector(5) = 50;
    REQUIRE(vector.length() == 100);
    vector(3) = 30;
    REQUIRE(vector(5) == 50);
    REQUIRE(vector(3) == 30);
    vector(5) = 30;
    REQUIRE(vector(5) == 30);
    REQUIRE(vector(1) == 0);
}    

TEST_CASE("Test value semantics on SparseVector", "[SparseVector]") {

    SparseVector<int> vector1(100);
    const SparseVector<int> v(100000);
    REQUIRE(v.length() == 100000);
    vector1(1) = 5;
    vector1(2) = 1;
    vector1(3) = 2;
    CHECK(vector1(1) == 5);
    CHECK(vector1(2) == 1);
    CHECK(vector1(3) == 2); 
    REQUIRE(vector1.length() == 100);

    const SparseVector<int> vector2 = vector1;
    CHECK(vector2(1) == 5);
    CHECK(vector2(2) == 1);
    CHECK(vector2(3) == 2);
    REQUIRE(vector2.length() == 100);

    SparseVector<int> vector3;
    vector3 = vector1; 
    CHECK(vector3(1) == 5);
    CHECK(vector3(2) == 1);
    CHECK(vector3(3) == 2);
    REQUIRE(vector3.length() == 100);

}

TEST_CASE("Test move semantics", "[SparseVector]") {

    SparseVector<int> vector(100);
    vector(1) = 1;
    vector(2) = 2;
    REQUIRE(vector(1) == 1);
    REQUIRE(vector(2) == 2);
    REQUIRE(vector.length() == 100);

    SparseVector<int> newvector = std::move(vector);
    REQUIRE(vector.length() == 0);
    REQUIRE(newvector(1) == 1);
    REQUIRE(newvector(2) == 2);
    REQUIRE(newvector.length() == 100);

    SparseVector<int> anothervector;
    anothervector = std::move(newvector);
    REQUIRE(anothervector(1) == 1);
    REQUIRE(anothervector(2) == 2);
    REQUIRE(anothervector.length() == 100);
    REQUIRE(newvector.length() == 0);

    SparseVector<double> v1(10000);
    v1(500) = 42.42;
    const SparseVector<double> v2 = v1;
    for (std::size_t i = 1; i <= v2.length(); ++i) {
        if (i == 500)
        {
            REQUIRE(v2(i) == 42.42);
        }
        else { REQUIRE(v2(i) == 0.0); }
    }
    
}


#include "catch.hpp"

#include "dense_vector.hpp"

TEST_CASE("vector test", "[vector]") {

	DenseVector<int>a;
	REQUIRE(a.length() == 0);

    const DenseVector<int> a2 = a;
    DenseVector<int> a3;
    a3 = a;
    REQUIRE(a2.length() == 0);
    REQUIRE(a3.length() == 0);
        //move constructor
    DenseVector<int> b1;
    DenseVector<int> b2 = std::move(b1);
    REQUIRE(b2.length() == 0);
    REQUIRE(b1.length() == 0);

    //move assignment
    DenseVector<int> b3;
    b3 = std::move(b2);
    REQUIRE(b3.length() == 0);
    REQUIRE(b1.length() == 0);
    REQUIRE(b2.length() == 0);
}

TEST_CASE("vector test 2  ", "[vector]") {
    DenseVector<int> c(12);
    c(1) = 1;
    REQUIRE(c(1) == 1);
    REQUIRE(c.length() == 12);
    const DenseVector<int> c2 = c;
    DenseVector<int> c3;
    c3 = c;
    REQUIRE(c2.length() == 12);
    REQUIRE(c3.length() == 12);
    REQUIRE(c2(1) == 1);
    REQUIRE(c3(1) == 1);




    DenseVector<int> d(50);
    DenseVector<int> d1 = std::move(d);
    REQUIRE(d1.length() == 50);
    REQUIRE(d.length() == 0);
    //move assignment
    DenseVector<int> d2;
    d2 = std::move(d1);
    REQUIRE(d2.length() == 50);
    REQUIRE(d1.length() == 0);
    REQUIRE_THROWS_AS(d1(0) = 0, std::invalid_argument);
}


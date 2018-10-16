#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "max-submatrix.cpp"

TEST_CASE("test provided") {
    std::istringstream in("3 4\n"
                          "2 -9 2 3\n"
                          "1 4 5 1\n"
                          "-2 3 4 1");
    REQUIRE(sumMaxSubMatrix(in) == 18);
}

TEST_CASE("all negative") {
    std::istringstream in("3 4\n"
                          "-1 -1 -1 -1\n"
                          "-1 -1 -1 -1\n"
                          "-1 -1 -1 -1");
    REQUIRE(sumMaxSubMatrix(in) == 0);
}

TEST_CASE("all positive") {
    std::istringstream in("3 3\n"
                          "1 1 1\n"
                          "1 1 1\n"
                          "1 1 1");
    REQUIRE(sumMaxSubMatrix(in) == 9);
}

TEST_CASE("right-bottom matrix") {
    std::istringstream in("3 3\n"
                          "-1 0 -1\n"
                          "-2 3 3\n"
                          "-1 0 3");
    REQUIRE(sumMaxSubMatrix(in) == 9);
}

TEST_CASE("left-bottom value") {
    std::istringstream in("4 4\n"
                          "-1 0 -1 -3\n"
                          "-2 3 3 -1\n"
                          "-1 0 3 -5\n"
                          "20 0 -3 -2");
    REQUIRE(sumMaxSubMatrix(in) == 23);
}

TEST_CASE("middle matrix") {
    std::istringstream in("4 4\n"
                          "-1 0 -1 -3\n"
                          "-2 3 3 -1\n"
                          "-1 0 3 -5\n"
                          "-1 0 -3 -2");
    REQUIRE(sumMaxSubMatrix(in) == 9);
}

TEST_CASE("single value") {
    std::istringstream in("4 4\n"
                          "-1 0 -1 -3\n"
                          "-2 3 -1 -1\n"
                          "-1 0 3 -5\n"
                          "20 0 -3 -2");
    REQUIRE(sumMaxSubMatrix(in) == 20);
}
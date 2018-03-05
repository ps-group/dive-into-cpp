// Макрос заставит Catch самостоятельно добавить определение функции main()
// Это можно сделать только в одном файле
#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

int Square(int value)
{
    int square = value;
    square = square * value;
    return square;
}

TEST_CASE("Squares are computed", "[Square]")
{
    REQUIRE(Square(1) == 1);
    REQUIRE(Square(2) == 4);
    REQUIRE(Square(3) == 9);
    REQUIRE(Square(7) == 49);
    REQUIRE(Square(10) == 100);
}

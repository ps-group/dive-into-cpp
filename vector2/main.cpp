// Макрос заставит Catch самостоятельно добавить определение функции main()
// Это можно сделать только в одном файле
#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

// Включаем заголовок, где мы описали структуру
#include "Vector2f.hpp"

// В C++ есть много способов вызвать один и тот же конструктор.
// Мы попробуем большинство из них.
TEST_CASE("Can be constructed", "[Vector2f]")
{
    // Обычное конструирование при объявлении.
    Vector2f v1(1, 2);
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);

    // Явный вызов конструктора, затем присваивание.
    Vector2f v2 = Vector2f(-1, 29);
    REQUIRE(v2.x == -1);
    REQUIRE(v2.y == 29);

    // Конструирование списком инициализации (C++11) - более универсальный приём.
    Vector2f v3 = { 5, -11 };
    REQUIRE(v3.x == 5);
    REQUIRE(v3.y == -11);

    // Универсальное конструирование (C++11) - ещё более универсальное
    Vector2f v4 = { 18, -110 };
    REQUIRE(v4.x == 18);
    REQUIRE(v4.y == -110);
}

TEST_CASE("Can compute length", "[Vector2f]")
{
    // Пифагоровы числа: 3, 4, 5
    Vector2f v1 = {3.f, 4.f};
    REQUIRE(v1.length() == Approx(5.f));

    // Пифагоровы числа: 12, 35, 37
    Vector2f v2 = {12.f, 35.f};
    REQUIRE(v2.length() == Approx(37.f));

    // Пифагоровы числа: 85 132 157
    Vector2f v3 = {85.f, -132.f};
    REQUIRE(v3.length() == Approx(157.f));

    // Пифагоровы числа: 799 960 1249
    Vector2f v4 = {799.f, -960.f};
    REQUIRE(v4.length() == Approx(1249.f));

    // Пифагоровы числа: 893 924 1285
    Vector2f v5 = {893.f, -924.f};
    REQUIRE(v5.length() == Approx(1285.f));
}

TEST_CASE("Can sum vectors", "[Vector2f]")
{
    Vector2f v1 = Vector2f{3, 5} + Vector2f{5, -5};
    REQUIRE(v1.x == 8);
    REQUIRE(v1.y == 0);

    Vector2f v2 = Vector2f{11, -6} + Vector2f{-6, 11};
    REQUIRE(v2.x == 5);
    REQUIRE(v2.y == 5);

    Vector2f v3 = Vector2f{11.2f, -6.71f} + Vector2f{-6.2f, 11.72f};
    REQUIRE(v3.x == Approx(5.f));
    REQUIRE(v3.y == Approx(5.01f));
}

TEST_CASE("Calculates dot product", "[Vector2f]")
{
    float d1 = dot(Vector2f{3, 5}, Vector2f{5, -5});
    REQUIRE(d1 == -10);

    float d2 = dot(Vector2f{11, -6}, Vector2f{6, 11});
    REQUIRE(d2 == 0);

    float d3 = dot(Vector2f{-1, 1}, Vector2f{-3, 2});
    REQUIRE(d3 == 5);
}

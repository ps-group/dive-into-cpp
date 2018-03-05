// Макрос заставит Catch самостоятельно добавить определение функции main()
// Это можно сделать только в одном файле
#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

// Включаем заголовок, где мы описали структуру
#include "Vector3f.hpp"

// В C++ есть много способов вызвать один и тот же конструктор.
// Мы попробуем большинство из них.
TEST_CASE("Can be constructed", "[Vector3f]")
{
    // Обычное конструирование при объявлении.
    Vector3f v1(1, 2, 5);
    REQUIRE(v1.x == 1);
    REQUIRE(v1.y == 2);
    REQUIRE(v1.z == 5);

    // Явный вызов конструктора, затем присваивание.
    Vector3f v2 = Vector3f(-1, 29, 42);
    REQUIRE(v2.x == -1);
    REQUIRE(v2.y == 29);
    REQUIRE(v2.z == 42);

    // Конструирование списком инициализации (C++11) - более универсальный приём.
    Vector3f v3 = {5, -11, -5.5f};
    REQUIRE(v3.x == 5);
    REQUIRE(v3.y == -11);
    REQUIRE(v3.z == -5.5f);

    // Универсальное конструирование (C++11) - ещё более универсальное
    Vector3f v4 = {18, -110, 0.1f};
    REQUIRE(v4.x == 18);
    REQUIRE(v4.y == -110);
    REQUIRE(v4.z == 0.1f);
}

TEST_CASE("Calculates distance", "[Vector3f]")
{
    float d1 = distance(Vector3f{3, 5, 1}, Vector3f{5, -5, 0});
    REQUIRE(d1 == Approx(10.247f));

    float d2 = distance(Vector3f{1, 2, 1}, Vector3f{2, -7, 5});
    REQUIRE(d2 == Approx(9.8994949366f));

    float d3 = distance(Vector3f{1, 0, 1}, Vector3f{1, 0, 0});
    REQUIRE(d3 == Approx(1.0f));
}
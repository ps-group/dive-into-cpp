// Макрос заставит Catch самостоятельно добавить определение функции main()
// Это можно сделать только в одном файле
#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

// Включаем заголовок, где мы описали структуру
#include "Vector3f.hpp"

// Тест функции cross()
TEST_CASE("Can cross vectors", "[Vector3f]")
{
    // Обычное конструирование при объявлении.
    Vector3f v1, v2, v3; 
    v1.x = 0.0;
    v1.y = 0.0;
    v1.x = 0.0;
    v2.x = 0.0;
    v2.y = 0.0;
    v2.z = 0.0;
    v3 = cross(v1, v2);
    REQUIRE(v3.x == 0.0);
    REQUIRE(v3.y == 0.0);
    REQUIRE(v3.z == 0.0);

    // Конструирование списком инициализации (C++11).      
    Vector3f v4 = {4.0, 5.0, 6.0};
    Vector3f v5 = {7.0, 8.0, 9.0};
    Vector3f v6 = cross(v4, v5);
    REQUIRE(v6.x == 6.0);
    REQUIRE(v6.y == 10.0);
    REQUIRE(v6.z == -8.0);

    // Конструирование списком инициализации (C++11).     
    Vector3f v7 = {-1.0, -1.0, -1.0};
    Vector3f v8 = {1.0, 1.0, 1.0};
    Vector3f v9 = cross(v7, v8);
    REQUIRE(v9.x == 0.0);
    REQUIRE(v9.y == 0.0);
    REQUIRE(v9.z == 0.0);
    
    // Конструирование списком инициализации (C++11).  
    Vector3f v10 = cross(Vector3f{1.0, 1.0, 1.0}, Vector3f{1.0, 1.0, 1.0});
    REQUIRE(v10.x == 0.0);
    REQUIRE(v10.y == 0.0);
    REQUIRE(v10.z == 0.0);
}

TEST_CASE("Division operator", "[Vector3f]")
{
    // Проверка operator /
    Vector3f v1{2, 4, 6};
    Vector3f v2 = v1 / 2;
    REQUIRE(v2.x == Approx(1));
    REQUIRE(v2.y == Approx(2));
    REQUIRE(v2.z == Approx(3));

    Vector3f v3{12.6f, 15.2f, -14.8f};
    v3 = v3 / 2.5f;
    REQUIRE(v3.x == Approx(5.04f));
    REQUIRE(v3.y == Approx(6.08f));
    REQUIRE(v3.z == Approx(-5.92f));

    // Проверка operator /=
    Vector3f v4{3, 6, 9};
    v4 /= 3;
    REQUIRE(v4.x == Approx(1));
    REQUIRE(v4.y == Approx(2));
    REQUIRE(v4.z == Approx(3));

    Vector3f v6{-2.5f, -7.5f, -12.5f};
    v6 /= -2.5f;
    REQUIRE(v6.x == Approx(1));
    REQUIRE(v6.y == Approx(3));
    REQUIRE(v6.z == Approx(5));
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

TEST_CASE("Multiply vectors on scal", "[Vector3f]")
{
    Vector3f v1 = Vector3f{2, 3, 4} * (-4);
    REQUIRE(v1.x == -8);
    REQUIRE(v1.y == -12);
    REQUIRE(v1.z == -16);

    Vector3f v2 = Vector3f{10, -6, 2} * 1;
    REQUIRE(v2.x == 10);
    REQUIRE(v2.y == -6);
    REQUIRE(v2.z == 2);

    Vector3f v3 = Vector3f{1, -1, 2} * 2;
    REQUIRE(v3.x == 2);
    REQUIRE(v3.y == -2);
    REQUIRE(v3.z == 4);

    Vector3f v4 = Vector3f{0, -3, 8} * 2;
    REQUIRE(v4.x == 0);
    REQUIRE(v4.y == -6);
    REQUIRE(v4.z == 16);
}

TEST_CASE("Normalize", "[Vector3f]")
{
    Vector3f v1 = normalize(Vector3f{2, 3, 4});
    REQUIRE(v1.x == Approx(0.371391f));
    REQUIRE(v1.y == Approx(0.557086f));
    REQUIRE(v1.z == Approx(0.742781f));
}

TEST_CASE("Comparison operators", "[Vector3f]")
{
    // Обычное конструирование при объявлении.
    Vector3f v1(1, 2, 5);
    Vector3f v2(1, 2, 5);
    REQUIRE(v1 == v1);
    REQUIRE(v1 == v2);
    REQUIRE((v1 != v2) == false);

    Vector3f v3(2, 0, 1);
    REQUIRE((v1 == v3) == false);
    REQUIRE(v1 != v3);
}

TEST_CASE("Subtraction operator", "[Vector3f]")
{
	// Проверка оператор вычитания /
	Vector3f v1{ 8, 6, 4 };
	Vector3f v2{ 4, 3, -4 };

	Vector3f v3 = v1 - v2;
	REQUIRE(v3.x == Approx(4));
	REQUIRE(v3.y == Approx(3));
	REQUIRE(v3.z == Approx(8));


	Vector3f v3 -= v1;
	REQUIRE(v3.x == Approx(-4));
	REQUIRE(v3.y == Approx(-3));
	REQUIRE(v3.z == Approx(4));
}
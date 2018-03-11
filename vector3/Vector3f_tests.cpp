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


#pragma once

// Структура, моделирующая трёхмерный вектор
struct Vector3f
{
    float x = 0;
    float y = 0;
    float z = 0;

    // Для конструктора без аргументов нас устраивает реализация по умолчанию
    Vector3f() = default;

    // Констуктор, принимающий три аргумента x, y, z
    Vector3f(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    // Возвращает длину (модуль) вектора
    /*
    float length() const
    {
    }
    */

    // Возвращает сумму двух векторов
    /*
    Vector3f operator+(const Vector3f& other) const
    {
    }
    */

    // Добавляет к вектору переданный вектор
    /*
    Vector3f& operator+=(const Vector3f& other)
    {
    }
    */

    // Возвращает разность двух векторов
    /*
    Vector3f operator-(const Vector3f& other) const
    {
    }
    */

    // Вычитает из вектора переданный вектор
    /*
    Vector3f& operator-=(const Vector3f& other)
    {
    }
    */

    // Возвращает покомпонентное произведение вектора на скаляр
    /*
    Vector3f operator*(float scale) const
    {
    }
    */

    // Умножает покомпонентно вектор на переданный скаляр
    /*
    Vector3f& operator*=(float scale)
    {
    }
    */

    // Выполняет покомпонентное сравнение двух векторов на равенство
    /*
    bool operator==(const Vector3f& a, const Vector3f& a) const
    {
    }
    */

    // Выполняет покомпонентное сравнение двух векторов на неравенство
    /*
    bool operator!=(const Vector3f& a, const Vector3f& a) const
    {
    }
    */
};

// Возвращает скалярное произведение двух векторов.
/*
inline float dot(const Vector3f& a, const Vector3f& b)
{
}
*/

// Возвращает векторное произведение двух векторов.
// См. https://www.mathsisfun.com/algebra/vectors-cross-product.html
/*
inline Vector3f cross(const Vector3f& a, const Vector3f& b)
{
}
*/

// Возвращает расстояние между двумя векторами в виде числа
/*
inline float distance(const Vector3f& a, const Vector3f& b)
{
}
*/

// Возвращает нормализованный вектор (вектор единичной длины, имеющий то же направлени)
/*
inline Vector3f normalize(const Vector3f& value)
{
}
*/

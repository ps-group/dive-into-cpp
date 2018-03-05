#pragma once
#include <cmath>

// Структура, моделирующая двумерный вектор
struct Vector2f
{
    float x = 0;
    float y = 0;

    Vector2f() = default;

    Vector2f(float x, float y)
        : x(x), y(y)
    {
    }

    float length() const
    {
        return std::hypot(x, y);
    }

    Vector2f operator+(const Vector2f& other) const
    {
        return { x + other.x, y + other.y };
    }

    Vector2f& operator+=(const Vector2f& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
};

inline float dot(const Vector2f& a, const Vector2f& b)
{
    return a.x * b.x + a.y * b.y;
}

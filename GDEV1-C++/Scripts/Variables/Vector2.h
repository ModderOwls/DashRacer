#include <iostream>
#pragma once


class Vector2 {
private:

public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	float magnitude();
	float magnitudeSqr();

	Vector2& operator=(const Vector2& other);
	Vector2& operator+=(const Vector2& other);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const float& other);

	Vector2 lerp(const Vector2& other, float time);

	float x, y;
};
#include <iostream>
#include <cassert>
#include <cmath>

#include "Vector2.h"


Vector2::Vector2() 
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y) 
{ 
	this->x = x;
	this->y = y;
}

Vector2::~Vector2() { }

float Vector2::magnitudeSqr()
{
	float sum = x * x + y * y;

	return sum;
}

float Vector2::magnitude()
{
	float sum = x * x + y * y;

	return sqrtf(sum);
}

Vector2 Vector2::lerp(const Vector2& other, float time) {
	Vector2 newVector = *this;

	newVector += (*this - other) * time;

	return newVector;
}


#pragma region operators

Vector2& Vector2::operator=(const Vector2& other) {
	x = other.x;
	y = other.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& other) {
	Vector2 newVector;
	
	newVector.x = x + other.x;
	newVector.y = y + other.y;

	return newVector;
}

Vector2 Vector2::operator-(const Vector2& other) {
	Vector2 newVector;

	newVector = Vector2(x - other.x, y - other.y);

	return newVector;
}

Vector2 Vector2::operator*(const float& multiplier) {
	Vector2 newVector;

	newVector = Vector2(x * multiplier, y * multiplier);

	return newVector;
}

#pragma endregion
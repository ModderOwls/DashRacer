#include <iostream>

#include "..\Time.h"

#include "..\Variables/Vector2.h"

#pragma once


class Rigidbody {
private:
	Vector2 previousPosition;
public:
	Rigidbody();

	Vector2 position;
	Vector2 tickPosition;
	Vector2 velocity;

	void setPosition(const Vector2& newPosition);
	Vector2& getPosition();
	void addForce(const Vector2& force);
	void setForce(const Vector2& force);

	virtual void update();
	virtual void tickUpdate();
};

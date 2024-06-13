#include <iostream>

#include "..\Time.h"

#include "..\Variables/Vector2.h"

#pragma once


class Collider {
private:
	float radius;
public:
	Collider();
	
	Vector2 position;

	void setRadius(const float& radius);
	const float getRadius();
	virtual void onCollision(const Collider& collider);
};

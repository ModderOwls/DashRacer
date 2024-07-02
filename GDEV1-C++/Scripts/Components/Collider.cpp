#include "Collider.h"


Collider::Collider()
{
	position = Vector2();
	radius = 0;
}

void Collider::setRadius(const float& newRadius)
{
	radius = newRadius;
}

void Collider::onCollision(const Collider& collider) { }

const float Collider::getRadius() 
{
	return radius;
}
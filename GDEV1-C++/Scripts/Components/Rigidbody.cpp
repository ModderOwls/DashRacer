#include "Rigidbody.h"

#include "../Time.h"


Rigidbody::Rigidbody() 
{
	position = Vector2();

	velocity = Vector2();
}

void Rigidbody::update()
{
	Time& instanceTime = Time::getInstance();
	position = tickPosition.lerp(previousPosition, instanceTime.tickLerpValue);
}

void Rigidbody::tickUpdate()
{
	previousPosition = tickPosition;

	Time& instanceTime = Time::getInstance();
	tickPosition += velocity * instanceTime.timeScale;
}

void Rigidbody::setPosition(const Vector2& newPosition) {
	position = newPosition;
	tickPosition = newPosition;
	previousPosition = newPosition;
}

Vector2& Rigidbody::getPosition() 
{
	return position;
}

void Rigidbody::addForce(const Vector2& force)
{
	velocity += force;
}

void Rigidbody::setForce(const Vector2& force)
{
	velocity = force;
}
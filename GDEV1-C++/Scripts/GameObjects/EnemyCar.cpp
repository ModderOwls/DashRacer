#include "EnemyCar.h"

#include <random>

#include "../Time.h"
#include "../Physics.h"
#include "../GameRules.h"

#include "../Variables/Vector2.h"

#include <SFML/Graphics/Texture.hpp>


EnemyCar::EnemyCar()
{
	DrawObject::setTexture("Sprites/CarEnemy.png");

	Collider::setRadius(40);

	ResetCar();
}

void EnemyCar::update()
{
	Rigidbody::update();

	DrawObject::position = Rigidbody::position;

	DrawObject::update();

	//if the car got hit will spin around out of control!
	if (hit) 
	{
		DrawObject::sprite.rotate(480*deltaTime.asSeconds());
	} else
	{
		DrawObject::sprite.setRotation(Rigidbody::velocity.x * 2);
	}
}

void EnemyCar::tickUpdate()
{
	Rigidbody::tickUpdate();
	DrawObject::tickUpdate();
	Collider::position = Rigidbody::tickPosition;

	//Keep Enemy in bound as to not go off-road.
	if (Rigidbody::tickPosition.x < 230) {
		Rigidbody::tickPosition.x = 230;
		Rigidbody::velocity.x *= -1;
	}
	if (Rigidbody::tickPosition.x > 640) {
		Rigidbody::tickPosition.x = 640;
		Rigidbody::velocity.x *= -1;
	}

	if (hit) 
	{
		if (Rigidbody::tickPosition.y < -60) {
			ResetCar();
		}

		Rigidbody::velocity = Vector2(Rigidbody::velocity.x, speed);
	}
	else 
	{
		//The enemy car has reached the bottom meaning you have evaded them!
		if (Rigidbody::tickPosition.y > 530) {
			ResetCar();
			addPoints(1);
		}

		Rigidbody::velocity = Vector2(Rigidbody::velocity.x, speed * carSpeed);
	}
}

//Reset the car to as new.
void EnemyCar::ResetCar() 
{
	DrawObject::sprite.setRotation(0);

	hit = false;
	int random = rand() % 4;
	float randomSpeedX = rand() % 5 - 2;
	speed = rand() % 5 + 4;
	Rigidbody::setPosition(Vector2(243 + 128 * random, -60));
	Rigidbody::setForce(Vector2(randomSpeedX, speed * carSpeed));
}

void EnemyCar::onCollision(const Collider& collider)
{
	if (!hit) {
		hit = true;

		speed = -6;
		Rigidbody::velocity = Vector2(Rigidbody::velocity.x * 6, -6);
	}
}
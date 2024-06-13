#include "Player.h"

#pragma once

int inputHorizontal;
int health;

Player::Player()
{
	DrawObject::setTexture("Sprites/CarPlayer.png");

	health = 3;

	Rigidbody::tickPosition = Vector2(427, 420);
	Rigidbody::velocity = Vector2(0, 0);

	Collider::setRadius(25);
}

void Player::update()
{
	Rigidbody::update();

	DrawObject::position = Rigidbody::position;

	DrawObject::sprite.setRotation(Rigidbody::velocity.x);

	DrawObject::update();
}

void Player::tickUpdate()
{
	Rigidbody::tickUpdate();
	DrawObject::tickUpdate();
	Collider::position = Rigidbody::tickPosition;

	inputHorizontal = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left);

	invulnerable++;
	castCollider(*this);

	Rigidbody::addForce(Vector2(0.9f * inputHorizontal, 0));
	if (inputHorizontal == 0) {
		Rigidbody::velocity.x *= 0.7f;
	}
	else {
		Rigidbody::velocity.x *= 0.92f;
	}

	if (carSpeed < 1)
	{
		carSpeed += 0.015f;

		//Ensure speed doesnt go above 1.
		if (carSpeed > 1) 
		{
			carSpeed = 1;
		}
	} 

	if (Rigidbody::tickPosition.x < 204) {
		Rigidbody::tickPosition.x = 204;
		Rigidbody::velocity.x = 0;
	} 
	if (Rigidbody::tickPosition.x > 666) {
		Rigidbody::tickPosition.x = 666;
		Rigidbody::velocity.x = 0;
	}
}

void Player::onCollision(const Collider& collider) 
{
	if (invulnerable > 0) 
	{
		carSpeed = 0;
		--health;

		invulnerable = -50;

		if (health <= 0) 
		{
			won = false;
			lose = true;

			timeScale = 0.0f;
		}
	}
}
#include <iostream>

#include "..\Time.h"
#include "..\Physics.h"
#include "..\GameRules.h"

#include "..\Variables/Vector2.h"

#include "..\Components/Object.h"
#include "..\Components/DrawObject.h"
#include "..\Components/Rigidbody.h"
#include "..\Components/Collider.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>

#pragma once

class Player : public Rigidbody, public DrawObject, public Collider, public Object {
private:
	//Invulnerability frames/ticks. Ensures you dont get hit multiple times unfairly.
	int invulnerable;
	int health;
public:
	Player();

	void update() override;
	void tickUpdate() override;

	void onCollision(const Collider& collider) override;
};

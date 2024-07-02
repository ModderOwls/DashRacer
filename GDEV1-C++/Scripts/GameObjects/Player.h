#pragma once

#include "../Components/Object.h"
#include "../Components/DrawObject.h"
#include "../Components/Rigidbody.h"
#include "../Components/Collider.h"


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

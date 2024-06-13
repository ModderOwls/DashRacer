#include <iostream>
#include <random>

#include "..\Time.h"
#include "..\Physics.h"
#include "..\GameRules.h"

#include "..\Variables/Vector2.h"

#include "..\Components/Object.h"
#include "..\Components/DrawObject.h"
#include "..\Components/Rigidbody.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>

#pragma once

class EnemyCar : public Rigidbody, public DrawObject, public Collider, public Object {
private:
	float speed;
	bool hit = false;

public:
	EnemyCar();

	void ResetCar();

	void update() override;
	void tickUpdate() override;

	void onCollision(const Collider& collider) override;
};

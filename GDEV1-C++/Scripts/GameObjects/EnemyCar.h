#pragma once

#include "../Components/Object.h"
#include "../Components/DrawObject.h"
#include "../Components/Rigidbody.h"
#include "../Components/Collider.h"


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

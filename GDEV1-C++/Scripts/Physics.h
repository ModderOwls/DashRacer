#pragma once

#include <iostream>
#include <vector>

#include "Components/Collider.h"


class Physics {
private:
	Physics();

public:
	Physics(Physics const&) = delete;
	void operator=(Physics const&) = delete;

	static Physics& getInstance();


	std::vector<std::shared_ptr<Collider>> colliders;

	void castCollider(Collider& collider);
};
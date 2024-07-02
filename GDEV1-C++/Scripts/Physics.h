#pragma once

#include <iostream>
#include <vector>

#include "Components/Collider.h"


extern std::vector<std::shared_ptr<Collider>> colliders;

extern void castCollider(Collider& collider);
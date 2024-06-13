#include <iostream>
#include <vector>

#include "Components/Collider.h"

using namespace std;
#pragma once

extern vector<shared_ptr<Collider>> colliders;

extern void castCollider(Collider& collider);
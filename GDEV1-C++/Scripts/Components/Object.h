#include <iostream>
#include <string> 

#include "..\Variables/Vector2.h"
#pragma once


class Object {
public:
	virtual void update();
	virtual void tickUpdate();
};
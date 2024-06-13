#include "GameRules.h"

#pragma once

int points = 0;
int pointsRequired = 25;
float carSpeed = 1;

bool won;
bool lose;

void addPoints(const int amount) 
{
	points += amount;

	if (points >= pointsRequired) 
	{
		won = true;
		lose = false;

		timeScale = 0.0f;
	}
}
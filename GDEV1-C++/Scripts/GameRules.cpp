#include "GameRules.h"

#include "Time.h"


GameRules::GameRules() {}

GameRules& GameRules::getInstance() {
	static GameRules instance;
	return instance;
}

void GameRules::addPoints(const int amount) 
{
	points += amount;

	if (points >= pointsRequired) 
	{
		won = true;
		lose = false;

		Time& instanceTime = Time::getInstance();
		instanceTime.timeScale = 0.0f;
	}
}
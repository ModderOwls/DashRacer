#include "Time.h"

#include <iostream>


Time::Time() {}

Time& Time::getInstance() {
	static Time instance;
	return instance;
}

void Time::initializeClock()
{
	updateClock = sf::Clock();
	deltaTime = updateClock.restart();
	timePassed = 0;
	tickLerpValue = 0;

	waitForTicks = 0;
}

void Time::restartClock()
{
	deltaTime = updateClock.restart() * timeScale;

	waitForTicks += deltaTime.asMicroseconds();
	timePassed += deltaTime.asSeconds();

	float tickRateF = tickRate;
	tickLerpValue = waitForTicks / tickRateF;
}
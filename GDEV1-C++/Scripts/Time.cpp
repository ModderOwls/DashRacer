#include "Time.h"


sf::Clock updateClock;
sf::Time deltaTime;
float timePassed;
float timeScale = 1;

//How often ticks happen. In microseconds, so every 20 milliseconds by default.
const int tickRate = 20000;
sf::Int64 waitForTicks;
float tickLerpValue;

void InitializeClock()
{
	updateClock = sf::Clock();
	deltaTime = updateClock.restart();
	timePassed = 0;
	tickLerpValue = 0;

	waitForTicks = 0;
}

void RestartClock()
{
	deltaTime = updateClock.restart() * timeScale;

	waitForTicks += deltaTime.asMicroseconds();
	timePassed += deltaTime.asSeconds();

	float tickRateF = tickRate;
	tickLerpValue = waitForTicks / tickRateF;
}
#pragma once

#include <SFML/System/Clock.hpp>


class Time {
private:
	Time();

public:
	Time(Time const&) = delete;
	void operator=(Time const&) = delete;

	static Time& getInstance();


	void initializeClock();
	void restartClock();

	sf::Clock updateClock;
	sf::Time deltaTime;
	float timePassed;
	float timeScale;

	//How often ticks happen. In microseconds, so every 20 milliseconds by default.
	const int tickRate = 20000;
	sf::Int64 waitForTicks;
	float tickLerpValue;
};
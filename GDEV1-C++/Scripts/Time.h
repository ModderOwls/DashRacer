#include <iostream>

#include <SFML/System/Clock.hpp>
#pragma once

extern sf::Clock updateClock;
extern sf::Time deltaTime;
extern float timePassed;
extern float timeScale;

//How often ticks happen. In microseconds, so every 20 milliseconds by default.
extern const int tickRate;
extern sf::Int64 waitForTicks;
extern float tickLerpValue;

extern void InitializeClock();
extern void RestartClock();
#pragma once


class GameRules {
private:
	GameRules();

public:
	GameRules(GameRules const&) = delete;
	void operator=(GameRules const&) = delete;

	static GameRules& getInstance();


	int points = 0;
	int pointsRequired = 25;
	float carSpeed = 1;

	bool won;
	bool lose;

	void addPoints(const int amount);
};
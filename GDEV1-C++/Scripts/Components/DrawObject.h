#pragma once

#include "../Variables/Vector2.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


class DrawObject {
private:
	sf::Texture texture;
public:
	DrawObject();

	Vector2 position;

	sf::Sprite sprite;

	void setTexture(const std::string& filename);

	virtual void update();
	virtual void tickUpdate();
};

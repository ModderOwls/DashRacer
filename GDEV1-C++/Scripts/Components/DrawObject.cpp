#include "DrawObject.h"


DrawObject::DrawObject() { }

void DrawObject::setTexture(const std::string& filename)
{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);

	sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
}

void DrawObject::update()
{
	sprite.setPosition(position.x, position.y);
}

void DrawObject::tickUpdate() { }
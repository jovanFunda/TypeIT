#pragma once

#include "SFML/Graphics.hpp"
#include "Math.h"

class GameObject
{
public:
	GameObject(std::string path, Point2D position);
	void loadSprite(std::string path);
	sf::Sprite sprite;

protected:
	sf::Texture m_Texture;
	Point2D m_position;
};
#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject(std::string path);
	void loadSprite(std::string path);
	sf::Sprite sprite;

protected:
	sf::Texture _Texture;
};
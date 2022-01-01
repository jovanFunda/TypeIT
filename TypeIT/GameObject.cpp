#include "GameObject.h"
#include <iostream>

GameObject::GameObject(std::string path, Point2D position) 
	: m_position(position)
{
	this->loadSprite(path);
	this->sprite.setPosition(position.x, position.y);
}

void GameObject::loadSprite(std::string path)
{
	this->m_Texture.loadFromFile(path);
	this->sprite.setTexture(this->m_Texture);
}
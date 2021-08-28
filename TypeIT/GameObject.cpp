#include "GameObject.h"

GameObject::GameObject(std::string path) 
{
	this->loadSprite(path);
}

void GameObject::loadSprite(std::string path)
{
	this->_Texture.loadFromFile(path);
	this->sprite.setTexture(this->_Texture);
}
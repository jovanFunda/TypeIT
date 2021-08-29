#pragma once

#include "SFML/Graphics.hpp"

#include "GameObject.h"
#include "Word.h"
#include "Math.h"

class Plane : public GameObject
{
public:
	Plane(std::string path, Point2D position);
	void rotateToWord(Word* word);
};


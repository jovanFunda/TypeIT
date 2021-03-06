#include "Plane.h"
#include "Math.h"

#include <cmath>

Plane::Plane(std::string path, Point2D position)
	: GameObject(path, position)
{
	sprite.setOrigin(24.f, 24.f);
}

void Plane::rotateToWord(Word* word) 
{
	Point2D planePos = Point2D(sprite.getPosition().x, sprite.getPosition().y);
	Point2D wordPos = Point2D(word->getText().getPosition().x, word->getText().getPosition().y);
	Point2D angle90 = Point2D(planePos.x, wordPos.y);

	int aS = Math::lengthSquare(angle90, wordPos);
	int bS = Math::lengthSquare(wordPos, planePos);
	int cS = Math::lengthSquare(planePos, angle90);

	float b = sqrt(bS);
	float c = sqrt(cS);

	float alpha = 0;

	if ((2 * b * c) != 0)
		alpha = acos((bS + cS - aS) / (2 * b * c));

	alpha = Math::radianToDegree(alpha);

	if (planePos.x > wordPos.x)
		alpha = 360 - alpha;

	sprite.setRotation(alpha);
}



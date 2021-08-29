#include "Math.h"

#include <cmath>

#define PI 3.1415926535

Point2D::Point2D(float x, float y)
{
	setPosition(x, y);
}

void Point2D::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Math::lengthSquare(Point2D point1, Point2D point2)
{
	float xDiff = point1.x - point2.x;
	float yDiff = point1.y - point2.y;
	return xDiff * xDiff + yDiff * yDiff;
}

float Math::lineLength(Point2D point1, Point2D point2)
{
	return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}

Point2D Math::pointBetween2Points(Point2D point1, Point2D point2, float min, float max)
{
	return Point2D(point1.x + min/max * (point2.x-point1.x), point1.y + min/max * (point2.y-point1.y));
}

float Math::radianToDegree(float radian)
{
	return radian * 180.f / PI;
}
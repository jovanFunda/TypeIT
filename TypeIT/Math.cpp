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

float Point2D::getX()
{
	return this->x;
}

float Point2D::getY()
{
	return this->y;
}

float Math::lengthSquare(Point2D point1, Point2D point2)
{
	int xDiff = point1.getX() - point2.getX();
	int yDiff = point1.getY() - point2.getY();
	return xDiff * xDiff + yDiff * yDiff;
}

float Math::lineLength(Point2D point1, Point2D point2)
{
	return sqrt(pow((point1.getX() - point2.getX()), 2) + pow((point1.getY() - point2.getY()), 2));
}

Point2D Math::pointBetween2Points(Point2D point1, Point2D point2, float min, float max)
{
	return Point2D(point1.getX() + min/max * (point2.getX()-point1.getX()), point1.getY() + min/max * (point2.getY()-point1.getY()));
}

float Math::radianToDegree(float radian)
{
	return radian * 180 / PI;
}
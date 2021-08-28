#pragma once

class Point2D
{
public:

	Point2D(float x, float y);
	void setPosition(float x, float y);
	float getX();
	float getY();

private:
	float x, y;
};

class Math
{
public:
	static float lengthSquare(Point2D, Point2D);
	static float lineLength(Point2D, Point2D);
	static float radianToDegree(float);
	static Point2D pointBetween2Points(Point2D, Point2D, float min, float max);
};
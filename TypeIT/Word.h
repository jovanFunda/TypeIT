#pragma once

#include "SFML/Graphics.hpp"
#include "Math.h"

class Word
{
public:

	Word();
	void setPosition(Point2D);
	void startMoving();
	void loadWord();
	Point2D getPosition();
	std::string getString();
	sf::Text getText();

	float step = 1;

private:
	sf::Text m_text;
	sf::Clock m_clock;
	sf::Font m_font;
	float startingX;
	float startingY;
	static std::string words[32];
};


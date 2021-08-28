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
	float i = 1;

private:
	sf::Text m_text;
	sf::Font m_font;
	sf::Clock m_clock;
	std::string m_string;
	float startingX;
	float startingY;
	static std::string words[32];
};


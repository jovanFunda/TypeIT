#include <time.h>

#include "Game.h"
#include "Word.h"

Word::Word()
{
	srand(time(NULL));
	loadWord();
	setPosition(Point2D(rand() % 650, 0));
	startingX = this->getPosition().x;
	startingY = this->getPosition().y;
	m_text.setOrigin(m_text.getLocalBounds().width / 2, 0);
}

void Word::loadWord()
{
	srand(time(NULL));
	std::string wordText = words[rand() % 32];
	m_font.loadFromFile("assets/fonts/couture-bldit.ttf");
	this->m_text.setString(wordText);
	this->m_text.setFont(m_font);
}

void Word::startMoving()
{
	sf::Time timer = m_clock.getElapsedTime();

	if (timer.asSeconds() > 0.005f)
	{
		if (step == Game::getWordSpeed())
		{
			//GAME OVER
			step = -1;
			return;
		}

		step++;
		this->setPosition(Math::pointBetween2Points(Point2D(this->startingX, this->startingY), Point2D(400.f, 800.f), step, Game::getWordSpeed()));
		m_clock.restart();
	}
}

void Word::setPosition(Point2D point)
{
	m_text.setPosition(point.x, point.y);
}

Point2D Word::getPosition()
{
	return Point2D(this->m_text.getPosition().x, this->m_text.getPosition().y);
}

sf::Text Word::getText() 
{
	return m_text;
}

std::string Word::getString()
{
	return m_text.getString();
}

std::string Word::words[32] = { "flower", "football", "desk", "table", "karate", "bookshelf", "cocacola", "speaker", "telephone", "clock", "cloudy", "virtual", "monitor", "paper", "passport", "numbers", "sponge", "hamburger", "mcdonalds", "survey", "epidemic", "attitude", "antena", "windows", "linux", "cactus", "networking", "computer", "system", "algebra", "euclidian", "major"};
#define SFML_NO_DEPRECATED_WARNINGS

#include <iostream>
#include <string>
#include <deque>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Plane.h"
#include "Game.h"
#include "Word.h"
#include "Math.h"

int Game::m_wordSpeed;
float Game::m_wordSpawnSpeed;
sf::Clock Game::m_clock;
int Game::m_score;
sf::RenderWindow Game::m_window(sf::VideoMode(800, 1000), "Keyboard racer", sf::Style::Titlebar | sf::Style::Close);
void setProperties(sf::Text*, sf::Color, Point2D);

int Game::Run()
{
	Plane plane("assets/images/plane.png", Point2D(400.f, 850.f));
	GameObject background("assets/images/background.jpg");
	m_window.setFramerateLimit(100);

	std::deque<Word*> words;
	m_wordSpeed = 500; // Decrease number and words will be faster 
	m_wordSpawnSpeed = 1.5f; // How much seconds between word spawning
	m_score = 0;

	int gameOver = 0;
	int finalScore = 0;
	
	float timer = m_wordSpawnSpeed; // Game immediately starts with one word
	int currentLetter = 0;

	sf::Text score;
	//setProperties(score, sf::Color(50, 50, 255, 255), Point2D(20, 20));
	sf::Font font;
	font.loadFromFile("assets/fonts/couture-bldit.ttf");
	score.setFont(font);
	score.setColor(sf::Color(50, 50, 255, 255));
	score.setPosition(20, 20);

	while (m_window.isOpen())
	{
		if (gameOver == 0)
		{
			timer += m_clock.restart().asSeconds();
			if (timer > m_wordSpawnSpeed)
			{
				words.push_back(new Word());
				timer = 0.f;
			}

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();

				if (event.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(words.front()->getString()[currentLetter] - 'a')))
					{
						std::cout << words.front()->getString()[currentLetter];
						currentLetter++;
						if (words.front()->getString()[currentLetter] == '\0')
						{
							// WORD FINISHED
							std::cout << std::endl;
							currentLetter = 0;
							m_score++;
							words.pop_front();
						}
					}
				}
			}

			plane.rotateToWord(words.front());

			m_window.clear(sf::Color::Black);
			m_window.draw(background.sprite);
			m_window.draw(plane.sprite);

			for (int i = 0; i < words.size(); i++)
			{
				if (words.at(i)->i == -1)
				{
					// GAME OVER
					gameOver = 1;
					finalScore = m_score;
					m_score = 0;
					words.pop_front();
				}

				(words.at(i))->startMoving();
				m_window.draw(words.at(i)->getText());
			}

			score.setString("Score " + std::to_string(m_score));
			m_window.draw(score);
		}
		else if (gameOver == 1)
		{
			sf::Text finalText;
			finalText.setString("Your score is " + std::to_string(finalScore));
			finalText.setFont(font);
			finalText.setColor(sf::Color(200, 200, 255, 255));
			finalText.setPosition(230, 400);

			m_window.clear(sf::Color::Black);
			m_window.draw(background.sprite);
			m_window.draw(finalText);

			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();

				if (event.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
					{
						gameOver = 0;
						timer = m_wordSpawnSpeed; // Game immediately starts with one word
						currentLetter = 0;
						words.clear();
					}
				}
			}
		}

		m_window.display();
	}

	return 0;
}

/*void setProperties(sf::Text text, sf::Color color, Point2D position)
{
	sf::Font font;
	font.loadFromFile("assets/fonts/couture-bldit.ttf");
	text->setFont(font);
	text->setColor(color);
	text->setPosition(position.getX(), position.getY());
}*/

void Game::setWordSpeed(int gameSpeed)
{
	m_wordSpeed = gameSpeed;
}

int Game::getWordSpeed()
{
	return m_wordSpeed;
}

void Game::setScore(int score)
{
	m_score = score;
}

void Game::setWordSpawnSpeed(float wordSpawnSpeed)
{
	m_wordSpawnSpeed = wordSpawnSpeed;
}

float Game::getWordSpawnSpeed()
{
	return m_wordSpawnSpeed;
}

int Game::getScore()
{
	return m_score;
}
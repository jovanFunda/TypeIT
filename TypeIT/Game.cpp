#define SFML_NO_DEPRECATED_WARNINGS

#include <string>
#include <deque>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Plane.h"
#include "Game.h"
#include "Word.h"

int Game::m_wordSpeed;
sf::RenderWindow Game::m_window(sf::VideoMode(800, 1000), "Keyboard racer", sf::Style::Titlebar | sf::Style::Close);
void setProperties(sf::Text&, sf::Color, Point2D);

int Game::Run()
{
	Plane plane("assets/images/plane.png", Point2D(400.f, 850.f));
	GameObject background("assets/images/background.jpg", Point2D(0, 0));
	m_window.setFramerateLimit(100);

	std::deque<Word*> words;

	m_wordSpeed = 500; // Decrease number to increase word speed
	float wordSpawnSpeed = 1.5f;
	
	sf::Clock clock;
	int score = 0;
	int gameOver = 0;
	int currentLetter = 0;
	
	float timer = wordSpawnSpeed; // Game immediately starts with one word

	sf::Text scoreText;
	setProperties(scoreText, sf::Color(50, 50, 255, 255), Point2D(20, 20));

	while (m_window.isOpen())
	{
		if (gameOver == 0)
		{
			timer += clock.restart().asSeconds();
			if (timer > wordSpawnSpeed)
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
						currentLetter++;
						if (words.front()->getString()[currentLetter] == '\0')
						{
							// WORD FINISHED
							currentLetter = 0;
							words.pop_front();
							score++;
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
				if (words.at(i)->step == -1)
				{
					gameOver = 1;
				}

				(words.at(i))->startMoving();
				m_window.draw(words.at(i)->getText());
			}

			scoreText.setString("Score " + std::to_string(score));
			m_window.draw(scoreText);
		} 
		else if (gameOver == 1) 
		{
			sf::Text finalText;
			finalText.setString("Your score is " + std::to_string(score));
			setProperties(finalText, sf::Color(200, 200, 255, 255), Point2D(230, 400));

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
						score = 0;
						currentLetter = 0;
						words.clear();
						timer = wordSpawnSpeed; // Game immediately starts with one word
					}
				}
			}
		}

		m_window.display();
	}

	return 0;
}

void setProperties(sf::Text& text, sf::Color color, Point2D position)
{
	static sf::Font font;
	font.loadFromFile("assets/fonts/couture-bldit.ttf");
	text.setColor(color);
	text.setPosition(position.x, position.y);
	text.setFont(font);
}

void Game::setWordSpeed(int gameSpeed)
{
	m_wordSpeed = gameSpeed;
}

int Game::getWordSpeed()
{
	return m_wordSpeed;
}
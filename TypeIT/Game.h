#pragma once

#include "Word.h"

class Game
{
public:
	static int currWordIndex;
	static std::vector<Word> currentWords;

	static void setScore(int score);
	static void setWordSpawnSpeed(float wordSpawnSpeed);
	static void setWordSpeed(int wordSpeed);
	static int getScore();
	static int getWordSpeed();
	static float getWordSpawnSpeed();
	static int Run();

private:
	static int m_score;
	static int m_wordSpeed;
	static float m_wordSpawnSpeed;
	static sf::Clock m_clock;
	static sf::RenderWindow	m_window;
};
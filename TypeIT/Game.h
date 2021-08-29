#pragma once

#include "Word.h"

class Game
{
public:
	static int Run();
	static int getWordSpeed();
	static void setWordSpeed(int gameSpeed);

private:
	static int m_wordSpeed;
	static sf::RenderWindow	m_window;
};
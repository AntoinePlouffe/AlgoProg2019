#pragma once

#include "Grid.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

private:

	void ShowInstructions();

	Grid m_Grid;
	Player m_player1;
	Player m_player2;
};


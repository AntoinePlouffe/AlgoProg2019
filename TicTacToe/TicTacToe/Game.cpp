#include<iostream>
#include "Game.h"
using namespace std;

Game::Game()
{
}


Game::~Game()
{
}

void Game::Run()
{
	do
	{
		ShowInstructions();

		m_Grid.Show();

		int row = -1;
		int column = -1;
		m_player1.AskInput(row, column);
		
		m_Grid.Affect(row, column);

	} while (m_Grid.Victory());
}

void Game::ShowInstructions()
{
	// Afficher les instructions
	cout << "Bienvenue dans le monde du tic-tac-toe." << endl <<
		"Voici les instructions:" << endl <<
		"..." << endl << endl;
}

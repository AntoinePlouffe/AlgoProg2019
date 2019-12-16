#include "Grid.h"
#include <iostream>
using namespace std;



Grid::Grid()
{
	m_Grid = { {' ', ' ', ' '},
			   {' ', ' ', ' '},
			   {' ', ' ', ' '} };
}


Grid::~Grid()
{
}

void Grid::Show()
{
	cout << "Grid" << endl;
	for (size_t x = 0; x < 3; x++) //
	{
		for (size_t y = 0; y < 3; y++) //
		{
			cout << " " << m_Grid[x][y] << "|";
		}
	}
}

bool Grid::Victory()
{
	return false;
}

bool Grid::CheckEmptyCase()
{
	return false;
}

void Grid::Affect(const int a_Row, const int a_Column)
{
}

#pragma once
#include <vector>

class Grid
{
public:
	Grid();
	~Grid();

	void Show();
	bool Victory();

	void Affect(const int a_Row, const int a_Column);

private:

	bool CheckEmptyCase();
	

	std::vector<std::vector<char >> m_Grid;
};


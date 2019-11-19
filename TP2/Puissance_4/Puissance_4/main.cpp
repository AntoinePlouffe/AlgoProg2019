#include <iostream>
#include <vector>
using namespace std;

int nbr1 = 5;

int main()
{
	cout << "  0 1 2 3 4 5 6" << endl;
	char grid[6][7];
	for (int r = 0; r < 6; r++)
	{
		cout << nbr1 <<"|";
		nbr1--;

		for (int c = 0; c < 7; c++)
		{
			grid[r][c] = 0;
			cout << grid[r][c] << "|";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


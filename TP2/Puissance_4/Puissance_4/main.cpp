#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Game
{
public:

	void Player1_Turn()
	{


	}

	void Player2_Turn()
	{

	}

	void Generate_Grid()
	{


		for (int y = 0; y < 6; y++)
		{
			for (int x = 0; x < 7; x++)
			{

				printf("|", grid[y][x] );

				cout << " ";
			}
			printf("|");
			cout << endl;

		}
	}

	Game()
	{
		Generate_Grid();
		Player1_Turn();

		system("cls");

		Generate_Grid();
		Player2_Turn();

		system("pause");
		system("cls");

		Game game;
	}

private:

	char X = 'X';
	char O = 'O';

	int P1_Choise = 0;


	char grid[6][7];
//              /*0 / 1 / 2 / 3 / 4 / 5 / 6*/
//* 0 */	{ {' ', ' ', ' ', ' ', ' ',' ',' '},
//* 1 */	  {' ', ' ', ' ', ' ', ' ',' ',' '},
//* 2 */	  {' ', ' ', ' ', ' ', ' ',' ',' '},
//* 3 */	  {' ', ' ', ' ', ' ', ' ',' ',' '},
//* 4 */	  {' ', ' ', ' ', ' ', ' ',' ',' '},
//* 5 */	  {' ', ' ', ' ', ' ', ' ',' ',' '} }; 
};



int main()
{
	//Main menu

	cout << "  _____                _____   _____   _____    _____                _____    _____              \n";
	cout << " /     \\   |       |     |    /       /        |     |   |\\     |   /        |        |     |  \n";
	cout << "|       |  |       |     |   |       |         |     |   | \\    |  |         |        |     |   \n";
	cout << "|\\_____/   |       |	 |    \\_____  \\_____   |_____|   |  \\   |  |         |_____   |     |  \n";
	cout << "|          |       |     |          \\       \\  |     |   |   \\  |  |         |        |_____| \n";
	cout << "|          |       |     |           |       | |     |   |    \\ |  |         |              |   \n";
	cout << "|           \\_____/    __|__   _____/  _____/  |     |   |     \\|   \\_____   |_____         | \n";
	system("pause");
	system("cls");

	Game game;

	return 0;

}
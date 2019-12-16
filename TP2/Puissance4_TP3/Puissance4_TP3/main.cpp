#include <iostream>
#include <cstdlib>

int tab[7][6];
int choice, player;
bool end = false;
int a = 0;

void check(int x)
{
	if (tab[x - 1][a] != 0 && a < 6)
	{
		a++;
		check(x);
	}
	else if (player == 1 && a < 6)
	{
		tab[x - 1][a] = 1;
		a = 0;
	}
	else if (player == 2 && a < 6)
	{
		tab[x - 1][a] = 2;
		a = 0;
	}
	else
	{
		std::cout << "WRONG!" << std::endl;
		a = 0;
		player++;
	}
}

int draw()
{
	system("cls");

	//Dessine le tableau
	for (int i = 0; i < 9; i++)
	{
		if (i < 2)
		{
			std::cout << "-";
		}
		else if (i > 7)
		{
			std::cout << i - 1 << "--" << std::endl;
		}
		else {
			std::cout << i - 1 << "----";
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (tab[j][i] != 0)
			{
				if (tab[j][i] == 1)
				{
					std::cout << "| X |";
				}
				else std::cout << "| O |";
			}
			else std::cout << "|   |";
		} std::cout << std::endl;
	}
	for (int i = 0; i < 35; i++)
	{
		std::cout << "=";
	} std::cout << std::endl;
	return 0;
}

int win_check()
{
	//Regarde si un des joueur à gagner

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (tab[j][i] == 1 && tab[j + 1][i + 1] == 1 && tab[j + 2][i + 2] == 1 && tab[j + 3][i + 3] == 1)
			{
				std::cout << "\nPLAYER 1 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			if (tab[j][i] == 1 && tab[j + 1][i - 1] == 1 && tab[j + 2][i - 2] == 1 && tab[j + 3][i - 3] == 1)
			{

				std::cout << "\nPLAYER 1 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			if (tab[j][i] == 2 && tab[j + 1][i - 1] == 2 && tab[j + 2][i -
				2] == 2 && tab[j + 3][i - 3] == 2)
			{
				std::cout << "\nPLAYER 2 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			else if (tab[j][i] == 2 && tab[j - 1][i - 1] == 2 && tab[j - 2][i - 2] == 2 && tab[j - 3][i - 3] == 2)
			{
				std::cout << "\nPLAYER 2 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			else if (tab[j][i] == 1 && tab[j][i - 1] == 1 && tab[j][i - 2] == 1 && tab[j][i - 3] == 1)
			{
				std::cout << "\nPLAYER 1 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			else if (tab[j][i] == 1 && tab[j - 1][i] == 1 && tab[j - 2][i] == 1 && tab[j - 3][i] == 1)
			{
				std::cout << "\nPLAYER 1 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			else if (tab[j][i] == 2 && tab[j][i - 1] == 2 && tab[j][i - 2] == 2 && tab[j][i - 3] == 2)
			{
				std::cout << "\nPLAYER 2 WIN!" << std::endl;
				system("pause");
				end = true;
			}
			else if (tab[j][i] == 2 && tab[j - 1][i] == 2 && tab[j - 2][i] == 2 && tab[j - 3][i] == 2)
			{
				std::cout << "\nPLAYER 2 WIN!" << std::endl;
				system("pause");
				end = true;
			}
		}
	}
	return 0;
}
int p_choice()
{
	player = 1;
	while (end != true)
	{
		std::cout << "PLAYER " << player << ": ";
		std::cin >> choice;
		if (choice > 0 && choice < 8)
		{
			check(choice);
			draw();
			if (player == 1)
			{
				player++;
			}
			else
			{
				player--;
			}
		}
		else
		{
			std::cout << "WRONG CHOICE!" << std::endl;
		}
		win_check();
	}
	return 0;
}


int main()
{
	//Main menu

	std::cout << "  _____                _____   _____   _____    _____                _____    _____              \n";
	std::cout << " /     \\   |       |     |    /       /        |     |   |\\     |   /        |        |     |  \n";
	std::cout << "|       |  |       |     |   |       |         |     |   | \\    |  |         |        |     |   \n";
	std::cout << "|\\_____/   |       |	 |    \\_____  \\_____   |_____|   |  \\   |  |         |_____   |     |  \n";
	std::cout << "|          |       |     |          \\       \\  |     |   |   \\  |  |         |        |_____| \n";
	std::cout << "|          |       |     |           |       | |     |   |    \\ |  |         |              |   \n";
	std::cout << "|           \\_____/    __|__   _____/  _____/  |     |   |     \\|   \\_____   |_____         | \n" << std::endl;


	std::cout << "Bienvenue dans le monde du Puissance 4." << std::endl <<
		"Voici les instructions:" << std::endl <<
		" 1- Pour gagner, vous devez aligner horizontalement, verticalement ou diagonalement 4 symboles identiques." << std::endl <<
		" 2- Vous pouvez placer un seul symbole par tour." << std::endl <<
		" 3- S'il y a egalite, la partie est nulle." << std::endl << std::endl;
	system("pause");
	draw();
	p_choice();
	return 0;
}

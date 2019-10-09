#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <stdlib.h>
using namespace std;

int playerHP = 20;
int ennemi1HP = 20;
int ennemi2HP = 20;
int ennemi3HP = 20;
int choixJoueur = 0;
int valeurRandom = 0;
bool gameEnd = false;



int main()
{
	srand(time(NULL));

	nbrEnnemi: 

	system("cls");

	int playerHP = 20;
	int ennemi1HP = 20;
	int ennemi2HP = 20;
	int ennemi3HP = 20;
	int choixJoueur = 0;
	int valeurRandom = 0;
	int fioleDeVie = 1;

	cout << "Veuillez taper le nombre d'ennemi a combattre (MAXIMUM: 3): ";
	cin >> choixJoueur;

	while (choixJoueur < 1 || choixJoueur > 3)
	{
		goto nbrEnnemi;
	}

	if (choixJoueur == 1) //player vs Ennemi1
	{
		system("cls");
		
		cout << "Voici vos HP: " << playerHP << " et ceux de l'ennemi(s): " << ennemi1HP << endl; //Montre les HP du joueur et de l'ennemi

		system("pause");
		system("cls");

		while (gameEnd == false)  //Tant que la parti n'est pas fini.
		{
			retourDebut1:

			cout << "Que voulez-vous faire?\n1-Attaquez, 2-Item, 3-Fuir" << endl; //tour du player
			cin >> choixJoueur;

			if (choixJoueur < 1 || choixJoueur > 3)
			{
				system("cls");
				goto retourDebut1;
			}

			if (choixJoueur == 1) //player attaque
			{
				system("cls");

				valeurRandom = rand() % 6;
				cout << "Le joueur attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				ennemi1HP -= valeurRandom;
				cout << "HP restant a l'ennemi: " << ennemi1HP << endl;
				
				system("pause");
				system("cls");

				if (ennemi1HP <= 0)
				{
					break;
				}
			}
			else if (choixJoueur == 2) //player item
			{
				retourItem1:

				system("cls");

				cout << "Choisir l'item! 1-Fiole de vie (1 time use), 2-Retour" << endl;
				cin >> choixJoueur;

				if (choixJoueur == 1)
				{
					if (fioleDeVie == 1)
					{
						playerHP += 10;
						if (playerHP > 20)
						{
							playerHP = 20;
						}

						system("cls");

						cout << "+10HP" << endl;

						system("pause");
						system("cls");

						cout << playerHP << "HP" << endl;
						fioleDeVie--;

						system("pause");
						system("cls");
					}
					else
					{
						system("cls");

						cout << "Vous n'avez plus de fiole de vie" << endl;

						system("pause");
						system("cls");
						goto retourItem1;
					}
				}
				else
				{
					system("cls");
					goto retourDebut1;
				}
			}

			else if (choixJoueur == 3) //player fuit
			{
				valeurRandom = rand() % 4 + 1;

				if (valeurRandom == 1)
				{
					system("cls");

					cout << "Vous avez pris la fuite." << endl;

					system("pause");
					system("cls");

					cout << "Voulez-vous rejouer? 1-oui, 2-non" << endl;
					cin >> choixJoueur;

					if (choixJoueur == 1)
					{
						goto nbrEnnemi;
					}
					else
					{
						gameEnd = true;
						goto gameOver;
					}
				}
				else
				{
					system("cls");

					cout << "Vous avez echoue a prendre la fuite." << endl;

					system("pause");
					system("cls");
				}
			}

			//tour de l'ennemie
			valeurRandom = rand() % 7;
			cout << "L'ennemi attaque de: " << valeurRandom << endl;

			system("pause");
			system("cls");

			playerHP -= valeurRandom;
			cout << "Vos HP restant: " << playerHP << endl;

			system("pause");
			system("cls");

			if (playerHP <= 0)
			{
				break;
			}
		}
	}
	else if (choixJoueur == 2) //player vs 2 ennemi
	{

		system("cls");

		fioleDeVie++; //rajoute une fiole de vie au joueur.
		
		cout << "Voici vos HP: " << playerHP << " et ceux de l'ennemi(s): " << ennemi1HP << endl; //Montre les HP du joueur et de l'ennemi

		system("pause");
		system("cls");

		while (gameEnd == false)
		{
			retourDebut2:

			cout << "Que voulez-vous faire?\n1-Attaquez, 2-Item, 3-Fuir" << endl; //tour du player
			cin >> choixJoueur;

			if (choixJoueur < 1 || choixJoueur > 3)
			{
				system("cls");
				goto retourDebut2;
			}

			if (choixJoueur == 1) //player attaque
			{
			retourAttaque:

				system("cls");

				cout << "Quel cible attaquer? 1-ennemi1, 2-ennemi2" << endl; //choix de la cible
				cin >> choixJoueur;

				if (choixJoueur == 1) //attaque l'ennemi1
				{

					system("cls");

					if (ennemi1HP <= 0) //Si ennemi1 est mort.
					{
						cout << "l'ennemi est mort. Veuillez choisir une autre cible." << endl;

						system("pause");
						goto retourAttaque; //retour au choix de la cible
					}

					valeurRandom = rand() % 10;
					cout << "Le joueur attaque de: " << valeurRandom << endl;

					system("pause");
					system("cls");

					ennemi1HP -= valeurRandom;
					cout << "HP restant a l'ennemi: " << ennemi1HP << endl;

					system("pause");
					system("cls");
				}
				else if (choixJoueur == 2) //attaque l'ennemi2
				{

					system("cls");

					if (ennemi2HP <= 0) //Si ennemi2 est mort.
					{
						cout << "l'ennemi est mort. Veuillez choisir une autre cible." << endl;

						system("pause");
						goto retourAttaque; //retour au choix de la cible
					}

					valeurRandom = rand() % 10;
					cout << "Le joueur attaque de: " << valeurRandom << endl;

					system("pause");
					system("cls");

					ennemi2HP -= valeurRandom;
					cout << "HP restant a l'ennemi: " << ennemi2HP << endl;

					system("pause");
					system("cls");
				}



				if (ennemi1HP <= 0 && ennemi2HP <= 0)
				{
					break;
				}
			}
		}
	}
	else //player vs 3 ennemi
	{

	}


	if (playerHP <= 0)
	{
		cout << "Victoire de l'ennemi(s)!" << endl;

		cout << "Voulez-vous rejouer? 1-oui, 2-non" << endl;
		cin >> choixJoueur;

		if (choixJoueur == 1)
		{
			goto nbrEnnemi;
		}
		else
		{

		}
	}
	else
	{
		cout << "Victoire du joueur!" << endl;

		cout << "Voulez-vous rejouer? 1-oui, 2-non" << endl;
		cin >> choixJoueur;

		if (choixJoueur == 1)
		{
			goto nbrEnnemi;
		}
		else
		{

		}
	}

	gameOver:

	if (gameEnd == true)
	{
		system("cls");

		cout << "GAME OVER!" << endl;
		system("pause");
	}
}
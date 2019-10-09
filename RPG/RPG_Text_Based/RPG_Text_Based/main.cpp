#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <stdlib.h>
using namespace std;

//VARIABLE
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

	//Reinitialisation des variables
	int playerHP = 20;
	int ennemi1HP = 20;
	int ennemi2HP = 20;
	int ennemi3HP = 20;
	int choixJoueur = 0;
	int valeurRandom = 0;
	int fioleDeVie = 1;

	cout << "Veuillez taper le nombre d'ennemi a combattre (MAXIMUM: 3): ";
	cin >> choixJoueur;

	//Tant que l'utilisateur ne tape pas entre 1 et 3
	while (choixJoueur < 1 || choixJoueur > 3)
	{
		goto nbrEnnemi;
	}

	//Player vs 1 ennemi
	if (choixJoueur == 1)
	{
		system("cls");
		
		cout << "Voici vos HP: " << playerHP << " et ceux de l'ennemi(s): " << ennemi1HP << endl; //Montre les HP du joueur et de l'ennemi

		system("pause");
		system("cls");

		//Tant que la parti n'est pas fini
		while (gameEnd == false)
		{
			retourDebut1:

			cout << "Que voulez-vous faire?\n1-Attaquez, 2-Item, 3-Fuir" << endl; //Choix du player
			cin >> choixJoueur;

			//Si le joueur ne tape pas entre 1 et 3
			if (choixJoueur < 1 || choixJoueur > 3)
			{
				system("cls");
				goto retourDebut1;
			}

			//Player attaque
			if (choixJoueur == 1)
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

				//Si l'ennemi est mort
				if (ennemi1HP <= 0)
				{
					break;
				}
			}

			//Player item
			else if (choixJoueur == 2)
			{
				retourItem1:

				system("cls");

				cout << "Choisir l'item! 1-Fiole de vie (1 time use), 2-Retour" << endl;
				cin >> choixJoueur;

				//Utilise fiole de vie
				if (choixJoueur == 1)
				{
					if (fioleDeVie > 0)
					{
						playerHP += 10;

						//Ne depasse pas le max de 20HP
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

					//Si il n'a plus de fiole de vie
					else
					{
						system("cls");

						cout << "Vous n'avez plus de fiole de vie" << endl;

						system("pause");
						system("cls");
						goto retourItem1;
					}
				}

				//Retour en arriere
				else if (choixJoueur == 2)
				{
					system("cls");
					goto retourDebut1;
				}
				
				//Si l'utilisateur ne tape pas 1 ou 2
				else
				{
					system("cls");
					goto retourItem1;
				}
			}
			//Player fuit
			else if (choixJoueur == 3)
			{
				valeurRandom = rand() % 4 + 1;

				//Player reussi a fuir
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

				//Player echoue a fuir
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

			//Si le joueur est battu
			if (playerHP <= 0)
			{
				break;
			}
		}
	}

	//Player vs 2 ennemi
	else if (choixJoueur == 2)
	{
		system("cls");

		fioleDeVie++; //rajoute une fiole de vie au joueur.
		
		cout << "Voici vos HP: " << playerHP << " et ceux de l'ennemi(s): " << ennemi1HP << endl; //Montre les HP du joueur et de l'ennemi

		system("pause");
		system("cls");

		while (gameEnd == false)
		{
			retourDebut2:

			cout << "Que voulez-vous faire?\n1-Attaquez, 2-Item, 3-Fuir" << endl; //Choix du player
			cin >> choixJoueur;

			//Si le joueur ne tape pas entre 1 et 3
			if (choixJoueur < 1 || choixJoueur > 3)
			{
				system("cls");
				goto retourDebut2;
			}

			//player attaque
			if (choixJoueur == 1)
			{
			retourAttaque:

				system("cls");

				cout << "Quel cible attaquer? 1-ennemi1, 2-ennemi2" << endl; //choix de la cible
				cin >> choixJoueur;

				//attaque l'ennemi1
				if (choixJoueur == 1)
				{

					system("cls");

					//Si ennemi1 est mort.
					if (ennemi1HP <= 0)
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

				//attaque l'ennemi2
				else if (choixJoueur == 2)
				{

					system("cls");

					//Si ennemi2 est mort.
					if (ennemi2HP <= 0)
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

				//Si ennemi1 et ennemi2 sont battu
				if (ennemi1HP <= 0 && ennemi2HP <= 0)
				{
					break;
				}	
			}

			//Player item
			else if (choixJoueur == 2)
			{
			retourItem2:

				system("cls");

				cout << "Choisir l'item! 1-Fiole de vie (2 uses), 2-Retour" << endl;
				cin >> choixJoueur;

				//Utilise fiole de vie
				if (choixJoueur == 1)
				{

					//Si il reste des fioles de vie
					if (fioleDeVie > 0)
					{
						playerHP += 10;

						//Ne depasse pas le max de 20HP
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

					//Si il n'a plus de fiole de vie
					else
					{
						system("cls");

						cout << "Vous n'avez plus de fiole de vie" << endl;

						system("pause");
						system("cls");
						goto retourItem2;
					}
				}

				//Retour en arriere
				else if (choixJoueur == 2)
				{
					system("cls");
					goto retourDebut1;
				}

				//Si l'utilisateur ne tape pas 1 ou 2
				else
				{
					system("cls");
					goto retourItem1;
				}
			}

			//Player fuit
			else if (choixJoueur == 3)
			{
			valeurRandom = rand() % 4 + 1;

				//Player reussi a fuir
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

				//Player echoue a fuir
				else
				{
					system("cls");

					cout << "Vous avez echoue a prendre la fuite." << endl;

					system("pause");
					system("cls");
				}
			}


			//tour de l'ennemie1
			if (ennemi1HP > 0)
			{
				valeurRandom = rand() % 5;
				cout << "L'ennemi1 attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				playerHP -= valeurRandom;
				cout << "Vos HP restant: " << playerHP << endl;

				system("pause");
				system("cls");

				//Si le joueur est battu
				if (playerHP <= 0)
				{
					break;
				}
			}
		
			//tour de l'ennemie2
			if (ennemi2HP > 0)
			{
				valeurRandom = rand() % 5;
				cout << "L'ennemi2 attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				playerHP -= valeurRandom;
				cout << "Vos HP restant: " << playerHP << endl;

				system("pause");
				system("cls");

				//Si le joueur est battu
				if (playerHP <= 0)
				{
					break;
				}
			}

			
		}
	}
	else
	{
		system("cls");
		fioleDeVie += 2; //rajoute deux fiole de vie au joueur.
		
		cout << "Voici vos HP: " << playerHP << " et ceux de l'ennemi(s): " << ennemi1HP << endl; //Montre les HP du joueur et de l'ennemi

		system("pause");
		system("cls");

		while (gameEnd == false)
		{
			retourDebut3:

			cout << "Que voulez-vous faire?\n1-Attaquez, 2-Item, 3-Fuir" << endl; //tour du player
			cin >> choixJoueur;

			//Si le joueur ne tape pas entre 1 et 3
			if (choixJoueur < 1 || choixJoueur > 3)
			{
				system("cls");
				goto retourDebut3;
			}
			//player attaque
			if (choixJoueur == 1)
			{
			retourAttaque1:

				system("cls");

				cout << "Quel cible attaquer? 1-ennemi1, 2-ennemi2, 3-ennemi3" << endl; //choix de la cible
				cin >> choixJoueur;

				//Attaque l'ennemi1
				if (choixJoueur == 1)
				{

					system("cls");

					//Si ennemi1 est mort.
					if (ennemi1HP <= 0)
					{
						cout << "l'ennemi est mort. Veuillez choisir une autre cible." << endl;

						system("pause");
						goto retourAttaque1; //retour au choix de la cible
					}

					valeurRandom = rand() % 10;
					cout << "Le joueur attaque de: " << valeurRandom << endl;

					system("pause");
					system("cls");

					ennemi1HP -= valeurRandom;
					cout << "HP restant a l'ennemi1: " << ennemi1HP << endl;

					system("pause");
					system("cls");
				}

				//Attaque l'ennemi2
				else if (choixJoueur == 2)
				{

					system("cls");

					//Si ennemi2 est mort.
					if (ennemi2HP <= 0)
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
					cout << "HP restant a l'ennemi2: " << ennemi2HP << endl;

					system("pause");
					system("cls");
				}

				//Attaque l'ennemi3
				if (choixJoueur == 3)
				{

					system("cls");

					//Si ennemi1 est mort.
					if (ennemi3HP <= 0)
					{
						cout << "l'ennemi est mort. Veuillez choisir une autre cible." << endl;

						system("pause");
						goto retourAttaque1; //retour au choix de la cible
					}

					valeurRandom = rand() % 10;
					cout << "Le joueur attaque de: " << valeurRandom << endl;

					system("pause");
					system("cls");

					ennemi3HP -= valeurRandom;
					cout << "HP restant a l'ennemi3: " << ennemi3HP << endl;

					system("pause");
					system("cls");
				}

				//Si tout les ennemis sont battu
				if (ennemi1HP <= 0 && ennemi2HP <= 0 && ennemi3HP <= 0)
				{
					break;
				}
			}

			//Player item
			else if (choixJoueur == 2)
			{
			retourItem3:

				system("cls");

				cout << "Choisir l'item! 1-Fiole de vie (3 uses), 2-Retour" << endl;
				cin >> choixJoueur;

				//Utilise fiole de vie
				if (choixJoueur == 1)
				{

					//Si il reste des fioles de vie
					if (fioleDeVie > 0)
					{
						playerHP += 10;

						//Ne depasse pas le max de 20HP
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

					//Si il n'a plus de fiole de vie
					else
					{
						system("cls");

						cout << "Vous n'avez plus de fiole de vie" << endl;

						system("pause");
						system("cls");
						goto retourItem3;
					}
				}

				//Retour en arriere
				else if (choixJoueur == 2)
				{
					system("cls");
					goto retourDebut1;
				}

				//Si l'utilisateur ne tape pas 1 ou 2
				else
				{
					system("cls");
					goto retourItem1;
				}
			}
			//Player fuit
			else if (choixJoueur == 3)
			{
				valeurRandom = rand() % 4 + 1;

				//Player reussi a fuir
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

				//Player echoue a fuir
				else
				{
					system("cls");

					cout << "Vous avez echoue a prendre la fuite." << endl;

					system("pause");
					system("cls");
				}
			}


			//tour de l'ennemie1
			if (ennemi1HP > 0)
			{
				valeurRandom = rand() % 4;
				cout << "L'ennemi1 attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				playerHP -= valeurRandom;
				cout << "Vos HP restant: " << playerHP << endl;

				system("pause");
				system("cls");

				//Si le joueur est battu
				if (playerHP <= 0)
				{
					break;
				}
			}

			//tour de l'ennemie2
			if (ennemi2HP > 0)
			{
				valeurRandom = rand() % 4;
				cout << "L'ennemi2 attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				playerHP -= valeurRandom;
				cout << "Vos HP restant: " << playerHP << endl;

				system("pause");
				system("cls");

				//Si le joueur est battu
				if (playerHP <= 0)
				{
					break;
				}
			}

			//tour de l'ennemie3
			if (ennemi3HP > 0)
			{
				valeurRandom = rand() % 4;
				cout << "L'ennemi3 attaque de: " << valeurRandom << endl;

				system("pause");
				system("cls");

				playerHP -= valeurRandom;
				cout << "Vos HP restant: " << playerHP << endl;

				system("pause");
				system("cls");

				//Si le joueur est battu
				if (playerHP <= 0)
				{
					break;
				}
			}


		}
	}

	//Victoire de l'ennemi
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

	//Victoire du joueur
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

	//GAME OVER
	if (gameEnd == true)
	{
		system("cls");

		cout << "GAME OVER!" << endl;
		system("pause");
	}
}
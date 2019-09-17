// Roche_Papier_Ciseaux.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;

int main()
{
	int Roche = 1;
	int Papier = 2;
	int Ciseau = 3;
	int ChoixJoueur, ChoixOrdi, PointJoueur, PointOrdi;

	ChoixJoueur = 0;
	ChoixOrdi = 0;
	PointJoueur = 0;
	PointOrdi = 0;

	cout << "Bienvenue au jeu de Roche-Papier-Ciseaux. Les regles sont simples, le premier qui a 3 points l'emporte. les choix	sont: Roche = 1, Papier = 2, Ciseaux = 3 \n";

	while (PointJoueur != 3 && PointOrdi != 3)
	{
		cout << "\nVeuillez choisir un chiffre entre 1 a 3: ";
		cin >> ChoixJoueur;

		ChoixOrdi = rand() % 3 + 1;

		if (ChoixJoueur < 1 || ChoixJoueur > 3)
		{
			cout << "\nVeuillez choisir un chiffre entre 1 a 3: ";
			cin >> ChoixJoueur;
		}


		if (ChoixJoueur == 1 && ChoixOrdi == 1)
		{
			cout << "Egalite";
		}

		else if (ChoixJoueur == 1 && ChoixOrdi == 2)
		{
			cout << "L'ordinateur marque un point!";
			PointOrdi++;
		}

		else if (ChoixJoueur == 1 && ChoixOrdi == 3)
		{
			cout << "Le Joueur marque un point!";
			PointJoueur++;
		}

		else if (ChoixJoueur == 2 && ChoixOrdi == 1)
		{
			cout << "Le Joueur marque un point!";
			PointJoueur++;
		}

		else if (ChoixJoueur == 2 && ChoixOrdi == 2)
		{
			cout << "Egalite";
		}

		else if (ChoixJoueur == 2 && ChoixOrdi == 3)
		{
			cout << "L'ordinateur marque un point!";
			PointOrdi++;
		}

		else if (ChoixJoueur == 3 && ChoixOrdi == 1)
		{
			cout << "L'ordinateur marque un point!";
			PointOrdi++;
		}

		else if (ChoixJoueur == 3 && ChoixOrdi == 2)
		{
			cout << "Le Joueur marque un point!";
			PointJoueur++;
		}

		else if (ChoixJoueur == 3 && ChoixOrdi == 3)
		{
			cout << "Egalite";
		}
	}

	system("ClS");


	if (PointJoueur == 3)
	{
		cout << "Le joueur remporte la parti!!\n";
	}

	else if (PointOrdi)
	{
		cout << "l'ordinateur remporte la parti!!\n";
	}

}
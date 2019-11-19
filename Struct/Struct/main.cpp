#include <iostream>

using namespace std;


struct Temps
{
	int heure; //0-23
	int minute; //0-59
	int seconde; //0-59
};

void afficherStandard(const Temps& a_refTemps);

int main() 
{
	Temps temps;

	temps.heure = 18;
	temps.minute = 30;
	temps.seconde = 0;

	afficherStandard(temps);
	cout << ", temps standard.\n";

	system("pause");

	return 0;

}

void afficherStandard(const Temps& a_refTemps)
{
	cout << ((a_refTemps.heure == 0 || a_refTemps.heure == 12) ? 12 : a_refTemps.heure % 12)
		<< ":" << (a_refTemps.minute < 10 ? "0" : "") << a_refTemps.minute
		<< ":" << (a_refTemps.seconde < 10 ? "0" : "") << a_refTemps.seconde
		<< (a_refTemps.heure < 12 ? "AM" : "PM");
}
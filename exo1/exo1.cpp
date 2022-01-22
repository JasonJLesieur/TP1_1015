#include <iostream>
#include <cmath>
using namespace std;

bool isPair(const int nombre)
{
	int division_entiere = nombre / 2;
	if (division_entiere * 2 == nombre)
		return true;
	else return false;
}

bool isDivisible(int nombre)
{
	int diviseur = 3;
	while (diviseur < sqrt(nombre))
	{
		int division_entiere = nombre / diviseur;
		if (division_entiere * diviseur == nombre)
			return true;
		else diviseur += 2;
	}

}

int retourneDiviseur(int nombre)
{
	for (int diviseur = 3; diviseur < sqrt(nombre); diviseur += 2) {
		int division_entiere = nombre / diviseur;
		if (division_entiere * diviseur == nombre)
			return diviseur;
	}
}

int main()
{
	int nombre;
	cout << "Entrer un nombre entier:";
	cin >> nombre;

	if (isPair(nombre)) {
		cout << "Le nombre est divisible par 2";

	}
	else if (isDivisible(nombre) == true) {
		cout << isDivisible(nombre);
		cout << "Le nombre est divisible par " << retourneDiviseur(nombre);
	}

	else {
		cout << "Le nombre est premier";
	}
}
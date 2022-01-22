#include <iostream>
#include <cmath>
#include <math.h> 
using namespace std;

//�crivez un programme qui demande et lit du clavier une somme d�argent qui a �t� pr�t�e, le
//montant rembours� chaque mois, ainsi que le taux d�int�r�t annuel(le taux mensuel est le 1 / 12 du taux
//annuel), et retourne le nombre de mois n�cessaires pour rembourser la dette ainsi que la somme des int�r�ts
//per�us par le pr�teur.Vous devrez v�rifier la validit� des donn�es entr�es par l�utilisateur(montant positifs
//et taux compris entre 0 et 100), et redemander ceux - ci lorsqu�ils ne sont pas valides.Vous devez utiliser
//une structure de r�p�tition, et non la solution analytique de l��quation de r�currence.�crivez une fonction
//2 / 4
//pour l�entr�e valid�e d�une valeur r�elle dans un intervalle; utilisez la constante INFINITY de cmath s�il
//n�y a pas de borne sup�rieure.

bool validerChiffrePositifs(double nombres)
{
	if (nombres > 0)
		return true;
	else return false;
}

bool validerTaux(double taux)
{
	if (taux < 100)
		return true;
	else return false;
}

bool validerDonn�(double taux, double montantEmprunt�, double montantRembour�)
{

	if (validerChiffrePositifs(montantEmprunt�) == false) {
		cout << "Le montant emprunt� entr� n'est pas positif, r�essayez \n";
	}
	else if (validerChiffrePositifs(montantRembour�) == false) {
		cout << "Le montant rembours� entr� n'est pas positif, r�essayez \n";
	}
	else if (validerChiffrePositifs(taux) == false) {
		cout << "Le taux d'int�r�t entr� n'est pas positif, r�essayez \n";
	}
	else if (validerTaux(taux) == false) {
		cout << "le taux d'int�r�t est plus grand que 100%, r�essayez \n";
	}
	else return true;
}

double calculNombreMois(double taux, double montantEmprunt�, double montantRembour�)
{
	// mensualite = initial (interest rate (1 + interest rate)^n)/((1+interest rate)^n -1)
	//formule sur internet
	//reduction donne n = (ln(mensualite/initial +1)/(ln (1+interest rate)

	double nombreMois = log(montantRembour� / montantEmprunt� + 1) / log(1 + taux);
	return nombreMois;

}

double calculMontantInterets(double montantEmprunt�, double montantRembour�Mensuel, double nbmois)
{
	double interets = montantEmprunt� - montantRembour�Mensuel * nbmois;
	return interets;
}

double demandeDonne()
{
	double montantEmprunt�;
	double montantRembours�Mensuel;
	double tauxInt�r�t;
	cout << "Quel est la somme d'argent emprunt�, le montant rembour� ainsi que le taux d'int�r�t annuel";
	cin >> montantEmprunt� >> montantRembours�Mensuel >> tauxInt�r�t;
	if (validerDonn�(tauxInt�r�t, montantEmprunt�, montantRembours�Mensuel) == true)
		return montantEmprunt�, montantRembours�Mensuel, tauxInt�r�t;
	else demandeDonne();
}

int main()
{
	double montantEmprunt�;
	double montantRembours�Mensuel;
	double tauxInt�r�t;
	cout << "Quel est la somme d'argent emprunt�, le montant rembour� ainsi que le taux d'int�r�t annuel";
	cin >> montantEmprunt� >> montantRembours�Mensuel >> tauxInt�r�t;
	if (validerDonn�(tauxInt�r�t, montantEmprunt�, montantRembours�Mensuel) == true) {
		double nbmois = calculNombreMois(tauxInt�r�t, montantEmprunt�, montantRembours�Mensuel);
		double interetsTotal = calculMontantInterets(montantEmprunt�, montantRembours�Mensuel, nbmois);
		cout << "Le nombre de mois n�cessaires est de: " << nbmois << " et le montant total d'int�r�t pay�s est de : " << interetsTotal;
	}
	else main();

	return 0;
}
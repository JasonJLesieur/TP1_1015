#include <iostream>
#include <cmath>
#include <math.h> 
using namespace std;

//Écrivez un programme qui demande et lit du clavier une somme d’argent qui a été prêtée, le
//montant remboursé chaque mois, ainsi que le taux d’intérêt annuel(le taux mensuel est le 1 / 12 du taux
//annuel), et retourne le nombre de mois nécessaires pour rembourser la dette ainsi que la somme des intérêts
//perçus par le prêteur.Vous devrez vérifier la validité des données entrées par l’utilisateur(montant positifs
//et taux compris entre 0 et 100), et redemander ceux - ci lorsqu’ils ne sont pas valides.Vous devez utiliser
//une structure de répétition, et non la solution analytique de l’équation de récurrence.Écrivez une fonction
//2 / 4
//pour l’entrée validée d’une valeur réelle dans un intervalle; utilisez la constante INFINITY de cmath s’il
//n’y a pas de borne supérieure.

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

bool validerDonné(double taux, double montantEmprunté, double montantRembouré)
{

	if (validerChiffrePositifs(montantEmprunté) == false) {
		cout << "Le montant emprunté entré n'est pas positif, réessayez \n";
	}
	else if (validerChiffrePositifs(montantRembouré) == false) {
		cout << "Le montant remboursé entré n'est pas positif, réessayez \n";
	}
	else if (validerChiffrePositifs(taux) == false) {
		cout << "Le taux d'intérêt entré n'est pas positif, réessayez \n";
	}
	else if (validerTaux(taux) == false) {
		cout << "le taux d'intérêt est plus grand que 100%, réessayez \n";
	}
	else return true;
}

double calculNombreMois(double taux, double montantEmprunté, double montantRembouré)
{
	// mensualite = initial (interest rate (1 + interest rate)^n)/((1+interest rate)^n -1)
	//formule sur internet
	//reduction donne n = (ln(mensualite/initial +1)/(ln (1+interest rate)

	double nombreMois = log(montantRembouré / montantEmprunté + 1) / log(1 + taux);
	return nombreMois;

}

double calculMontantInterets(double montantEmprunté, double montantRembouréMensuel, double nbmois)
{
	double interets = montantEmprunté - montantRembouréMensuel * nbmois;
	return interets;
}

double demandeDonne()
{
	double montantEmprunté;
	double montantRembourséMensuel;
	double tauxIntérêt;
	cout << "Quel est la somme d'argent emprunté, le montant rembouré ainsi que le taux d'intérêt annuel";
	cin >> montantEmprunté >> montantRembourséMensuel >> tauxIntérêt;
	if (validerDonné(tauxIntérêt, montantEmprunté, montantRembourséMensuel) == true)
		return montantEmprunté, montantRembourséMensuel, tauxIntérêt;
	else demandeDonne();
}

int main()
{
	double montantEmprunté;
	double montantRembourséMensuel;
	double tauxIntérêt;
	cout << "Quel est la somme d'argent emprunté, le montant rembouré ainsi que le taux d'intérêt annuel";
	cin >> montantEmprunté >> montantRembourséMensuel >> tauxIntérêt;
	if (validerDonné(tauxIntérêt, montantEmprunté, montantRembourséMensuel) == true) {
		double nbmois = calculNombreMois(tauxIntérêt, montantEmprunté, montantRembourséMensuel);
		double interetsTotal = calculMontantInterets(montantEmprunté, montantRembourséMensuel, nbmois);
		cout << "Le nombre de mois nécessaires est de: " << nbmois << " et le montant total d'intérêt payés est de : " << interetsTotal;
	}
	else main();

	return 0;
}
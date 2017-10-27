/*
// Projet : Calculatrice sur nombres rationnels
// Auteur : Nelson Deren, Hugo Fernandez, Leo Chazeau, Benjamin Destruhaut
// Date : 27/10/17
*/


#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct Fraction {
  int numerateur;
  int denominateur;
}Fraction;
Fraction ecrire();
void afficherFraction(Fraction *fraction); // affiche la valeur d'une fraction.
void comparer(Fraction *fraction1, Fraction *fraction2); // Prend la valeur de la fonction comparerbis pour ensuite afficher la comparaison des deux fractions avec >, < et =
int comparerbis(Fraction *fraction1, Fraction *fraction2);// Determine quelle fraction est la plus grande par rapport a l'autre
void choisirOperation(Fraction *fraction1, Fraction *fraction2); // Affiche le menu du choix d'opération, récupere la saisie et choisit l'opération en fonction de celle-ci.
void metreSurMemeDenominateur(Fraction *fraction1, Fraction *fraction2); // Permet de mettre sous le meme denominateur deux fractions
void afficherResultat(Fraction *fraction); // Affiche le resultat d'une operation.
Fraction additionner(Fraction *fraction1, Fraction *fraction2); //additionne deux fractions
Fraction diviser(Fraction *fraction1, Fraction *fraction2);//divise deux fractions
Fraction soustraire(Fraction *fraction1, Fraction *fraction2);//soustrait deux fractions
Fraction multiplier(Fraction *fraction1, Fraction *fraction2);//multiplie deux fractions
Fraction simplifier(Fraction *fraction1);  //Simplifie une fraction en divisant sont numerateur et son denominateur par leur pgcd.
int gcd(int nombre1, int nombre2); //Exprime la fonction pgcd par l'algorithme d'euclide

#endif // FONCTIONS_H_INCLUDED

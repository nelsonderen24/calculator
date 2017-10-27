/*
// Projet DMSKJBMDKJBV
// Auteur :
// Date :


*/


#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct Fraction {
  int numerateur;
  int denominateur;
}Fraction;

Fraction ecrire();
void afficherFraction(Fraction *fraction);
void comparer(Fraction *fraction1, Fraction *fraction2);
int comparerbis(Fraction *fraction1, Fraction *fraction2);
void choisirOperation(Fraction *fraction1, Fraction *fraction2);
void metreSurMemeDenominateur(Fraction *fraction1, Fraction *fraction2);
void afficherResultat(Fraction fraction);
Fraction additionner(Fraction *fraction1, Fraction *fraction2);
Fraction diviser(Fraction *fraction1, Fraction *fraction2);
Fraction soustraire(Fraction *fraction1, Fraction *fraction2);
Fraction multiplier(Fraction *fraction1, Fraction *fraction2);
Fraction simplifier(Fraction *fraction1);  //utiliser pgcd des deux nombres et diviser chaque nombre par le pgcd (nelson)
int gcd(int nombre1, int nombre2);

#endif // FONCTIONS_H_INCLUDED

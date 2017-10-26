#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct Fraction {
  int numerateur;
  int denominateur;
}Fraction;

Fraction ecrire(); //hugo

Fraction choisirOperation(Fraction *fraction1, Fraction *fraction2); //leo

void afficherResultat(Fraction fraction); //benjamin


Fraction additionner(Fraction *fraction1, Fraction *fraction2); //hugo
Fraction diviser(Fraction *fraction1, Fraction *fraction2); //hugo
Fraction soustraire(Fraction *fraction1, Fraction *fraction2); //leo
Fraction multiplier(Fraction *fraction1, Fraction *fraction2);  //leo
Fraction comparer(Fraction *fraction1, Fraction *fraction2); //benjamin

Fraction simplifier(Fraction *fraction1);  //utiliser pgcd des deux nombres et diviser chaque nombre par le pgcd (nelson)

int gcd(Fraction *fraction1, Fraction *fraction2); // nelson

#endif // FONCTIONS_H_INCLUDED

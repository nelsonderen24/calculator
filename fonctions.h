#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct Fraction {
  int numerateur;
  int denominateur;
}Fraction;

Fraction ecrire();

Fraction choisirOperation(Fraction *fraction1, Fraction *fraction2);

void afficherResultat(Fraction fraction);


Fraction additionner(Fraction *fraction1, Fraction *fraction2);
Fraction diviser(Fraction *fraction1, Fraction *fraction2);
Fraction soustraire(Fraction *fraction1, Fraction *fraction2);
Fraction multiplier(Fraction *fraction1, Fraction *fraction2);
Fraction comparer(Fraction *fraction1, Fraction *fraction2);
Fraction simplifier(Fraction *fraction1);



#endif // FONCTIONS_H_INCLUDED

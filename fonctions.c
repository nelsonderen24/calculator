#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

Fraction *creerFraction() {
  //Allocation d'un espace pour créer la fraction
  Fraction *nouvelleFraction = malloc(sizeof(*nouvelleFraction));
  if (nouvelleFraction == 0)
  {
    exit(EXIT_FAILURE);
  }

  //Initialisation de la fraction
  nouvelleFraction->denominateur = 1;
  nouvelleFraction->numerateur = 1;

  return nouvelleFraction;
}

void changerValeur(Fraction *fraction, int numerateur, int denominateur) {
  fraction->numerateur = numerateur;
  fraction->denominateur = denominateur;
}

void afficherFraction(Fraction *fraction) {
  printf("%d/%d", fraction->numerateur, fraction->denominateur);
}

Fraction additionner(Fraction *fraction1, Fraction *fraction2){
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur * fraction2->denominateur) + (fraction2->numerateur * fraction1->denominateur));
  fraction.denominateur = (fraction1->denominateur * fraction2->denominateur); //oubli ;
  return fraction;
}

int comparer(Fraction *fraction1, Fraction *fraction2) {
  Fraction cloneFraction1 = *fraction1;
  Fraction cloneFraction2 = *fraction2;

  metreSurMemeDenominateur(&cloneFraction1, &cloneFraction2);

  if (cloneFraction1.numerateur > cloneFraction2.numerateur) {
    return 1; //Retourne 1 si fraction1 supérieur
  }
  else if (cloneFraction1.numerateur < cloneFraction2.numerateur) {
    return 2; //Retourne 2 si fraction2 supérieur
  }
  else {
    return 0; //Retourne 0 si égales
  }
}

void metreSurMemeDenominateur(Fraction *fraction1, Fraction *fraction2) {
  fraction1->numerateur *= fraction2->denominateur;
  fraction2->numerateur *= fraction1->denominateur;
  int denominateurCommun = fraction1->denominateur * fraction2->denominateur;
  fraction1->denominateur = denominateurCommun;
  fraction2->denominateur = denominateurCommun;
}



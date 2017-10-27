#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

void choisirOperation(Fraction *fraction1, Fraction *fraction2){
  printf("Choisir une opération : \n 1 - Additionner \n 2 - Soustraire \n 3 - Diviser \n 4 - Multiplier \n 5 - Comparer \n 6 - Simplifier \n");
  int operation;
  scanf("%d", &operation);
  Fraction fraction;
  switch (operation) {
    case 1:
      fraction = additionner(fraction1, fraction2);
      afficherResultat(&fraction);
      break;
    case 2:
      fraction = soustraire(fraction1, fraction2);
      afficherResultat(&fraction);
      break;
    case 3:
      fraction = diviser(fraction1, fraction2);
      afficherResultat(&fraction);
      break;
    case 4:
      fraction = multiplier(fraction1, fraction2);
      afficherResultat(&fraction);
      break;
    case 5:
      comparer(fraction1, fraction2);
      break;
    case 6:
      fraction = simplifier(fraction1);
      afficherResultat(&fraction);
      fraction = simplifier(fraction2);
      afficherResultat(&fraction);
      break;
    default:
      printf("Erreur de frappe, relancez la calculette.\n");
      break;
  }
}
int gcd(int nombre1, int nombre2){
  return nombre1 ? gcd(nombre2%nombre1, nombre1) : nombre2;
}
Fraction simplifier(Fraction *fraction1) {
  int pgcd = gcd(fraction1->numerateur, fraction1->denominateur);
  Fraction fraction;
  fraction.numerateur = (fraction1->numerateur)/pgcd;
  fraction.denominateur = (fraction1->denominateur)/pgcd;
  return fraction;
}
Fraction additionner(Fraction *fraction1, Fraction *fraction2) {
  Fraction fraction;
  fraction.numerateur = (((fraction1->numerateur) * (fraction2->denominateur)) + ((fraction2->numerateur) * (fraction1->denominateur)));
  fraction.denominateur = (fraction1->denominateur * fraction2->denominateur);
  return fraction;
}
Fraction soustraire(Fraction *fraction1, Fraction *fraction2) {
  Fraction fraction;
  fraction.numerateur = (((fraction1->numerateur) * (fraction2->denominateur) - (fraction1->numerateur) * (fraction2->denominateur)));
  fraction.denominateur = (((fraction1->numerateur) * (fraction2->denominateur) * (fraction1->numerateur) * (fraction2->denominateur)));
  return fraction;
}
Fraction multiplier(Fraction *fraction1, Fraction *fraction2) {
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur) * (fraction2->numerateur));
  fraction.denominateur = ((fraction1->denominateur) * (fraction2->denominateur));
  return fraction;
}
Fraction diviser(Fraction *fraction1, Fraction *fraction2) {
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur) * (fraction2->denominateur));
  fraction.denominateur = ((fraction2->numerateur) * (fraction1->denominateur));
  return fraction;
}
Fraction ecrire() {
  Fraction fraction;
  printf("Entrer une fraction :\n");
  printf("Numerateur :\n");
  scanf("%d", &fraction.numerateur);
  printf("Denominateur :\n");
  scanf("%d", &fraction.denominateur);
  return fraction;
}
void afficherFraction(Fraction *fraction) {
  printf("%d/%d", fraction->numerateur, fraction->denominateur);
}

void afficherResultat(Fraction *fraction) {
  Fraction fractionSimplifie = simplifier(fraction);
  printf("Le resultat est : ");
  if (fractionSimplifie.denominateur != 1)
  {
    afficherFraction(&fractionSimplifie);
  }
  else {
    printf("%d", fractionSimplifie.numerateur);
  }
  printf("\n");
}

void comparer(Fraction *fraction1, Fraction *fraction2) {
  switch (comparerbis(fraction1, fraction2)) {
    case 0:
      afficherFraction(fraction1);
      printf(" = ");
      afficherFraction(fraction2);
      break;
    case 1:
      afficherFraction(fraction1);
      printf(" > ");
      afficherFraction(fraction2);
      break;
    case 2:
      afficherFraction(fraction1);
      printf(" < ");
      afficherFraction(fraction2);
      break;
    }
}
int comparerbis(Fraction *fraction1, Fraction *fraction2) {
  Fraction cloneFraction1 = *fraction1;
  Fraction cloneFraction2 = *fraction2;
  metreSurMemeDenominateur(&cloneFraction1, &cloneFraction2);
  if (cloneFraction1.numerateur > cloneFraction2.numerateur) {
    return 1;
  } else if (cloneFraction1.numerateur < cloneFraction2.numerateur) {
    return 2;
  } else {
    return 0;
  }
}
void metreSurMemeDenominateur(Fraction *fraction1, Fraction *fraction2) {
  fraction1->numerateur *= fraction2->denominateur;
  fraction2->numerateur *= fraction1->denominateur;
  int denominateurCommun = fraction1->denominateur * fraction2->denominateur;
  fraction1->denominateur = denominateurCommun;
  fraction2->denominateur = denominateurCommun;
}

#include "fonctions.h"

int gcd(Fraction *fraction1){
  int reste = 1;
  int dividende;
   int diviseur;
  if (fraction1->numerateur < fraction1->denominateur){
    dividende = fraction1->numerateur;
    diviseur = fraction1->denominateur;
  } else if (fraction1->numerateur > fraction1->denominateur){
    dividende = fraction1->denominateur;
    diviseur= fraction1->numerateur;
  } else {
    return fraction1->denominateur;
  }
  while (diviseur%dividende != 0){
    reste = diviseur%dividende;
    dividende = diviseur;
    diviseur = reste;
  }
  return reste;
}

Fraction simplifier(Fraction *fraction1){
  int pgcd = gcd(&fraction1);
  Fraction fraction;
  fraction.numerateur = (fraction1->numerateur)/pgcd;
  fraction.denominateur = (fraction1->denominateur)/pgcd;
  return fraction;
}

Fraction additionner(Fraction *fraction1, Fraction *fraction2){
  Fraction fraction;
  fraction.numerateur = (((fraction1->numerateur) * (fraction2->denominateur)) + ((fraction2->numerateur) * (fraction1->denominateur)));
  fraction.denominateur = (fraction1->denominateur * fraction2->denominateur);
  return fraction;
}

Fraction diviser(Fraction *fraction1, Fraction *fraction2){
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur) * (fraction1->denominateur));
  fraction.denominateur = ((fraction2->numerateur) * (fraction2->denominateur));
  return fraction;

}

Fraction ecrire(){
  Fraction fraction;
  printf("Entrer une fraction :\n");
  printf("Numerateur :\n");
  scanf("%d", &fraction.numerateur);
  printf("Denominateur :\n");
  scanf("%d", &fraction.denominateur);
  return fraction;
}

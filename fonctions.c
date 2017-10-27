#include "fonctions.h"

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

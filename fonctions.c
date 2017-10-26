#include "fonctions.h"

Fraction additionner(Fraction *fraction1, Fraction *fraction2){
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur * fraction2->denominateur) + (fraction2->numerateur * fraction1->denominateur));
  fraction.denominateur = (fraction1->denominateur * fraction2->denominateur)
  return fraction;
}

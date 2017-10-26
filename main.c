#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main()
{
  Fraction fraction1 = *creerFraction();
  Fraction fraction2 = *creerFraction();
  changerValeur(&fraction1, 912, 85);
  afficherFraction(&fraction1);
  printf("\n");
  changerValeur(&fraction2, 39, 3);
  afficherFraction(&fraction2);
  printf("\n");
  Fraction fraction3 = additionner(&fraction1, &fraction2);
  afficherFraction(&fraction3);
   printf("\n");
  comparer(fraction1, fraction2);
}

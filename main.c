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


  switch (comparer(&fraction1, &fraction2)) {
  case 0:
    afficherFraction(&fraction1);
    printf(" = ");
    afficherFraction(&fraction2);
    break;
  case 1:
    afficherFraction(&fraction1);
    printf(" > ");
    afficherFraction(&fraction2);
    break;
  case 2:
    afficherFraction(&fraction1);
    printf(" < ");
    afficherFraction(&fraction2);
    break;
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main()
{
  Fraction fraction1 = ecrire();
  Fraction fraction2 = ecrire();
  choisirOperation(&fraction1, &fraction2);

  return 0;
}

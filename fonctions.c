#include "fonctions.h"

void choisirOperation(Fraction *fraction1, Fraction *fraction2){
  printf("Choisir une opération : 1 - Additionner \n 2 - Soustraire \n 3 - Diviser \n 4 - Multiplier \n 5 - Comparer \n 6 - Simplifier \n");
  int operation;
  scanf("%d", &operation);

  switch (operation) {
  case 1:
    afficherFraction(additionner(&fraction1, &fraction2));
    break;
  case 2:
    afficherFraction(soustraire(&fraction1, &fraction2));
    break;
  case 3:
    afficherFraction(diviser(&fraction1, &fraction2));
    break;
  case 4:
    afficherFraction(multiplier(&fraction1, &fraction2));
    break;
  case 5:
    comparer(&fraction1, &fraction2);
    break;
  case 6:
    afficherFraction(simplifier(&fraction1));
    afficherFraction(simplifier(&fraction2));
    break;
  default:
    printf("Erreur de frappe, relancez la calculette.");
    break;
  }
}

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
  return simplifier(fraction);
}

Fraction diviser(Fraction *fraction1, Fraction *fraction2){
  Fraction fraction;
  fraction.numerateur = ((fraction1->numerateur) * (fraction1->denominateur));
  fraction.denominateur = ((fraction2->numerateur) * (fraction2->denominateur));
  return simplifier(fraction);

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

void afficherFraction(Fraction *fraction) {
  printf("Le resultat est : %d/%d", fraction->numerateur, fraction->denominateur);
}

void comparer(Fraction fraction1, Fraction fraction2){
  switch (comparerbis(&fraction1, &fraction2)) {
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
}

int comparerbis(Fraction *fraction1, FractioafficherFraction(simplifier(&fraction1));n *fraction2) {
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

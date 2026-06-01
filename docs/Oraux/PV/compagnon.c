#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "auxiliaire.h"
#include "compagnon.h"


void ajout_lettre(char c, liste lst){  // Q3
  // A COMPLETER
}

liste sous_mots_possibles(lexique *lex, char *mot, bool obligatoire){  // Q6
  if(lex == NULL){
    return NULL;
  }
  if(*mot == '\0'){
    if(!lex->fin){ //on n'est pas sur un mot du lexique
      return NULL;
    } else {
      liste res = NULL;
      // A COMPLETER (a) - debut
      /* res doit représenter une liste contenant un unique maillon
       * dont le mot est la chaîne vide, mais qui contient suffisamment
       * de place mémoire pour y écrire un mot de longueur LG_MAX */
      // A COMPLETER (a) - fin
      return res;
    }
  }
  liste lst1 = NULL;
  // A COMPLETER (b) - debut
  /* lst1 doit contenir les sous-mots possibles de mot 
   * qui contiennent sa première lettre, stockés à l'envers */
  // A COMPLETER (b) - fin

  liste lst2 = NULL;
  obligatoire = obligatoire || mot[1] == '\0'; //dernière lettre obligatoire

  if(!obligatoire){ //lettre pas obligatoire : on la saute
    // A COMPLETER (c) - debut
    /* lst2 doit contenir les sous-mots possibles de mot, 
     * qui ne contiennent pas sa première lettre, stockés à l'envers */
    // A COMPLETER (c) - fin
  }
  return union_listes(lst1, lst2);
}


int main(int argc, char **argv){
  //Début des tests ici
  
  liste lst = ex_liste_de_mots();

  //Fin des tests
  libere_liste(lst);
  if(argc == 2){
    lexique *lex = genere_lexique();
    liste lst = sous_mots_possibles(lex, argv[1], true);
    //    affiche_liste(lst);
    libere_liste(lst);
    libere_lexique(lex);
    return 0;
  }
  else{
    fprintf(stderr, "%s usage : %s w\n pour afficher les mots du lexique correspondant qui sont solutions du problème P pour un mot w passé en argument\n", argv[0], argv[0]);
    return 1;
  }
}

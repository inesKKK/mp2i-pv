#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "auxiliaire.h"


liste union_listes(liste lst1, liste lst2){
  if(lst1 == NULL){
    return lst2;
  }
  if(lst2 == NULL){
    return lst1;
  }
  liste m = lst1;
  while(m->suite != NULL){
    m = m->suite;
  }
  m->suite = lst2;
  return lst1;
}


int num(char c){
  return (int)c - (int)'a';
}

lexique *cree_lexique(){
  lexique *lex = (lexique *)malloc(sizeof(lexique));

  lex->fin = false;
  for(int i=0; i<ALPH; i=i+1){
    lex->s[i] = NULL;
  }
  
  return lex;
}

void ajoute_mot(lexique *lex, char *mot){
  if(*mot == '\0'){
    lex->fin = mot;
    return;
  }

  int nc = num(*mot); //code de la première lettre
  if(lex->s[nc] == NULL){
    lex->s[nc] = cree_lexique();
  }
  ajoute_mot(lex->s[nc], &mot[1]);
}

lexique *genere_lexique(){
  FILE *f = fopen("lexique.txt", "r");
  if(f == NULL){
    perror("Problème avec le fichier lexique.txt : vérifiez son nom et vos droits.\n");
    exit(1);
  }

  lexique *lex = cree_lexique();

  char s[LG_MAX+2];
  while((fscanf(f, "%s\n", s) != EOF)){
    ajoute_mot(lex, s);
  }

  fclose(f);

  return lex;
}

void libere_lexique(lexique *lex){
  if(lex == NULL){
    return;
  }
  for(int i=0; i < ALPH; i=i+1){
    libere_lexique(lex->s[i]);
  }
  free(lex);
}


void libere_liste(liste lst){
  if(lst->suite != NULL){
    libere_liste(lst->suite);
  }
  free(lst->mot);
  free(lst);
}


liste ex_liste_de_mots(){
  liste lst = malloc(sizeof(struct maillon)), p;
  p = lst;
  p->mot = malloc(sizeof(char) * (LG_MAX+1));
  p->mot = strcpy(p->mot, "nu");
  p->n = strlen(p->mot);
  p->suite = malloc(sizeof(struct maillon));
  p = p->suite;
  p->mot = malloc(sizeof(char) * (LG_MAX+1));
  p->mot = strcpy(p->mot, "xued");
  p->n = strlen(p->mot);
  p->suite = malloc(sizeof(struct maillon));
  p = p->suite;
  p->mot = malloc(sizeof(char) * (LG_MAX+1));
  p->mot = strcpy(p->mot, "siort");
  p->n = strlen(p->mot);
  p->suite = NULL;
  return lst;
}

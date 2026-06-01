#ifndef _AUXILIAIRE_H
#define _AUXILIAIRE_H

#include <stdbool.h>

/* Partie 1 : Fonctions auxiliaires */
struct maillon{
  char *mot;
  int n; // longueur du mot
  struct maillon *suite;
};

/** Une liste vide est donc représentée par NULL
 */
typedef struct maillon *liste;

/* CODE FOURNI -- la documentation doit vous suffire */
/** renvoie la liste obtenue en concaténant lst2 à la fin de lst1 */
liste union_listes(liste lst1, liste lst2);

/** libère la mémoire associée à une liste dont les mots ont été alloués
 * dynamiquement */
void libere_liste(liste lst);

/** renvoie une liste de mots contenant dans l'ordre les mots "un", "deux" et "trois" */
liste ex_liste_de_mots();

/* Partie 2 : Recherche de mots */
  
#define LG_MAX 30
#define ALPH 26

struct lexique{
  bool fin;
  struct lexique *s[ALPH];
};

typedef struct lexique lexique;

/* CODE FOURNI -- la documentation doit vous suffire */
/** genere un lexique dont les mots sont en lettres minuscules sans accents,
 * ni caractère autre (pas d'espace, ni de tiret par exemple),
 * la longueur d'un mot est garantie ne pas dépasser LG_MAX */
lexique *genere_lexique();

/** libere la mémoire allouée pour le lexique */
void libere_lexique(lexique *lex);

/** renvoie le numéro associé au caractère dans l'alphabet
 * ex : num('a') renvoie 0 et num('b') renvoie 1
 */
int num(char c);

#endif

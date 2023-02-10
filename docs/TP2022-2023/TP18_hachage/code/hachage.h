#ifndef _HACHAGE_H
#define _HACHAGE_H

#include "liste.h"

struct hachage {
  int lg; // nombre d'alvéoles
  struct maillon **alveoles; // tableau de listes d'alveoles
  int (*hacher)(int); // fonction de hachage (prend un entier en argument et renvoie un entier)
};

typedef struct hachage hachage;

/** n : entier strictement positif
 * hacher : une fonction qui prend un entier en argument et renvoie un entier compris entre 0 et n-1
 * sortie: table de hachage avec n alvéoles
 */
hachage init(int n, int (*hacher)(int, int));

/** h : table de hachage existante
 * val : valeur à ajouter
 * sortie : la valeur val est ajoutée à l'alvéole hacher(val) si elle n'appartenait pas à l'ensemble
 */
void ajout(hachage h, int val);

/** sortie : vrai si et seulement si val apparaît dans h
 */
bool element(hachage h, int val);

/** h : table de hachage existante
 * valeur à supprimer
 * sortie : la valeur val a été supprimée de h si elle appartenait à h
 */
void suppression(hachage h, int val);

/** affiche le contenu de h */
void contenu(hachage h);

/** vider le contenu de la table de hachage */
void vider(hachage h);
#endif

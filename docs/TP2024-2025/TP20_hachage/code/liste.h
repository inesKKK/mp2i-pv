#ifndef _LISTE_H
#define _LISTE_H

#include <stdbool.h>

struct maillon {
  int val;
  struct maillon *suivant;
};

typedef struct maillon *liste;

/** sortie : vrai si et seulement si val apparaît dans lst
 */
bool element_liste(int val, liste lst);

/** val : entier à ajouter
 * lst : liste d'entier
 * sortie : val a été ajouté en tête s'il n'appartenait pas déjà à lst, sinon lst est renvoyé
 */
liste ajout_liste(int val, liste lst);


/** val : entier à supprimer
 * lst : liste d'entier
 * sortie : val a été supprimé s'il appartenait à lst, sinon lst est renvoyé
 */
liste suppression_liste(int val, liste lst);

/** affiche le contenu de lst */
void contenu_liste(liste lst);

/** libere la mémoire de la liste */
void vider_liste(liste lst);
#endif

#ifndef _VARTAB_H_
#define _VARTAB_H_

/** constructeur : construit un tableau de taille variable à partir d'un tableau */
vartab_tt *new_vartab(int *tab, int n);
/** accesseur : renvoie l'entier en case i, t doit être non NULL, i un numero de case autorise */
int get(vartab_tt *t, int i);
/** transformateur : modifie la valeur de la case i, t doit être non NULL, i un numero de case autorise */
void set(vartab_tt *t, int i, int val);
/** accesseur : renvoie la longueur de la liste, t doit être non NULL */
int len(vartab_tt *t);
/** transformateur : ajoute un élément à la fin, t doit être non NULL */
struct vartab *append(vartab_tt *t, int val);
/** destructeur : libère la mémoire associée aux valeurs */
void delete_vartab(vartab_tt *t);
/** transformateur : supprime le dernier élément, t doit être non NULL */
int pop(vartab_tt *t);


#endif

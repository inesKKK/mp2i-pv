#ifndef _DESSIN_H_
#define _DESSIN_H_

/** fichier : nom de fichier d'extension .png
 * img : tableau bidimensionnel de booléens de dimensions hxl
 * sortie : image sauvegardée dans le fichier
 */
void sauvegarder(const char *fichier, bool **img, int h, int l);

#endif

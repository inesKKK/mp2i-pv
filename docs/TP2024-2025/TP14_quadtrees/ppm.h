#ifndef _PPM_H
#define _PPM_H

#include "image.h"

/** entrée : une image (non NULL)
 * sortie : affichage de l'encodage PPM P3 de l'image sur la sortie standard
 */
void affiche(image *tableau);

/** entrée : un nom de fichier supposé au format PPM P3 sans commentaire
 * sortie : l'image correspondante
 */
image *lecture(const char *fichier);


#endif

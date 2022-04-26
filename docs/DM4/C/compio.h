#ifndef _COMP_IO_H_
#define _COMP_IO_H_

#include <stdio.h>

struct hfile {
  FILE *f;
  unsigned char tampon; //le début du prochain caractère à écrire ou à lire
  int ou;                            //où on en est pour l'écriture
  char mode;                   //mode 'r' ou 'w'
};

typedef struct hfile hfile;

/** ouvre un flux en lecture ou écriture
 * pathname : chemin valide
 * mode : "r" ou "w" */
hfile *hopen(const char *pathname, const char *mode);
/** ferme le flux */
int hclose(hfile *stream);
/** écrit le contenue de la chaîne de caractères dans le flux
 * s : ne contient que des '0' et des '1' (et '\0' à la fin)
 * écriture du bit 0 ou du bit 1 */
void hwrite(hfile *stream, char *s);
/** lit 1 bit (si size=1) ou 1 octet (si size=8) et renvoie le résultat
 * le caractère de code ascii l'octet lu si size=8,
 * 0 ou différent de 0 si size=1
 * (comportement garanti uniquement s'il reste assez de bits à lire) */
unsigned char hread(hfile *stream, unsigned int size);
/** ferme le flux en vidant le buffer (complété par des 0 si besoin) s'il est en écriture */
int hclose(hfile *stream);
#endif

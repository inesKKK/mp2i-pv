#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define LONG 1024

struct liste_occ {
  int occ; //indice de début d'une occurence
  struct liste_occ *suite; //occurences suivantes
};

/** motif : le motif à analyser (chaîne de caractères)
    sortie : un tableau de la taille le nombre de valeurs du type char qui contient
    la dernière occurence de (char) i dans la case i, -1 si aucune occurence */
int *occ_droite(const char *motif){
  int *res = (int *)malloc(256*sizeof(int));

  for(int i=0; i<256; i=i+1){
    res[i] = -1;
  }
  for(int i=strlen(motif)-1; i >= 0; i=i-1){
    if(res[(int)motif[i]] == -1){
      res[(int)motif[i]] = i;
    }
  }

  return res;
}


/** liste des occurences du motif dans le texet à partir de l'indice debut, on transmet
    le tableaux des dernières occruences */
struct liste_occ *boyer_moore(FILE *fichier, char *texte, const char *motif, int debut_texte, int courante_fichier, int *droite){
  struct liste_occ *liste;
  int i;
    
  if(strlen(texte) - debut_texte < strlen(motif)){//il ne reste pas assez de texte -> on complète
    for(i=debut_texte; i<(int)strlen(texte); i=i+1){ //on décale ce qui reste au début
      texte[i-debut_texte] = texte[i];
    }
    for(; i<LONG; i=i+1){ //on récupère la suite dans le fichier
      if(fscanf(fichier, "%c", &texte[i-debut_texte]) == EOF){
        break;
      }
    }
    texte[i-debut_texte] = '\0';
    if(strlen(texte) < strlen(motif)){ //pas assez de texte pour trouver le motif
      return NULL;
    }

    return boyer_moore(fichier, texte, motif, 0, courante_fichier, droite);
  }
  
  for(int j=strlen(motif)-1; j>=0; j=j-1){//on compare le motif et le facteur
    if(texte[debut_texte+j] != motif[j]){
      if(droite[(int)motif[j]] >= j){
        return boyer_moore(fichier, texte, motif, debut_texte+1, courante_fichier+1, droite);
      } else {
        int decalage = j - droite[(int)motif[j]];
        return boyer_moore(fichier, texte, motif, debut_texte + decalage, courante_fichier+decalage, droite);
      }
    }
  }
  
  liste = (struct liste_occ *)malloc(sizeof(struct liste_occ));
  liste->occ = courante_fichier;
  liste->suite = boyer_moore(fichier, texte, motif, debut_texte+1, courante_fichier+1, droite);

  return liste;
}



void affichage(FILE *fichier, const char *motif){
  char texte[LONG+1];
  fscanf(fichier, "%1024s", texte);
  struct liste_occ *lst = boyer_moore(fichier, texte, motif, 0, 0, occ_droite(motif));
  int debut_ligne = 0, lg_motif = strlen(motif);
  char c;
  int i = -1;
  
  if(lst == NULL){
    return;
  }

  fseek(fichier, 0, SEEK_SET);
  while(true){
    int fin = fscanf(fichier, "%c", &c);
    i = i+1;
    if(fin == EOF){
      printf("\n");
    } else {
      printf("%c", c);
    }
    if(c == '\n' || fin == EOF){
      int pos = debut_ligne;
      while(lst != NULL && lst->occ <= i){
        for(int j=0; j < lst->occ - debut_ligne; j=j+1){
          printf(" ");
          pos = pos + 1;
        }
        while(pos < lst->occ + lg_motif){
          printf("^");
          pos = pos + 1;
        }
        debut_ligne = lst->occ + lg_motif;
        lst = lst->suite;
      }
      printf("\n");
      if(fin == EOF){
        break;
      }
      debut_ligne = i+1;
    }
  }
}


int main(void){
  FILE *fichier = fopen("texte2", "r");
  affichage(fichier, "aaa");
  fclose(fichier);
}

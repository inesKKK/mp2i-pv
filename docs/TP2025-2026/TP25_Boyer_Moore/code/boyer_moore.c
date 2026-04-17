#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
  for(int i=(int)strlen(motif)-1; i >= 0; i=i-1){
    if(res[(int)motif[i]] == -1){
      res[(int)motif[i]] = i;
    }
  }

  return res;
}


/** liste des occurences du motif dans le texet à partir de l'indice debut, on transmet
    le tableaux des dernières occruences */
struct liste_occ *boyer_moore(const char *texte, const char *motif, int debut, int *droite){
  struct liste_occ *liste;
  if(strlen(texte) - debut < strlen(motif)){
    return NULL;
  }
  for(int j=(int)strlen(motif)-1; j>=0; j=j-1){
    if(texte[debut+j] != motif[j]){
      if(droite[(int)motif[j]] >= j){
        return boyer_moore(texte, motif, debut+1, droite);
      } else {
        return boyer_moore(texte, motif, debut + j - droite[(int)motif[j]], droite);
      }
    }
  }
  liste = (struct liste_occ *)malloc(sizeof(struct liste_occ));
  liste->occ = debut;
  liste->suite = boyer_moore(texte, motif, debut+1, droite);
  return liste;
}


void affichage(const char *texte, const char *motif){
  struct liste_occ *lst = boyer_moore(texte, motif, 0, occ_droite(motif));
  int debut_ligne = 0, lg_motif = strlen(motif);
  
  if(lst == NULL){
    return;
  }

  for(int i=0; i<(int)strlen(texte); i=i+1){
    printf("%c", texte[i]);
    if(i == (int)strlen(texte)-1){
      printf("\n");
    }
    if(texte[i] == '\n' || i == (int)strlen(texte)-1){
      int pos = debut_ligne;
      while(lst != NULL && lst->occ <= i){
        for(int j=0; j < lst->occ - debut_ligne; j=j+1){
          printf(" ");
          pos = pos+1;
        }
        while(pos < lst->occ + lg_motif){
          printf("^");
          pos = pos + 1;
        }
        debut_ligne = lst->occ + lg_motif;
        lst = lst->suite;
      }
      printf("\n");
      debut_ligne = i+1;
    }
  }
}


int main(void){
  char *texte = "ceci est une tentative en tente cartonnee\net meme une autre tentative sur\nune autre ligne\n";
  char *motif="ten";
  //  texte = "aaabaaaaaabaabaaabbbaaaaaabba\naabbaaaabb";
  //  motif= "aaa";
  affichage(texte, motif);
}

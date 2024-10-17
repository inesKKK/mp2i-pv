#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "dessin.h"

void sauvegarder(const char *fichier, bool **img, int h, int l){
    FILE *file;
    int val;
    
    // ce qui suit sera vu plus tard dans l'année
    file = fopen("toto.ppm", "w");
    fprintf(file, "P3\n%d %d\n%d\n", l, h, 1);
    for(int j=0; j<h; j++){
        for(int i=0; i<l; i++){
            val = img[i][j] ? 0 : 1;
            fprintf(file, "%d %d %d ", val, val, val);
        }
        fprintf(file, "\n");
    }    
    fclose(file);
        
    // ce qui suit est complètement hors programme
    if(fork()==0){
        execl("/usr/bin/convert", "convert", "toto.ppm", fichier, NULL);
    }
    wait(NULL);
}

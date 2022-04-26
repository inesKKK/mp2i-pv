#include <stdlib.h>
#include "compio.h"

#define DEBUT 7
#define FIN (-1)
#define VIDE 0

hfile *hopen(const char *pathname, const char *mode){
  hfile *stream;
  FILE *f = fopen(pathname, mode);

  if(f == NULL){
    return NULL;
  }
  
  stream = (hfile *)malloc(sizeof(hfile));
  stream->f = f;
  stream->tampon = VIDE;
  stream->ou = DEBUT;
  stream->mode = *mode;

  return stream;
}

int hclose(hfile *stream){
  int res;
  
  if(stream->mode == 'w')
    fwrite(&stream->tampon, sizeof(char), 1, stream->f);
    
  res = fclose(stream->f);
  free(stream);
  return res;
}

void hwrite(hfile *stream, char *s){
  while(*s != '\0'){
    if(stream->ou == FIN){
      fwrite(&stream->tampon, sizeof(char), 1, stream->f);
      stream->tampon = VIDE;
      stream->ou = DEBUT;
    }
    stream->tampon |= ((*s == '1') ? 1 : 0 ) << stream->ou;
    stream->ou--;
    s++;
  }
}


unsigned char hread(hfile *stream, unsigned int size){
  if(size == 1){
    unsigned char res;
    if(stream->ou == DEBUT){
      if(fread(&stream->tampon, sizeof(char), 1, stream->f) == 0)
        return 0;
      stream->ou = FIN;
    }
    res = stream->tampon & (1<<DEBUT);
    stream->tampon <<= 1;
    stream->ou++;
    return res;
  }

  if(size == 8){
    unsigned char res = stream->tampon;
    int ou = stream->ou;

    if(fread(&stream->tampon, sizeof(char), 1, stream->f) == 0 && stream->ou != FIN)
      return 0;
    stream->ou = FIN;      

    res |= stream->tampon >> (DEBUT-ou);
    stream->tampon = stream->tampon << (ou+1);
    stream->ou = ou;
    return res;
  }

  return 0;
}

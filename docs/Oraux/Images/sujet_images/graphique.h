#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>

typedef unsigned char petit_entier ;

// Nos types
typedef SDL_Surface * image ;
typedef struct couleur {
  uint8_t r,v,b ;
} couleur ;

SDL_Window * gWindow ;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int HAUTEUR_FENETRE = SCREEN_HEIGHT ;
const int LARGEUR_FENETRE = SCREEN_WIDTH ;

void demarre_graphique() {
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    fprintf(stderr, "Problème au démarrage de SDL : %s\n", SDL_GetError() );
    exit(1);
  }
  //Create window
  gWindow = SDL_CreateWindow( "Concours CCMP", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN  );
  if( gWindow == NULL ) {
    fprintf(stderr, "Problème de création de fenêtre : %s\n", SDL_GetError() );
    exit(2);
  }
  int imgFlags = IMG_INIT_PNG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
    fprintf(stderr, "Problème avec SDL images : %s\n", IMG_GetError() );
    exit(3);
  }
}

void arrete_graphique() {
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  IMG_Quit();
  SDL_Quit();
}

image  charge_image(const char * chemin) {
  image  imgSurface = IMG_Load(chemin);  
  if( imgSurface == NULL ) {
    fprintf(stderr, "Problème avec l'ouverture de l'image au chemin %s!\n", chemin);
    exit(4);
  }
  return imgSurface;
}


int largeur_image(image img) {
  return img->w; 
}

int hauteur_image(image img) {
  return img->h; 
}

couleur couleur_du_pixel(const image  img, const int X, const int Y) {
  Uint8* pPixel = (Uint8*)img->pixels + Y * img->pitch + X * img->format->BytesPerPixel;
  Uint32 PixelData = *(Uint32*)pPixel;
  couleur Color ;
  SDL_GetRGB(PixelData, img->format, &Color.r, &Color.v, &Color.b);
  return Color;
}

void libere_image(image img) {
  SDL_FreeSurface(img);
}

void affiche_image(image img) {
  //Event handler
  SDL_Event e;
  SDL_SetWindowSize(gWindow, img->w, img->h);
  SDL_UpdateWindowSurface( gWindow );
  image  gScreenSurface = SDL_GetWindowSurface( gWindow );
  //While application is running
  while(1) {
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT )
        return ;
      if( e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_ESCAPE)
          exit(0);
        if(e.key.keysym.sym == SDLK_RIGHT)
          return ;
      }
    }
    //Apply the PNG image
    SDL_BlitSurface( img, NULL, gScreenSurface, NULL );
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
  }
}

image couleurs_vers_image(couleur * c, int largeur, int hauteur) {
  int channels = 3; // for a RGB image
  // populate pixels with real data ...  
  image surface = SDL_CreateRGBSurfaceFrom((void*)c,
                                                  largeur,
                                                  hauteur,
                                                  channels * 8,          // bits per pixel = 24
                                                  largeur * channels,  // pitch
                                                  0x0000FF,              // red mask
                                                  0x00FF00,              // green mask
                                                  0xFF0000,              // blue mask
                                                  0);                    // alpha mask (none)
  return surface;
}


int initialise = 0 ;

int nombre_aleatoire(int maxi) {
  if(!initialise) {
    srand (time(NULL));
    initialise = 1 ;
  }
  return rand()%maxi;
}

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "animation_logo.h"
void animation_logo()

{ 

	SDL_Surface *imageHP[900];
	SDL_Surface *ecran = NULL ;
 SDL_Init(SDL_INIT_EVERYTHING);
 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    int fr; 
    char imgname[900]; 
    for (fr=0; fr<900; fr++) 
    { 
        sprintf(imgname,"Logo/(%d).png",fr+1); 
        imageHP[fr]=IMG_Load(imgname);
        SDL_BlitSurface(imageHP[fr],NULL,ecran,NULL);
              SDL_Flip(ecran); 
              SDL_FreeSurface(imageHP[fr]);

    } 
 
}

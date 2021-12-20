#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"



int timer()
{
int tempsactuelle , tempsprecedant=0 , temps ;
tempsactuelle=SDL_GetTicks();
temps=tempsactuelle-tempsprecedant;
return temps;
}


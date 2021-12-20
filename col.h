#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y);
int collision_test(SDL_Surface *col,int x,int y);
int collision_back_bas(obstacle *ob , player *p);
int collision_back_haut(obstacle *ob , player *p);
int collision_back_droit_bas(obstacle *ob , player *p);
int collision_back_gauche_bas(obstacle *ob , player *p);

/*
int collision_test (SDL_Surface *mask,int x,int y,int height);
int pixel_test(SDL_Surface *surface,int x,int y);
*/

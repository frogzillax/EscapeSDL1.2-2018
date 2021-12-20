#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "personage.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGTH 600
  

typedef struct Map
{
 SDL_Surface *background;
 SDL_Rect dest;
 SDL_Rect src;
}map;
typedef struct obstacle
{
 SDL_Surface *background_masque;
 SDL_Rect dest;
 SDL_Rect src;

}obstacle;
void initialisation(map *m);
void draw_map(map m , SDL_Surface *ecran);
void srolling_map(map *m , player p);
void init_obstacle(obstacle *m);
void draw_obstacle(obstacle *m , map *p , SDL_Surface *ecran);
void saut (player *p,obstacle *m,input *boutton);
void gravite(player *p,obstacle *m);

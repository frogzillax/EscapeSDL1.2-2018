#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_mixer.h>
#include "map.h"
#include "trigo.h"

#define attack 2
#define mise_en_garde 5
#define apparition 1
#define mort 4
# define defense 3
# define endormi 0
struct enemie
{
SDL_Surface *boss[2];
SDL_Rect *enem[9];
SDL_Rect position; 
int vie;
int etat;
int vitesse;
int direction;
////////////paramètre d'animation/////////////////
int indice;
int tempsactuelle , tempsprecedant , tempsprecedant1 , tempsactuelle1;
};
typedef struct enemie enemie;

int timer();
afficher_ennemi(enemie *E ,map m, SDL_Surface *ecran);
void animation_apparision_attack(enemie* E,player *p,map m);
void animation_defense(enemie *E);
void animation_mort(enemie *E);
void timer1();
void  initialiser(enemie *monstre);
void deplacer_ennemi (enemie *monstre ,player *p,int vitesse);
void scroll (SDL_Rect *camera);
void InitVie(Vie *v);
void Life(Vie* v, SDL_Rect *position_perso);
void afficher_vie(Vie v , SDL_Surface* ecran);
void animation_bosse(SDL_Surface* ecran , enemie E);
void jouer_stage1(SDL_Surface *ecran , int *compteur_ecran);

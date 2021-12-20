#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#define PLAYER_WIDTH 95
#define PLAYER_HEIGTH 80
#define  TIME_BETWEEN_2_FRAMES 8
#define speed_move 1.5
#define GRAVITY_SPEED 0.6 
#define  MAX_FALL_SPEED 10
#define JUMP 1
#define sol 0

typedef struct 
{
	int vie;
	SDL_Surface* vies[7];
	SDL_Surface* vieBarre;
	SDL_Rect pos;
}Vie;

typedef struct  INPUT 
{
	int left;
	int down;
	int up;
	int right;
	int enter;
	int attack;
	int jump;
        int echap;
}input;

typedef struct personnage
{
SDL_Surface *sprinte[20];
SDL_Surface *sheet[4];

SDL_Rect src;
int x,y;//coordonne du personnage vu de face
int w,h;
int x1,y1;
int etat; //0.droite 1.gauche 2.mort 3.esquive 4.attaque 5.haut
int score;
int indice;//paramère d'animation
int nombreframe,frameTimer ;
Vie vie;

////////////variable utilisé pour la gestion des collision//////////////

int onGround, timerMort;
float dirX, dirY;



//gravité 
 int gravity , saut_etat;
 double v_x,v_y;
 ///////////////variable de saut///////
 double v_saut,v_grav;
 
}player;

void Getinput(input *boutton);
void initialiser_player(player *p);
void deplacer_player(player *p);
void animer_player(player *p);
void draw_player(player p,input boutton,SDL_Surface *ecran);
void initialise_input(input *p);
/*deplacement du joueur dans le bacjground vu de dessus*/
void init_player_haut(player *p);
void deplacer_player_dessus(player *p);
void anim_player_dessus(player *p);
void draw_player_dessus(player P,SDL_Surface *ecran,input boutton);

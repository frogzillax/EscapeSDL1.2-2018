
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "enemie.h"



void jouer_stage1(SDL_Surface *ecran , int *compteur_ecran)
{
SDL_Surface *vx;

AABB position_player,position_enem ,pos;
SDL_Event event;
enemie montres;
map m;
Vie v;
obstacle o;
int continuer=1, i=0;
input bouton;
player malcon;
SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
initialisation(&m);
init_obstacle(&o);
initialiser_player(&malcon);
initialise_input(&bouton);
initialiser(&montres);
InitVie(&v);
malcon.indice=6;
vx=IMG_Load("3.png");
int j;
int k;
bool collision;
int compteur;
int prec_position=0 , actuel_position;
while (continuer)
{   
	////////////uplaod 1//////////////
	actuel_position=malcon.x+malcon.w+m.src.x;
	montres.tempsactuelle=SDL_GetTicks();
	montres.tempsactuelle1=SDL_GetTicks();
	position_player.dest.x=malcon.x;
	position_player.dest.y=malcon.y;
	position_player.dest.w=malcon.w;
	position_player.dest.h=malcon.h;
	position_enem.dest=montres.position;
	j=collision_back_droit_bas(&o,&malcon);
	k=collision_back_gauche_bas(&o,&malcon);
    collision=Collision_AABB(position_enem,position_player);
    /////////////////affichage///////////
    draw_obstacle(&o,&m,ecran);
	draw_map(m,ecran);
	afficher_vie(malcon.vie,ecran);
	draw_player(malcon,bouton,ecran);
	afficher_ennemi(&montres,m,ecran);
	////////////////////input/////////////////
	Getinput(&bouton);

	////////////////uplaod 2///////////////

	//perso
	

	if(bouton.right==1 && j==0)
    {
    malcon.etat=0;
    animer_player(&malcon);
	deplacer_player(&malcon);
	srolling_map(&m,malcon);
    }
	else if (bouton.left==1 && k==0)
	{		
	malcon.etat=1;
	animer_player(&malcon );
	deplacer_player(&malcon);
	srolling_map(&m,malcon);
	}

   
	if(bouton.up==1 || (bouton.up==1 && bouton.left==1) || (bouton.up==1 && bouton.right==1))
	{
		malcon.saut_etat=JUMP;
		srolling_map(&m,malcon);
	}
	
	saut (&malcon,&o,&bouton);
	gravite(&malcon,&o);


  //ennemie
	if(actuel_position-prec_position>=1000)
	{
	 montres.etat=apparition;	
     prec_position=actuel_position;  
	}
	animation_apparision_attack(&montres,&malcon,m);
	//animation_defense(&montres);
    deplacer_ennemi (&montres,& malcon , 0);

   /* if (collision)
	{
		printf("collision=%d\n",1);
		Life(&malcon.vie,&montres.position);
	}*/

if(bouton.echap==1)
{
*compteur_ecran=0;
continuer=0;
}

	
	     
        
    SDL_Delay(1);
    SDL_Flip(ecran);
}
SDL_Delay(18);
}

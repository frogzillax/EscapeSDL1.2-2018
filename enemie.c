#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_mixer.h>
#include "enemie.h"
////////////////etat 1. apparisiont 2. attaque 3. defense 4 . mort////////////////////

void deplacer_ennemi (enemie *monstre ,player *p,int vitesse)
{
int i;

srand(time(NULL));
   // should only be called once
int min, max ;

min = 100 ;
max = 600;//generer un nombre entre 0 et 800 //
 //redo the loop if min is supp or equal to max (which is not what we want )

 if((monstre->vie!=0 && monstre->etat==2) && monstre->indice==2 && ((monstre->tempsactuelle)-(monstre->tempsprecedant))>=100)
 {
  monstre->tempsprecedant=monstre->tempsactuelle;
	if (monstre->position.x >=max)
		monstre->direction = 0;            
	if (monstre->position.x <= min)
		monstre->direction = 1;

	if ( monstre->direction == 1)
		monstre->position.x +=1.5+vitesse;
	if (monstre->direction == 0)
		monstre->position.x -=1.5+vitesse; 
}
}







void animation_apparision_attack(enemie* E , player *p , map m)

{ 

if (E->etat==apparition) 
{  
    if(E->indice<2 && ((E->tempsactuelle1)-(E->tempsprecedant1))>=800)
    {  
      E->tempsprecedant1=E->tempsactuelle1;
    	E->indice++;
    } 
   else if(E->indice==2 || E->etat==attack)
    {
   E->etat=attack;
   E->indice=2;
    }
 }
}

void animation_defense(enemie *E)
{
   if(((E->tempsactuelle)-(E->tempsprecedant))>=4000)
	{   
	    E->etat=defense; 
        E->indice=4;//defense//
        
        E->tempsprecedant=E->tempsactuelle;
	}
	else if(((E->tempsactuelle)-(E->tempsprecedant))>=1000)
	{
		if(E->vie>0)
		{
         E->etat=attack;//attacc
         E->indice=2;
		}
		else 
		{
		 E->etat=mort;//mort//
		}
	}

}

void animation_mort(enemie *E)
{
  if(E->etat==4 && E->vie==0)
  {
  	if (E->indice>=9 || E->indice<5)
  	{
        E->indice=5;
  	}
    E->indice++;
}
}

void  initialiser(enemie *monstre)
{
   
   monstre->enem[0]= IMG_Load("personnage/sprint/aparision1.png");
   monstre->enem[1]= IMG_Load("personnage/sprint/aparision2.png");
   monstre->enem[2]= IMG_Load("personnage/sprint/aparision3.png");
   monstre->enem[3]= IMG_Load("personnage/sprint/def1.png");
   monstre->enem[4]= IMG_Load("personnage/sprint/def2.png");
   monstre->enem[5]= IMG_Load("personnage/sprint/def3.png");
   monstre->enem[6]= IMG_Load("personnage/sprint/mort1.png");
   monstre->enem[7]= IMG_Load("personnage/sprint/mort2.png");
   monstre->enem[8]= IMG_Load("personnage/sprint/mort3.png");

   monstre->position.x=600;
   monstre->position.y=400;
   monstre->position.w=monstre->enem[2]->w;
   monstre->position.h=monstre->enem[2]->h;

   monstre->vie=1;
   monstre->etat=endormi; 
   monstre->direction=0; /*1=apparision*/
   monstre->indice=-1;
   monstre->tempsprecedant=0;
   monstre->tempsprecedant1=0;
 }





afficher_ennemi(enemie *E ,map m, SDL_Surface *ecran)
{
 //printf("%d\n",E->tempsactuelle);
//E->position.x=(E->position.x-m.src.x);   
if(E->etat!=endormi)
{
SDL_BlitSurface(E->enem[E->indice],NULL,ecran,&E->position);
}	
}

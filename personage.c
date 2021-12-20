#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "personage.h"

Getinput(input *boutton)
{

	SDL_Event event;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        boutton->echap=1;
                    break;
                    case SDLK_c:
                        boutton->jump = 1;
                    break;

                      case SDLK_v:
                         boutton->attack = 1;
                    break;

                    case SDLK_LEFT:
                         boutton->left = 1;
                    break;

                    case SDLK_RIGHT:
                         boutton->right = 1;
                    break;

                    case SDLK_DOWN:
                         boutton->down = 1;
                    break;

                    case SDLK_UP:
                         boutton->up = 1;
                    break;

                    case SDLK_RETURN:
                         boutton->enter = 1;
                    break;
                    case SDLK_y:
                        boutton->y=1;
                        break;
                      case SDLK_n:
                        boutton->n=1;
                        break;   


                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        boutton->echap=0;
                    break;

                    case SDLK_c:
                         boutton->jump = 0;
                    break;

                    case SDLK_LEFT:
                         boutton->left = 0;
                    break;

                    case SDLK_RIGHT:
                         boutton->right = 0;
                    break;

                    case SDLK_DOWN:
                         boutton->down = 0;
                    break;

                    case SDLK_UP:
                         boutton->up = 0;
                    break;

                    case SDLK_RETURN:
                         boutton->enter = 0;
                    break;
                     case SDLK_y:
                        boutton->y=0;
                        break;
                      case SDLK_n:
                        boutton->n=0;
                        break;   


                    default:
                    break;
                }
            break;

        }

    }
}
initialise_input(input *p)
{
p->left=0;
p->right=0;
p->down=0;
p->up=0;
p->attack=0;
p->jump=0;
}
/////////fonctie vie /////////////////////////
void InitVie(Vie *v)
{
  v->vie =6;
  v->vies[1] =IMG_Load("life/6.png");
  v->vies[2] =IMG_Load("life/5.png");
  v->vies[3] =IMG_Load("life/4.png");
  v->vies[4] =IMG_Load("life/3.png");
  v->vies[5] =IMG_Load("life/2.png");
  v->vies[6] =IMG_Load("life/1.png");
  v->vieBarre = v->vies[6] ;
  v->pos.x = -50;
  v->pos.y = -330;
}
////////////////////////////////////////////////////
void Life(Vie* v,SDL_Rect *position_perso)
{
  if(v->vie >0)
  {
          (v->vie)--;
          int i=v->vie;
        printf("vie=%d\n",v->vie);
        v->vieBarre = v->vies[i];
          position_perso->x=600;
          position_perso->y=430;
  }
}
void afficher_vie(Vie v , SDL_Surface* ecran)
{

  SDL_BlitSurface(v.vies[v.vie],NULL,ecran,&v.pos);
  printf("0 affichage");
}


initialiser_player(player *p)
{
	//chargement des images
p->sprinte[0]=IMG_Load("sprite/1a.png");
p->sprinte[1]=IMG_Load("sprite/2a.png");
p->sprinte[2]=IMG_Load("sprite/3a.png");
p->sprinte[3]=IMG_Load("sprite/4a.png");
p->sprinte[4]=IMG_Load("sprite/5a.png");
p->sprinte[5]=IMG_Load("sprite/6a.png");
p->sprinte[6]=IMG_Load("sprite/7a.png");
p->sprinte[7]=IMG_Load("sprite/1b.png");
p->sprinte[8]=IMG_Load("sprite/2b.png");
p->sprinte[9]=IMG_Load("sprite/3b.png");
p->sprinte[10]=IMG_Load("sprite/4b.png");
p->sprinte[11]=IMG_Load("sprite/5b.png");
p->sprinte[12]=IMG_Load("sprite/6b.png");
p->sprinte[13]=IMG_Load("sprite/7b.png");
p->sprinte[14]=IMG_Load("sprite/mort1.png");
p->sprinte[15]=IMG_Load("sprite/mort2.png");


   //initialisation des positiond e debut
p->x=30;
p->y=-4;
p->w=p->sprinte[0]->w;
p->h=p->sprinte[0]->h;
   //initialisation des variable d'animation
p->etat=0;
p->frameTimer=0;
p->indice=0;
   //variable de vie 
InitVie(&p->vie); 
p->etat_sprituelle=VIVANT;  

////////initialisation des variable de collision/////////
p->onGround=0; 
p->timerMort=0;

    p->v_x = 1.5;
    p->gravity=0;
    p->v_grav = 0.3;
    p->v_saut = -11;
    p->v_y =0;
    p->saut_etat=JUMP;


}

deplacer_player(player *p)
{
   if(p->saut_etat==sol && p->etat_sprituelle==VIVANT)
   {
	 switch (p->etat)
                    {
                    case 0:
                  if (p->x<=300)
                  p->x +=speed_move;
                  break;
                    case 1:
                    if ( p->x>0)
                    p->x -=speed_move;
                    break;
                    }

   }
   
                    

}

animer_player(player *p)
{
	if(p->saut_etat==sol && p->etat_sprituelle==VIVANT)
	{
	
 if(p->frameTimer<0 )
   {
   	p->frameTimer=TIME_BETWEEN_2_FRAMES;
 switch (p->etat)
{
case 0:
if (p->indice>=6)
p->indice=1;
else p->indice++;
break;
case 1:
if (p->indice>6 && p->indice<12)
p->indice++;
else p->indice=7;
break;
}
}
else
  p->frameTimer--;
	}
	if(p->etat_sprituelle==MORT)
   {
    p->indice=13;
    SDL_Delay(300);
    p->indice++;
   }
  
}

draw_player(player p,input boutton,SDL_Surface *ecran)
{

SDL_Rect dest;
dest.x=p.x;
dest.y=p.y;
dest.h=p.sprinte[0]->h;
dest.w=p.sprinte[0]->w;


   if (p.etat==0 && (boutton.right==0))  
      SDL_BlitSurface(p.sprinte[1], NULL,ecran, &dest);
   else if (p.etat==1 && boutton.left== 0) 
      SDL_BlitSurface(p.sprinte[7], NULL, ecran, &dest); 

  else if(boutton.right==1 || boutton.left==1)
  {
  	 SDL_BlitSurface(p.sprinte[p.indice], NULL, ecran, &dest);
  }                        
}



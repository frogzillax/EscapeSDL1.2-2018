#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "map.h"
void initialisation(map *m)
{
  m->background=IMG_Load("personnage/stage/back1.jpg");
  m->dest.x=0;
  m->dest.y=0;
  m->dest.w=m->background->w;
  m->dest.h=m->background->h;
  
  m->src.x=0;
  m->src.y=0;
  m->src.w=m->background->w;
  m->src.h=m->background->h;	
}

void init_obstacle(obstacle *m )
{

  m->background_masque=IMG_Load("personnage/obstacle/back1masque.png");
  m->dest.x=0;
  m->dest.y=0;
  m->dest.w=m->background_masque->w;
  m->dest.h=m->background_masque->h;

  m->src.x=0;
  m->src.y=0;
  m->src.w=m->background_masque->w;
  m->src.h=m->background_masque->h;

}

void srolling_map(map *m , player p)
{
   switch(p.etat)
    {
    case 0:

     if(p.x>=200)
        if(m->src.x<7205)
        {
        m->src.x +=1.5;
        }
        break;

    case 1:
          if(m->src.x>0)
          {
        m->src.x -=1.5;
          }
        break;
    }


}

void draw_map(map m , SDL_Surface *ecran)
{
	SDL_BlitSurface(m.background,&m.src,ecran,&m.dest);
}
void draw_obstacle(obstacle *m , map *p, SDL_Surface *ecran)
{
  m->src=p->src;
  SDL_BlitSurface(m->background_masque,&m->src,ecran,&m->dest);
}


////////////////////////////////////////////saut /////////////////////////////

void saut (player *p,obstacle *m,input *boutton)
{
  if(p->saut_etat==JUMP)
  {
                     
            if (boutton->up==1 && p->etat==0 && p->x<=570 && boutton->right== 1 && boutton->left==0)
            {
            p->x +=p->v_x;
            p->y +=p->v_y;
            }
              if (boutton->up==1 && p->etat==1 && p->x >200 && boutton->left== 1 && boutton->right== 0)
            {  
            p->x -=p->v_x;
            p->y +=p->v_y;
            }
              if (boutton->left ==0 && boutton->right==0)
            {
            p->y +=p->v_y;
            }             
             
}
}

void gravite(player *p , obstacle *m)
{
        
      
        
      if (collision_back_bas(m ,p))
      {
       p->v_y=p->v_saut;
       p->saut_etat=sol;
      }

      else
      {
        p->v_y += p->v_grav;
        p->saut_etat=JUMP;           
      }
}

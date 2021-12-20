
#include "col.h"


///////////////////////////////////////////////////////////
SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_test(SDL_Surface *col,int x,int y)
{
  SDL_Color c;

        int i,r;
          c=GetPixel(col,x,y);
          printf("R = %d |G = %d |B = %d |\n",c.r,c.g,c.b);
          if(c.r==255 && c.g==255 && c.b==255)
         return 1; 
        else
        return 0;   
}

int collision_back_bas(obstacle *ob , player *p)
{
  int i=collision_test(ob->background_masque,p->x+p->w/2+ob->src.x,ob->src.y+p->y+p->h);
   printf("%d\n",p->x+p->w+ob->src.x);
     if(i==1)
     	return 1;
     else 
     	return 0;
}
int collision_back_haut(obstacle *ob , player *p)
{
	int i=collision_test(ob->background_masque,p->x+p->w/2+ob->src.x,p->y+ob->src.y);
	   if(i==1)
	   	return 1;
	   else 
	   	return 0;
}

int collision_back_droit_bas(obstacle *ob , player *p)
{
 int i=collision_test(ob->background_masque,p->x+p->w+ob->src.x,p->y+p->h+ob->src.y-10);
 printf("%d\n",p->x+p->w+ob->src.x);
  if(i==1)
  	return 1;
  else 
  	 return 0;


}
int collision_back_gauche_bas(obstacle *ob , player *p)
{
 int i=collision_test(ob->background_masque,p->x+ob->src.x,p->y+p->h-ob->src.y-10);
  if(i==1)
  	return 1;
  else 
  	 return 0;
}
















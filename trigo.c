#include "trigo.h"


/*cllision de deux antité rectangle*/

bool Collision_AABB(AABB box1,AABB box2)
{
   if((box2.dest.x >= box1.dest.x + box1.dest.w)                   // trop à droit
    ||(box2.dest.x + box2.dest.w <= box1.dest.x)                  // trop à gauche
	|| (box2.dest.y >= box1.dest.y + box1.dest.h)                      // trop en bas
	|| (box2.dest.y + box2.dest.h <= box1.dest.y)){
                                               // trop en haut
     return false;
 }
    
   else
          return true; 
}


bool Collision_cercle(SDL_Rect dest , cercle c)
{
   int d2 = (dest.x-c.x)*(dest.x-c.x) + (dest.y-c.y)*(dest.y-c.y);
   if (d2>c.rayon*c.rayon)
   {
      return false;
   }
   else
      return true;
}


bool Collision_2cercle(cercle C1,cercle C2)
{
   int d2 = (C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y);
   if (d2 > (C1.rayon + C2.rayon)*(C1.rayon + C2.rayon)){
      return false;
   }
   else
      return true;
}

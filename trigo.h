  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h> 
  #include <SDL/SDL.h>

 typedef bool;
 #define true 1;
 #define false 0;


 typedef struct 
 {
  
SDL_Rect dest;
 }AABB;

struct cercle
{
   int x,y;
   int rayon;
};
typedef struct cercle cercle;










bool Collision_AABB(AABB box1,AABB box2);
bool Collision_cercle(SDL_Rect dest , cercle C);
bool Collision_2cercle(cercle C1,cercle C2);
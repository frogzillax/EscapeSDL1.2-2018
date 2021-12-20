


#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct personnage personnage;
typedef struct box box;
typedef struct enemie enemie;
typedef struct stage stage  ;
//////pas très utile ///////////////
struct box
{
 SDL_Surface  *obstacle;
 SDL_Rect position;
 float w;
 float h;
};
////////////////////////////////

struct enemie
{
SDL_Surface *boss[2];
SDL_Rect *enem[8];
SDL_Rect position; 
int vie;
int etat;
};

struct personnage
{
SDL_Surface tab_image[4][4],*mort;
int vie;
int score;
Mix_Chunk *son,*son1;
int etat;
SDL_Rect position;
int h;
int w;
};

struct stage 
{
SDL_Surface *tab[4];
SDL_Rect position;
Mix_Music *musique;
int etat;
int partie;
};

int timer();



#endif /* FONCTIONS_H_ */ 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"


int main(int argc, char *argv[])

{     
	

    SDL_Surface *ecran = NULL;
    int continuer=1,compteurecran=-1;


    SDL_Surface *imageDeFond = NULL, *new_game = NULL,*continues=NULL, *multi=NULL,*help=NULL,*option=NULL,*exit=NULL,*background0; 
    SDL_Event event;
    SDL_Rect positionFond,pnewgame,pcontinue,pmulti,phelp,poption,pexit;
    
    int compteurblit=1,compteur=0,droite=1,gauche=1;

    /*declaration variable du text*/

    SDL_Rect positiontext;
    TTF_Font *police = NULL,*policechap;/*police*/
    SDL_Color couleurNoire = {0, 0, 0}; /*couleur du texte*/

    SDL_Surface *newgametext,*continuestext,*helptext,*multiplayertext,*optiontext,*echaptext,*keytext;
   
   /*ecran pour les stage*/

SDL_Surface *Map,*exitbackground,*no,*yes;
SDL_Rect positionstage1,positionmap,positionechap,positionexit,pno,pyes,pkeytext;

positionechap.x=255;
positionechap.y=575;

positionstage1.x=0;
positionstage1.y=0;

positionmap.x=0;
positionmap.y=0;

positionexit.x=0;
positionexit.y=0;

pno.x=0;
pno.y=0;

pyes.x=0;
pyes.y=0;

pkeytext.x=300;
pkeytext.y=544;
/////////////////////////////

    positiontext.x=321;
    positiontext.y=528;

    positionFond.x = 0;
    positionFond.y = 0;

    pnewgame.x =-305.365;
    pnewgame.y =-145.50;

    pexit.x=-304;
    pexit.y=235;

    phelp.x=-306;
    phelp.y=162.50;

    poption.x=-305.50;
    poption.y=76;

    pmulti.x=-305.50;
    pmulti.y=8.50;

    pcontinue.x= -305.00; 
    pcontinue.y=-69.50;    

     
    SDL_Init(SDL_INIT_VIDEO);


    //initialisation du texte

    TTF_Init();
    police = TTF_OpenFont("roch.ttf", 60);
    policechap=TTF_OpenFont("roch.ttf",30);
TTF_SetFontStyle(police, TTF_STYLE_ITALIC);
newgametext = TTF_RenderText_Blended(police, "newgame", couleurNoire);
continuestext=TTF_RenderText_Blended(police, "continue", couleurNoire);
helptext=TTF_RenderText_Blended(police, "help", couleurNoire);
multiplayertext=TTF_RenderText_Blended(police, "multipluyers", couleurNoire);
optiontext=TTF_RenderText_Blended(police, "option", couleurNoire);
echaptext=TTF_RenderText_Blended(policechap,"press ESCAPE to return main menu",couleurNoire);
keytext=TTF_RenderText_Blended(policechap,"press any key",couleurNoire);


//////////////////////////////////////////////////////////    
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("MENU", NULL);
  background0=IMG_Load("background.jpg");
imageDeFond = IMG_Load("menu3.jpg");
SDL_BlitSurface(background0, NULL, ecran, &positionFond);
SDL_BlitSurface(keytext,NULL,ecran,&pkeytext);
SDL_Flip(ecran);



	


/*chargement du song*/

 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer

   {

      printf("%s", Mix_GetError());

   }

 Mix_VolumeMusic(MIX_MAX_VOLUME); //Mettre le volume à la moitié

   Mix_Music *musique; //Création d'un pointeur de type Mix_Music

  musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
   
    Mix_AllocateChannels(32);
   Mix_Chunk *son,*son1;
   son = Mix_LoadWAV("son.wav");
   son1=Mix_LoadWAV("son1.wav");
   Mix_VolumeChunk(son, MIX_MAX_VOLUME);
   Mix_VolumeChunk(son1, MIX_MAX_VOLUME);
    /*chargement des surface menu*/
    new_game = IMG_Load("newgame.png");
    continues = IMG_Load("continues.png");
      multi = IMG_Load("multiplayers.png");
      option = IMG_Load("option.png");
      help = IMG_Load("help.png");
      exit = IMG_Load("exit.png");
      Map=IMG_Load("map.png");     
      exitbackground=IMG_Load("exitbackground.png");
      no=IMG_Load("no.png");
      yes=IMG_Load("yes.png");
    int time=0;
    int state =0;
    int t2=0;
    int t1=SDL_GetTicks();
/////////////////////////chargement_menu_option//////////////////////////////////////////////

    SDL_Surface *background_option;
    background_option=IMG_Load("backoption.png");

     int vol=Mix_VolumeMusic(MIX_MAX_VOLUME);


////////////////////////////////

    //animation_logo();
  while(continuer)

{
     ////////////////////upload/////////////////////



















    
   switch(compteurecran)
 {


////////////////////////////////////////animation///////////////////////////////////////////////////////////

case -1:

{
int temps;
	//temps=timer();
if(time==0)
{
  SDL_BlitSurface(background0, NULL, ecran, &positionFond);
 SDL_Delay(300);
SDL_BlitSurface(keytext,NULL,ecran,&pkeytext);

time=1;
}
else if(time==1)
{
SDL_Delay(300);
SDL_BlitSurface(background0, NULL, ecran, &positionFond);
time=0;	
}

SDL_PollEvent(&event);
    switch(event.type)
    {

            case SDL_QUIT: /* Si c'est un événement QUITTER */

                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */

                break;

            case SDL_KEYDOWN:

                    
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                     SDL_Flip(ecran);
             compteurecran=0;
                     break;
     }   
    
     }      
break;





///////////////////////////////////////////menu//////////////////////////////////////////////////////








case 0:

    SDL_WaitEvent(&event);
    switch(event.type)
    {

            case SDL_QUIT: /* Si c'est un événement QUITTER */

                continuer= 0; /* On met le booléen à 0, donc la boucle va s'arrêter */

                break;

            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;

                    /*augementé et béssé le volume*/




                    /*blit button avec le dwon*/    

                  case SDLK_DOWN:  
                 switch(compteurblit) 
                 { 

                  case 1:
                    
                    pnewgame.x =-305.365;
                    pnewgame.y =-145.50;
                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(new_game, NULL, ecran, &pnewgame);
                  SDL_Flip(ecran);
                   break;
                    
                    case 2:

                      pcontinue.x= -305.00; 
                      pcontinue.y=-69.50;    


                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                   SDL_BlitSurface(continues, NULL, ecran, &pcontinue);
                  SDL_Flip(ecran);

                  compteur=1;

                  break;

                  case 3:
                
    pmulti.x=-305.50;
    pmulti.y=8.50;

               SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(multi, NULL, ecran, &pmulti);
                  SDL_Flip(ecran);

                  compteur=2;

                  break;

                  case 4:
                 poption.x=-305.50;
                  poption.y=76;

                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(option, NULL, ecran, &poption);
                  SDL_Flip(ecran);
                  compteur=3;

                  break;

              
                  case 5:
                  phelp.x=-306;
                  phelp.y=162.50;

                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(help, NULL, ecran, &phelp);
                  SDL_Flip(ecran);
                  compteur=4;
                   
                   break; 
                  
                 case 6:
                 pexit.x=-304;
                  pexit.y=235;

         SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(exit, NULL, ecran, &pexit);
                  SDL_Flip(ecran);
                  compteur=5;
                  compteurblit=0;
                SDL_WaitEvent(&event);
                  if(event.type==SDL_KEYDOWN)
                  {

                    if(event.key.keysym.sym==SDLK_KP_ENTER)

                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */

                break;


                 }
                   
                 break;

                 }
                 Mix_PlayChannel(1, son, 0);

compteurblit++;               
                  break;

                  /*case SDLK_RETURN:
     if(compteurblit==1)
     {
     	           SDL_BlitSurface(newgametext, NULL, ecran, &positiontext); 
          
       compteurecran=5; 
       compteurecran=5;

     }
     else if(compteurblit==2) 
     {
         SDL_BlitSurface(continuestext, NULL, ecran, &positiontext);
     }  
     else if (compteurblit==3)
     {
     	
           SDL_BlitSurface(multiplayertext, NULL, ecran, &positiontext); 
     }
     else if (compteur==4)
     {
     	SDL_BlitSurface(optiontext, NULL, ecran, &positiontext); 
     	compteurecran=3;
     }
     else if (compteurblit==5)
     {
     	
     }
     else if (compteurblit==6)
     {
     	compteurecran=2;
     }


           break;   */    





                  /*blittage avec les case up*/



 case SDLK_UP:
 
          switch(compteur)

                 { 
                   case 0:
                  pexit.x=-304;
                  pexit.y=235;

         SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(exit, NULL, ecran, &pexit);
                  SDL_Flip(ecran);
                  compteurblit=1;
                  compteur=6;
                    break;
                    
                    case 1:
                    pnewgame.x =-305.365;
                    pnewgame.y =-145.50;
                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(new_game, NULL, ecran, &pnewgame);
                  SDL_Flip(ecran);
                  compteurblit=2;
                   break;

                      

                  case 2:
                  pcontinue.x= -305.00; 
                      pcontinue.y=-69.50;    


                      SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                      SDL_BlitSurface(continues, NULL, ecran, &pcontinue);
                      SDL_Flip(ecran);
                          compteurblit=3;
                  break;
                
                    pmulti.x=-305.50;
                    pmulti.y=8.50;

               SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(multi, NULL, ecran, &pmulti);
                  SDL_Flip(ecran);
                          
                  break;

                  case 3:
                  pmulti.x=-305.50;
                    pmulti.y=8.50;

               SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(multi, NULL, ecran, &pmulti);
                  SDL_Flip(ecran);
                  compteurblit=4;

                  break;
                 

              
                  case 4:
                  poption.x=-305.50;
                  poption.y=76;

                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(option, NULL, ecran, &poption);
                  SDL_Flip(ecran);

                  compteurblit=5;

                  break;
                  
                  
                 case 5:
                 phelp.x=-306;
                  phelp.y=162.50;

                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(help, NULL, ecran, &phelp);
                  SDL_Flip(ecran);

                  compteurblit=6; 
                   break; 
                 
             }
compteur--;
Mix_PlayChannel(1, son, 0);


break;
          
        }

break;
//case SDL_MOUSEBUTTONUP:

//printf("x=%d \n y=%d \n",event.button.x,event.button.y);
case SDL_MOUSEMOTION:
            if ((event.motion.x>=24 && event.motion.x<=214) &&(event.motion.y>=131 && event.motion.y<=189))
             {
                Mix_PlayChannel(2, son, 0);

                pnewgame.x =-305.365;
                 pnewgame.y =-145.50;
                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(new_game, NULL, ecran, &pnewgame);
                  SDL_Flip(ecran);

                  compteurblit=5;
                  compteur=0;

              }   

             else if ((event.motion.x>=27.205 && event.motion.x<=204.205) &&(event.motion.y>=205 && event.motion.y<=256)) 
             {
                Mix_PlayChannel(2, son1, 0);

                               pcontinue.x= -305.00; 
                      pcontinue.y=-69.50;    


                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                   SDL_BlitSurface(continues, NULL, ecran, &pcontinue);
                  SDL_Flip(ecran);

                    compteurblit=3;
                    compteur=1;
     
             
             }
else if ((event.motion.x>=24 && event.motion.x<=210) &&(event.motion.y>=279 && event.motion.y<=337))
              {
Mix_PlayChannel(2, son, 0);

pmulti.x=-305.50;
                    pmulti.y=8.50;

               SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(multi, NULL, ecran, &pmulti);
                  SDL_Flip(ecran);

                  compteurblit=4;
                  compteur=2;

              }
else if ((event.motion.x>=19 && event.motion.x<=207) &&(event.motion.y>=352 && event.motion.y<=405)) 

      {
Mix_PlayChannel(2, son, 0);

poption.x=-305.50;
                  poption.y=76;

                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_BlitSurface(option, NULL, ecran, &poption);
                  SDL_Flip(ecran);
        compteurblit=5;
        compteur=2;

      }    

else if ((event.motion.x>=24 && event.motion.x<=214) &&(event.motion.y>=505 && event.motion.y<=567)) 
{
    Mix_PlayChannel(2, son, 0);
           
            
        pexit.x=-304;
                  pexit.y=235;

         SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(exit, NULL, ecran, &pexit);
                 SDL_Flip(ecran);
   SDL_WaitEvent(&event);
                  if(event.type==SDL_KEYDOWN)
                  {

                    if(event.key.keysym.sym==SDLK_KP_ENTER)

                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */

                break;


                  }  
          compteurblit=1;  
          compteur=5;    

}

else if ((event.motion.x>=25 && event.motion.x<=213) &&(event.motion.y>=433 && event.motion.y<=485)) 

{
Mix_PlayChannel(2, son, 0);

                phelp.x=-306;
                  phelp.y=162.50;

                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                 SDL_BlitSurface(help, NULL, ecran, &phelp);
                  SDL_Flip(ecran);
     compteurblit=6;           

}
/// affichage old button 
else if ((event.motion.x>=252 && event.motion.x<=792.17) &&(event.motion.y>=3 && event.motion.y<=789))
{
     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
     SDL_Flip(ecran);
/* code */
}
else if ((event.motion.x>=31 && event.motion.x<=208) &&(event.motion.y>=3 && event.motion.y<=111))
{
    
     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
     SDL_Flip(ecran);
/* code */
}

             break;
             
case SDL_MOUSEBUTTONUP:
   if (event.button.button == SDL_BUTTON_LEFT) /* On arrête le programme si on a fait un clic droit */
    {
       if((event.button.x>=24 && event.button.x<=214) && (event.button.y >=505 && event.button.y<=567))
       {
            //Arrête la musique
           SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
     SDL_BlitSurface(exitbackground, NULL, ecran, &positionexit);
     SDL_Flip(ecran);
       
          compteurecran=2;
                break;
            }
        else if((event.button.x>=24 && event.button.x<=214) &&(event.button.y>=131 && event.button.y<=189))
        {

           Mix_PlayChannel(1, son, 0);
           SDL_BlitSurface(newgametext, NULL, ecran, &positiontext); 
          
           compteurecran=5; 
            
        }
       else if((event.button.x>=27.205 && event.button.x<=204.205) &&(event.button.y>=205 && event.button.y<=256))
       {

           SDL_BlitSurface(continuestext, NULL, ecran, &positiontext); 
           SDL_Flip(ecran); 
       }

       else if((event.button.x>=24 && event.button.x<=210) &&(event.button.y>=279 && event.button.y<=337))
       {
           SDL_BlitSurface(multiplayertext, NULL, ecran, &positiontext); 

           Mix_HaltMusic();
           SDL_Flip(ecran); 

       }    

       else if((event.button.x>=19 && event.button.x<=207) &&(event.button.y>=352 && event.button.y<=405))
       {
             
       compteurecran=3;
          SDL_BlitSurface(optiontext, NULL, ecran, &positiontext); 
           SDL_Flip(ecran); 


       }

   else if ((event.button.x>=25 && event.button.x<=213) &&(event.button.y>=433 && event.button.y<=485))     
       {
          
           
          SDL_BlitSurface(helptext, NULL, ecran, &positiontext); 
           SDL_Flip(ecran); 

       }

  }

break;

}



break;













////////////////////////////evenement sur la map///////////////////////////////////////////////////////////////
















case 1:
    SDL_BlitSurface(Map, NULL, ecran, &positionmap);
    SDL_BlitSurface(echaptext, NULL, ecran, &positionechap); 
           SDL_Flip(ecran);
    SDL_WaitEvent(&event);
    switch(event.type)
       {

            case SDL_QUIT: /* Si c'est un événement QUITTER */

                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */

                break;
            
             case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                   
     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
     SDL_Flip(ecran);
     compteurecran=0;
                    break;
            }

       }

  break;





////////////////////////event du exit background///////////////////////////////////////////////

 












  case 2:
     
SDL_WaitEvent(&event);
    switch(event.type)
       {            
             case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT: /* Appui sur la touche Echap, on arrête le programme */
                   if(droite==1)
                   {
                    SDL_BlitSurface(exitbackground, NULL, ecran, &positionexit);
                     SDL_BlitSurface(yes, NULL, ecran, &pyes);
                    SDL_Flip(ecran); 
                    gauche=1;
                   }
                   else if(droite==2)
                   {
                     SDL_BlitSurface(exitbackground, NULL, ecran, &positionexit);
                    SDL_BlitSurface(no, NULL, ecran, &pno);
                    SDL_Flip(ecran);
                      gauche=0; 
                   }
                   else if(droite>1)
                   {

                    droite=0;
                   }
                     else if(droite==0)
                     {
                        gauche=2;
                     }
                     droite++;
                    break;

             case SDLK_LEFT:
                

                    break;   
            }
          break;


            case SDL_MOUSEMOTION:
            {
                    if ((event.motion.x>=180 && event.motion.x<=327) &&(event.motion.y>=189 && event.motion.y<=318))
                    {
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);	
                    SDL_BlitSurface(exitbackground, NULL, ecran, &positionexit);
                    SDL_BlitSurface(yes, NULL, ecran, &pyes);
                    SDL_Flip(ecran);
                    }

                  else if ((event.motion.x>=450 && event.motion.x<=547.5) &&(event.motion.y>=237 && event.motion.y<=298))
                   {
                   	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                   	SDL_BlitSurface(exitbackground, NULL, ecran, &positionexit);
	                SDL_BlitSurface(no, NULL, ecran, &pno);
                    SDL_Flip(ecran);
                    }
          
            }

         break;

           case SDL_MOUSEBUTTONUP:
              {

            if (event.button.button == SDL_BUTTON_LEFT) /* On arrête le programme si on a fait un clic droit */
             {
       if((event.button.x>=180 && event.button.x<=327) && (event.button.y >=189 && event.button.y<=318))
             {
           
                continuer=0;
                break;
              }
       else   if((event.button.x>=450 && event.button.x<=547.5) && (event.button.y >=237 && event.button.y<=298))
           {

       	    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
       	      compteurecran=0;
          }   
          }

          }





}
break;

///////////////////////////////////////////////////menu_option////////////////////////////////////

case 3:


SDL_BlitSurface(background_option,NULL,ecran,&positionFond);
    SDL_WaitEvent(&event);
    switch(event.type)    
    {



            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    compteurecran =0;
                    break;
                    case SDLK_o:
        vol++;
break;
case SDLK_p:
vol--;

break;

                 
                     case SDLK_i: 

                    if(Mix_PausedMusic() == 1)//Si la musique est en pause

                    {

                        Mix_ResumeMusic(); //Reprendre la musique

                    }

                    else

                    {

                        Mix_PauseMusic(); //Mettre en pause la musique

                    }

                    break;
             }

                break;



}
break;

case 5 :
jouer_stage1(ecran , &compteurecran);
break;




















}
SDL_Flip(ecran);
}   
//// liberer du memoire 
    SDL_FreeSurface(new_game);
    SDL_FreeSurface(exit);
    SDL_FreeSurface(continues);
    SDL_FreeSurface(option);
    SDL_FreeSurface(multi);
    SDL_FreeSurface(help);
    
    //SDL_Quit();


    return EXIT_SUCCESS;

}


//enemy 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

#define W_Screen 800
#define H_Screen 600
#define CMode 32

#define SPEED 5


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6 



#define W_BackgImg 259
#define H_BackgImg 194


struct enemy
{
	SDL_Surface* spriteleft;
	SDL_Surface* spriteright;
        Mix_Music *musique1;
	SDL_Rect frame;
	SDL_Rect dst;
};
typedef struct enemy enemy;
enemy initialisation_enemy(char *image[],char *image1[],char *music1[],int x,int y);
enemy afficher_enemy(SDL_Surface *screen,enemy enemy);



//collision 



#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
SDL_Surface *image ; 
SDL_Rect position ; 

} Objet ; 

void initialiserObj( Objet *obj , char name[] , int x , int y ) ; 
void affichageObj ( Objet obj , SDL_Surface *screen) ; 



#endif /* FONCTIONS_H_ */






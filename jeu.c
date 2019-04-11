//enemy 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"
enemy initialisation_enemy(char *image[],char *image1[],char *music1[],int x,int y)
{
SDL_Surface* screen = NULL;
enemy enemy;
SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
screen = SDL_SetVideoMode(W_Screen, H_Screen, CMode, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE /*| SDL_FULLSCREEN */| SDL_RESIZABLE /*| SDL_NOFRAME*/);
enemy.spriteleft = IMG_Load("image.png");
enemy.spriteright = IMG_Load("image1.png");
enemy.dst.x = 0;
enemy.dst.y = 0;
enemy.musique1=Mix_LoadMUS("music1.mp3");
Mix_PlayMusic(enemy.musique1,-1);

return enemy;
}
enemy afficher_enemy(SDL_Surface *screen,enemy enemy)
{
SDL_Surface* backg = NULL;
backg = IMG_Load("back.png");
SDL_BlitSurface(backg, NULL, screen, NULL);
SDL_Flip(screen);

SDL_ShowCursor(SDL_DISABLE); /*hide cursor*/

	int carryon = 1;
	while(carryon)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}

		switch(event.type)
		{
			case SDL_KEYDOWN:
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	carryon = 0;
			    }
		}

	}
	SDL_Quit();
 return enemy;

}

//collision 
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"

void initialiserObj( Objet *obj , char name[] , int x , int y ) 
{

	       obj->image =  IMG_Load(name); 
	      if  ( obj->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     obj->position.x  =  x ; 
     obj->position.y  =  y ; 
     obj->position.h  =  obj->image->h ;
obj->position.w = obj->image->w ;
}

}



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utility.h"

int collisionbb( SDL_Rect posj , SDL_Rect posobj )
{
 int x ; 
if ( ((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+posj.w>=posobj.x)&&(posj.x<=posobj.x+posobj.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}





#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"
#include "utility.h"

int main()
{
SDL_Surface *screen ; 
Objet Obj, Obj1 ; 
SDL_Event event ; 
int done=0 , x ; 

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255)); 
//initialiser et afficher image
    initialiserObj( &Obj ,"C.png" ,  0 ,  0 ) ; 
    affichageObj (Obj ,screen) ;
    initialiserObj( &Obj1 ,"F.png" ,  500 ,  200 ) ; 
    affichageObj (Obj1 ,screen) ;
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

Obj.position.x-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;

break ; 

case SDLK_RIGHT : 

Obj.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_UP : 

Obj.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_DOWN : 

Obj.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 


                 
			 }
x=collisionbb(Obj.position,Obj1.position) ;

if(x==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }


}
return 0 ; 
}


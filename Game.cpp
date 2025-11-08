 	#include "Game.h"  //searches in current directory used for our own use
#include <stdio.h>  //searches in system directories
//init funtion to initialize sdl/game


Game::Game()
  {
     grunning = false;
    win = nullptr;
    ren = nullptr;
  
  }
  
  Game::~Game()
   {
    clean();
   }
  
  
bool Game::init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen)  //function type= boolean , function belongs to game class , :: scope resolution operatoe says that function belongs to game class

  {
  
  
   int flags=0;
  
     if (fullscreen)
       {
       
        flags=SDL_WINDOW_FULLSCREEN;
       }
        
    if(SDL_Init(SDL_INIT_VIDEO)==0)
      {
      
        //success
        printf("\n sdl initialization successfull");
        
        //if init success then initialize window
        
        win = SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_SHOWN);
        
        //if win creation successful then create renderer
//----------------------------------------------------------------------------------------------------------------------------//        
          if(win!=0) //if window creation sucessful
           {
           ren = SDL_CreateRenderer(win,-1,0);
           
           //if render creation success draw and set color
//------------------------------------------------------------------------------------------------------------//           
             if(ren!=0) //if renderer sucess
               {
                 SDL_SetRenderDrawColor(ren,0,0,0,255); //r,g,b,alpha
                 
                 SDL_Surface* surf = SDL_LoadBMP("assets/scarfy.bmp");   //load func returns surface*
                 smtex=SDL_CreateTextureFromSurface(ren,surf); //create texture form surface
                 SDL_FreeSurface(surf); //free temp surface  freeing used memory
                // SDL_QueryTexture(smtex,NULL,NULL,&srect.w,&srect.h);  // get dimensions of textures we've loaded  to set width and height of source rect
                
                 srect.w=128;  //width of source rect
                 srect.h=128;  //height of dest rect
                 
               //  drect.x=srect.x=5;  //set x cordinate to 0
                // drect.y=srect.y=5;  //set y cordinate to 0  together the cordinates (0,0) top left!
                
                  drect.x=350; //dest rect x cord
                  drect.y=200; //dest rect y cord
                 drect.w=srect.w; //setting width  of dest rect
                 drect.h=srect.h; //setting height  of dest rect 
                 
                }
             else
               {
                printf("\n render failed");
                return false;
               }
             }
//------------------------------------------------------------------------------------------------------------//               
           else
              {
               printf("\n window creation failed");
               return false;
              }
//----------------------------------------------------------------------------------------------------------------------------//             
             } 
      else
        {
          printf("\n initializing failed %s",SDL_GetError());
          return false;
        }
       
     printf("\n initialization sucessful");
     grunning=true;  //init success start main loop 
     
     return true;
   }	
   void Game::render()
     {
     
       SDL_RenderClear(ren);  //clear screen to draw color
       SDL_RenderCopy(ren,smtex,&srect,&drect); // to render texture
       SDL_RenderPresent(ren);  //draw to the screen
     }
     
     
   void Game::clean()
     {
     
       printf("\n cleaning_game");
       SDL_DestroyWindow(win);
       SDL_DestroyRenderer(ren);
       SDL_Quit();
    }
     
       
   void Game::handleevents()
     {
     
      SDL_Event event;
      
      if(SDL_PollEvent (&event))
        {
         switch (event.type)
           {
             case SDL_QUIT:
             
             grunning=false;
             break;
            
             default:
             break;
          }
        }
        
      }
             
                 
 void Game::update()
   {
   
     srect.x=128*int(((SDL_GetTicks()/100)%6)); //getticks() is used to find out no of millisecs since sdl was initialized.then divide this by amount of  time we want btw frames. then use % operator to keep it in the range of frames we want.
   
   }
        
         
              
           
            
                
           
            
        
        
        

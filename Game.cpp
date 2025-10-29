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
  
  
bool Game::init(const char* title,int xpos,int ypos,int width,int height,int flags)  //function type= boolean , function belongs to game class , :: scope resolution operatoe says that function belongs to game class

  {
  
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
                 SDL_SetRenderDrawColor(ren,255,255,255,255); //r,g,b,alpha
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
   
   }
        
         
              
           
            
                
           
            
        
        
        

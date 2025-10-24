#include<Game.h>
#include<stdio.h>
//init funtion to initialize sdl/game

bool Game::init(const char*,int xpos,int ypos,int width,int height,int flags)

  {
  
    if(SDL_INIT_EVERYTHING)==0)
      {
      
        //success
        printf("\n sdl initialization successfull");
        
        //if init success then initialize window
        
        win = SDL_CreateWindow("Game_window",xpos,ypos,with,height,SDL_WINDOW_SHOWN);
        
        //if win creation successful then create renderer
//----------------------------------------------------------------------------------------------------------------------------//        
          if(win!=0)
           {
           ren = SDL_CreateRenderer(win,-1,0);
           
           //if render creation success draw and set color
//------------------------------------------------------------------------------------------------------------//           
             if(ren!=0)
               {
                 SDL_SetRendererDrawColor(ren,255,255,255,255);
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
          printf("\n initializing failed");
          return false;
        }
       
     printf("\n initialization sucessful");
     grunning=true;  //init success start main loop 
     
     return true;
     
   }
     
        
        
         
              
           
            
                
           
            
        
        
        

#include<SDL.h>

//pointer to win

SDL_Window* win = 0;

//pointer to rendere

SDL_Renderer* ren = 0;

//main func

int main(int argc,char* args[])

  {
  
   //initialse sdl 
   
   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
   
     {
     
     //IF initialization success create window
     
    win = SDL_CreateWindow("window_4",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500,SDL_WINDOW_SHOWN);
     
   //if win creation sucess then create renderer
   
   if(win !=0)
   {
     ren = SDL_CreateRenderer(win,-1,0);
   }
  }
  
  else
  {
   return 1;  //init failed
   
  }
  
  //if render sucess then color it
  
  SDL_SetRenderDrawColor(ren,1,0,1,255);
  
  //clear color to black
  
  SDL_RenderClear(ren);
  
  //show winow
  
  SDL_RenderPresent(ren);
  
  //delay
  
  SDL_Delay(1000);
  
  
  //sdl quit
  
  SDL_Quit();
  
  return 0;
}
     
     

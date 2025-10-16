#include<SDL.h>

SDL_Window * win =0;
SDL_Renderer * ren =0;

int main(int argc , char* args[])
 
  {
    //initialize sdl 
    
   if((SDL_INIT_EVERYTHING) >= 0)
   
     {
      
       //if success create window
       
       win = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500,SDL_WINDOW_SHOWN);   //function to create window
    
    }
    
       
      if(win !=0)
        {
        // if window creation sucess then create renderer
        
       ren = SDL_CreateRenderer(win,-1,0);   //create a renderer for the window 
       
       }
       
       else
         {
           return 1; //sdl initialization failed 
         } 
           
       //if renderer created sucessfuly then draw color(clear to black)
       
       SDL_SetRenderDrawColor(ren,0,0,0,255);  //SET COLOR USING R,G,B,ALPHA
       
       
       //clear the window 
       
       SDL_RenderClear(ren);  //clear window to specified color
      
      //show the window
       
       SDL_RenderPresent(ren);   //show the window 
       
      
      //set delay to show window for sometime
      
      SDL_Delay(600000000);      //show for 5 sec
      
      //quit cleanup
      
     // SDL_Quit();
      
      return 0;
      
    }
      

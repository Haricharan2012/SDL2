#include<SDL.h>
#include<stdbool.h>
void render();
bool init(const char* title,int xpos,int ypos,int height,int width,int flags);


SDL_Window* win =0;
SDL_Renderer* ren =0;

bool grunning = false;  //needed for looping

     
 bool init(const char* title,int xpos,int ypos,int width,int height,int flags)
    
      {
      
       if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
       
       {
      
        // if sucess create window
      
         win=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
       
       
         
         //if window creation sucess then create renderer
         if(win!=0)
           {
              ren=SDL_CreateRenderer(win,-1,0);
              
           }
         }
         
           
          else
            {
              return false;
            }
         
        return true;
        
     }
     
     
     
  void render()
      
    {
    
    //set to black
    
    SDL_SetRenderDrawColor(ren,1,0,1,255); //set to black
    
  //clear to that color
  
    SDL_RenderClear(ren);
    
   //show window
   
   SDL_RenderPresent(ren);
   
    //delay
   
   // SDL_Delay(5000);
   
  }
    
    
 int main(int argc ,char* argv[])

  {
  
    //function call within if
    
    
    
    if(init("Modwin",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,400,SDL_WINDOW_SHOWN))
 
        {
        
           grunning = true;  //game running is true
           
         }
         
     else
        {
         return 1;  //failed init
         
        }
        
      while(grunning)  //while game is running
        {
        
         render();  //call render function whn game is running
         
        }
          
      //clean up sdl
      
      SDL_Quit();
      
      return 0;
      
     }
      
       
         
    
    

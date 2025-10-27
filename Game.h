#ifndef _Game_
#define _Game_
#include "SDL.h"

class Game
  {

    public:
     
            Game();  //constructor
           ~Game();  //destructor
           
           bool init(const char* title,int xpos,int ypos,int width,int height,int flags); //  void init();  //initialize sdl
           void render();  //draw game
           void update();  //update game based on user events
           void handleevents(); //handle the user events mouseclick,keypress etc..
           void clean();  //clean garbage after execution success
           
           
           bool running()   //function to access private variable
           
           {
           
            return grunning;  
            
           }
           
           
       private:
        
         SDL_Window* win;  //window object
         SDL_Renderer* ren;  //renderer object 
         bool grunning;  //game running var
    
    
  };

#endif /* defined(__Game__) */

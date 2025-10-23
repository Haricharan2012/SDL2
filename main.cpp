#include<stdio.h>

void init();
void render();
void update();
void handle_events();
void clean();

bool running = true;  

int main()
  {
  
   //initialize sdl
   
   void init();
   
   while(running)
   
   {
   
   //while game is running do these
     handle_events();  //handle events from user
     render();  //render graphics onto screen
     update(); //update based on events 
    }
    
   //clear everything
   
   clean();
   
  }
  
  void init()
   {
   
    //initialize everything(SDL)
    printf("\n initializing 100 percent ");
   
   }
   
  void render()
   {
     //render graphics
     printf("\n render start");
   }
   
  void update()
   {
    
    //update based on events
    printf("\n updating initiated");
   
   }
   
  void handle_events()
   {
     //handle user events 
    printf("\n handling events");
     
   }
   
  void clean()
  {
  
   //to clean after quit
   printf("\n clearing garbage");
   
  }

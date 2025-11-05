#include "Game.h"

//game obj

Game* gameobj=0;  //global pointer to a game object '0'-null pointer 

//main func

  int main(int argc,char* argv[])
     {
       gameobj=new Game(); //new keyword allocates memory and calls constructor ,pointer gameobj now points to new gameobject
       
       gameobj->init("gamewin",100,100,800,500,true);  //call function along with passing arguments
       
      while(gameobj->running())
        {
          gameobj->handleevents();
          gameobj->update();
          gameobj->render();
        }
        
       gameobj->clean();  //when game stops(loop exit) then clean unwanted data
       
      return 0;
      
    }
       
       
   //-> arrow operator - is used when we are accessing a class or a struct member through  a pointer 

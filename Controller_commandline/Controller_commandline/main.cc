//
//  main.cpp
//  Controller_commandline
//
//  Created by David Karlsson on 04/03/15.
//  Copyright (c) 2015 David Karlsson. All rights reserved.
//

#include <iostream>
//#include <sys/types.h>
//#include <signal.h>
//#include <sys/types.h>
//#include <signal.h>
#include <unistd.h>
#include <assert.h>

pid_t playerPid;
int pipedes[2], status;
bool hasPlayer = false;
void initAL();


int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Parent program started!\n";
  initAL();
  for(;;){
    std::cout << "parent waiting for message: ";
    std::string msg;
    std::getline(std::cin,msg);
    if (strlen(msg.c_str()) > 0) {
      std::cout << "writing message to pipe";
      write(pipedes[1], msg.c_str(), strlen(msg.c_str())); //Writes line to the pipe.
    }
    //send string: "play to child"
  }
  
  
  return 0;
}


void initAL(){
  
  //This needs to be executed only once, messages are aarriving
  if (!hasPlayer) {
    hasPlayer = true;
    wprintf(L"Added a fork");
    //fork(),exec() create pipes.
    
    //Fire up a command line application that plays open al as a separate process:
    signal(SIGCHLD, SIG_IGN);
    
    assert (pipe(pipedes) == 0);
    playerPid=fork();
    if (playerPid == 0) {
      // child process //
      
      close (pipedes[1]); /* Close writing end */
      dup2(pipedes[0], STDIN_FILENO); /* Make stdin the same as the pipe read fd */
      
      static char *argv[]={(char*)" ",NULL};//(char*)"echo",(char*)"Foo is my name.",NULL};
      //execv("/bin/ps",argv);
      execv("/Users/daka/Library/Developer/Xcode/DerivedData/openAL_commandline-hayyerhevkpwrbdkkkhalkxbvquk/Build/Products/Debug/openAL_commandline",argv);
      exit(127); // only if execv fails
      
    }
    else { // pid!=0; parent process
      


      //waitpid(pid,0,0); wait for child to exit
    }
    
  }
}